#include <iostream>
#include <fstream>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include "date.hpp"
#include "serialize-method.hpp"

void save() {
  std::ofstream file("archive.xml");
  boost::archive::xml_oarchive oa(file);
  date d(15, 8, 1947);
  oa & BOOST_SERIALIZATION_NVP(d);
}

void load() {
  std::ifstream file("archive.xml");
  boost::archive::xml_iarchive ia(file);
  date dr;
  ia >> BOOST_SERIALIZATION_NVP(dr);
  std::cout << dr;
}

int main(int argc, char** argv) {
  save();
  load();
  return 0;
}
