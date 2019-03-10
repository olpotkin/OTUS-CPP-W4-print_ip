#include "core/print_ip.h"


/// @brief  Main function. Prints IP addresses in multiple formats
/// @author olpotkin@gmail.com
int main() {
  std::cout << "Integral: char" << std::endl;
  print_ip(char(-1));
  std::cout << "---" << std::endl;

  std::cout << "Integral: short" << std::endl;
  print_ip(short(0));
  std::cout << "---" << std::endl;

  std::cout << "Integral: int" << std::endl;
  print_ip(int(2130706433));
  std::cout << "---" << std::endl;

  std::cout << "Integral: long" << std::endl;
  print_ip(long(8875824491850138409));
  std::cout << "---" << std::endl;
  return 0;
}
