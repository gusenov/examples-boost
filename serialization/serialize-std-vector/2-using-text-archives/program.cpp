#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "Info.hpp"

int main(int argc, char** argv) {
  Info info;
  info.AddFilename("ThisFile.txt");
  info.AddFilename("ThatFile.txt");
  info.AddFilename("OtherFile.txt");

  // Сохранить данные об именах файлов содержащиеся в объекте класса Info:
  {
    // Создать выходной архив:
    std::ofstream ofs("store.dat");
    boost::archive::text_oarchive ar(ofs);

    // Сохранить данные:
    ar & info;
  }

  // Восставление из сохраненных данных:
  Info restored_info;
  {
    // Создать входной архив:
    std::ifstream ifs("store.dat");
    boost::archive::text_iarchive ar(ifs);

    // Загрузить данные:
    ar & restored_info;
  }

  // Печать для верификации контента:
  restored_info.Print();

  return 0;
}
