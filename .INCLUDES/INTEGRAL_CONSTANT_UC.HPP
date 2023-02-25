/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:31:57 by crochu            #+#    #+#             */
/*   Updated: 2022/02/15 15:48:09 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <
		class T,
		T v
	> struct integral_constant {
		typedef T							value_type;
		typedef integral_constant< T, v >	type;

		operator value_type(void) const { return value; }

		static const T	value = v;
	};

	typedef integral_constant< bool, false >	false_type;
	typedef integral_constant< bool, true >		true_type;
}
