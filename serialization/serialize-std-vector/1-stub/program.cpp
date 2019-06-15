#include <fstream>
#include "Info.hpp"

int main(int argc, char** argv) {
  Info info;
  info.AddFilename("ThisFile.txt");
  info.AddFilename("ThatFile.txt");
  info.AddFilename("OtherFile.txt");

  {
    std::ofstream ofs("store.dat");
  }

  Info restored_info;
  {
    std::ifstream ifs("store.dat");
  }

  // Печать для верификации контента:
  restored_info.Print();

  return 0;
}
