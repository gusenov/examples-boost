#include <iostream>
#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

void example() {
  // Запись JSON:
  ptree pt;
  pt.put("foo", "bar");
  std::ostringstream buf;
  write_json(buf, pt, false);
  std::string json = buf.str();  // {"foo":"bar"}  плюс перевод строки
  std::cout << json;

  // Чтение JSON:
  ptree pt2;
  std::istringstream is(json);
  read_json(is, pt2);
  std::string foo = pt2.get<std::string>("foo");  // bar
  std::cout << foo << std::endl;
}

std::string map2json(const std::map<std::string, std::string>& map) {
  ptree pt;
  for (auto& entry: map)
    pt.put (entry.first, entry.second);
  std::ostringstream buf;
  write_json (buf, pt, false);
  return buf.str();
}

int main(int argc, char* argv[]) {
  example();

  std::map<std::string, std::string> m;
  m["key1"] = "val1";
  m.insert(std::pair<std::string, std::string>("key2", "val2"));
  m.insert({"key3", "val3"});  // C++11
  std::cout << map2json(m);
  // {"key1":"val1","key2":"val2","key3":"val3"}  плюс перевод строки

  return 0;
}
