#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "Info.hpp"

int main(int argc, char** argv) {
  std::vector<Info> infs;

  Info info1, info2;
  info1.AddFilename("ThisFile.txt");
  info2.AddFilename("ThatFile.txt");
  info2.AddFilename("OtherFile.txt");

  info2.AddFilename("ABC");
  info2.AddFilename("123");
  info2.AddFilename("XYZ");

  infs.push_back(info1);
  infs.push_back(info2);

  // Сохранить данные об именах файлов содержащиеся в объекте класса Info:
  {
    // Создать выходной архив:
    std::ofstream ofs("store.dat");
    boost::archive::text_oarchive ar(ofs);

    // Сохранить данные:
    ar & infs;
  }

  // Восставление из сохраненных данных:
  std::vector<Info> restored_info;
  {
      // Создать входной архив:
      std::ifstream ifs("store.dat");
      boost::archive::text_iarchive ar(ifs);

      // Загрузить данные:
      ar & restored_info;
  }

  // Печать для верификации контента:
  std::vector<Info>::const_iterator it = restored_info.begin();
  for (; it != restored_info.end(); ++it) {
    Info info = *it;
    info.Print();
  }

  return 0;
}
