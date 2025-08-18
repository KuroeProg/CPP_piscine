/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:32:59 by cfiachet          #+#    #+#             */
/*   Updated: 2025/08/18 11:46:03 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _nbr;
		static const int fractionnalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copie);
		Fixed &operator=(const Fixed &copie);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif