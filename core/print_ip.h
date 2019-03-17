#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <type_traits>


/// @file

/// References:
/// - https://en.cppreference.com/w/cpp/types/enable_if
/// - https://www.daniweb.com/programming/software-development/threads/200708/how-to-convert-uint32-to-ip-address-dot-format
/// - http://www.cplusplus.com/reference/type_traits/is_integral/
/// Note: std::is_untegral_v<T> available since C++17
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


template <typename T>
struct is_lis_vec : std::false_type {};

template <typename... Args>
struct is_lis_vec<std::vector<Args ...> > : std::true_type {};

template <typename... Args>
struct is_lis_vec<std::list<Args ...> > : std::true_type {};

/// @brief  Prints IP represented as std::vector or std::list
/// @tparam T - std::vector / std::list type
/// @param  ip - IP address
/// @author Oleg Potkin <olpotkin@gmail.com>
template <typename T>
std::enable_if_t<is_lis_vec<T>::value> print_ip(const T& ip) {
  // Iterate through the vector
  for (const auto& it : ip) {
    std::cout << it;
    std::cout << (&it != &ip.back() ? "." : "");
  }
}


/// @brief
/// Check if arguments have the same type
/// Reference: https://stackoverflow.com/questions/37236109/how-to-check-the-type-of-passed-arguments-to-variadic-function
template <typename T, typename... Args>
struct all_same_args_t;
template <typename T>
struct all_same_args_t<T> : public std::true_type {};
template <typename T, typename U, typename...Args>
struct all_same_args_t<T, U, Args...> : public std::false_type {};
template <typename T, typename...Args>
struct all_same_args_t<T, T, Args...> : public all_same_args_t<T, Args...> {};

/// @brief
/// Helper to print tuple elements divided by "."
/// Note: Dot "." after last octet shouldn't be printed
template<typename T, size_t arg_pos, size_t last_dot_pos>
struct format_tuple {
  static void print_tuple_arg(const T& value) {
    std::cout << std::get<arg_pos>(value) << ".";
    format_tuple<T, arg_pos + 1, last_dot_pos>::print_tuple_arg(value);
  }
};
template<typename Type, size_t arg_pos>
struct format_tuple<Type, arg_pos, arg_pos> {
  static void print_tuple_arg(const Type& value) {
    std::cout << std::get<arg_pos>(value);
  }
};

/// @brief  Prints IP represented as std::tuple where all arguments have same type
/// @tparam T - std::tuple
/// @param  ip - IP address
/// @author Oleg Potkin <olpotkin@gmail.com>
template <typename... Args>
typename std::enable_if<all_same_args_t<Args...>::value>::type print_ip(const std::tuple<Args...>& ip) {
  constexpr int num_args_tuple = std::tuple_size<std::tuple<Args...>>::value;
  format_tuple<std::tuple<Args...>, 0, num_args_tuple - 1>::print_tuple_arg(ip);
}
