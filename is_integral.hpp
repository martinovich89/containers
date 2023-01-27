#pragma once

namespace ft
{
	struct true_type {};
	struct false_type {};

	template <class T>
	struct is_integral : false_type { };
	template <>
	struct is_integral <signed char> : true_type { };
	template <>
	struct is_integral <unsigned char> : true_type { };
	template <>
	struct is_integral <signed short> : true_type { };
	template <>
	struct is_integral <unsigned short> : true_type { };
	template <>
	struct is_integral <signed int> : true_type { };
	template <>
	struct is_integral <unsigned int> : true_type { };
	template <>
	struct is_integral <signed long> : true_type { };
	template <>
	struct is_integral <unsigned long> : true_type { };
	template <>
	struct is_integral <signed long long> : true_type { };
	template <>
	struct is_integral <unsigned long long> : true_type { };
	template <class T>
	struct is_integral <const T> : is_integral<T> { };
	template <class T>
	struct is_integral <volatile T> : is_integral<T> { };
	template <class T>
	struct is_integral <const volatile T> : is_integral<T> { };
}