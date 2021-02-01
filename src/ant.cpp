#include <iostream>

#include "counters/brute_counter.h"

using namespace std;
using namespace counters;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    cout << "Invalid arguments. Type \"ant <init_x> <init_y> <deepness>\""
         << endl;
    return EXIT_FAILURE;
  }

  cout << brute_force(std::stoi(argv[1]), std::stoi(argv[2]),
                      std::stoi(argv[3]))
       << endl;

  return EXIT_SUCCESS;
}
