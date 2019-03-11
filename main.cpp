#include "core/print_ip.h"


/// @brief  Main function. Prints IP addresses in multiple formats
/// @author Oleg Potkin <olpotkin@gmail.com>
int main() {
  print_ip(char(-1));
  std::cout << std::endl;

  print_ip(short(0));
  std::cout << std::endl;

  print_ip(int(2130706433));
  std::cout << std::endl;

  print_ip(long(8875824491850138409));
  std::cout << std::endl;

  print_ip(std::string("192.168.1.1"));
  std::cout << std::endl;

  print_ip(std::vector<std::string>{"192", "168", "1", "1"});
  std::cout << std::endl;

  return 0;
}
