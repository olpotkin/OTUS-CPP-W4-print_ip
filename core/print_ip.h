#pragma once

#include <iostream>


/// @brief  Prints IP represented in integral type
/// References:
/// - https://en.cppreference.com/w/cpp/types/enable_if
/// - https://www.daniweb.com/programming/software-development/threads/200708/how-to-convert-uint32-to-ip-address-dot-format
/// @tparam T - integral type (bool, char, short, uint, int, long, etc...)
/// @param  ip - IP address
/// @author olpotkin@gmail.com
template <typename T>
typename std::enable_if<std::is_integral<T>::value> print_ip(const T& ip) {
  for (size_t sz = sizeof(T); sz != 0; --sz) {
    std::cout << ((ip >> (8 * (sz - 1))) & 0xff)
      << (sz != 1 ? "." : "");
  }
  std::cout << std::endl;
}
