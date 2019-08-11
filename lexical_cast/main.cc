#include <boost/lexical_cast.hpp>
#include <cstdlib>

using boost::lexical_cast;
using std::string;

int main(int argc, char* argv[]) {
  int x = 5;
  string s = lexical_cast<string>(x);
  assert(s == "5");

  return EXIT_SUCCESS;
}
