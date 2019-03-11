#pragma once

#include <iostream>
#include <string>

/// References:
/// - https://en.cppreference.com/w/cpp/types/enable_if
/// - https://www.daniweb.com/programming/software-development/threads/200708/how-to-convert-uint32-to-ip-address-dot-format
/// - http://www.cplusplus.com/reference/type_traits/is_integral/
/// - http://www.cplusplus.com/reference/type_traits/integral_constant/
/// Helper types
/// template< bool B, class T = void >
/// using enable_if_t = typename enable_if<B,T>::type;


/// @brief  Prints IP represented as integral type
/// @tparam T - integral type (bool, char, short, uint, int, long, etc...)
/// @param  ip - IP address
/// @author Oleg Potkin <olpotkin@gmail.com>
template <typename T>
typename std::enable_if_t<std::is_integral<T>::value> print_ip(const T& ip) {
  for (size_t sz = sizeof(T); sz != 0; --sz) {
    std::cout << ((ip >> (8 * (sz - 1))) & 0xff)
      << (sz != 1 ? "." : "");
  }
}


template <typename T>
struct is_string : std::false_type {};

template <>
struct is_string<std::string> : std::true_type {};

/// @brief  Prints IP represented as std::string type
/// @tparam T - std::string type
/// @param  ip - IP address
/// @author Oleg Potkin <olpotkin@gmail.com>
template <typename T>
typename std::enable_if<is_string<T>::value>::type print_ip(const T& ip) {
  std::cout << ip;
}
