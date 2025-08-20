/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:32:59 by cfiachet          #+#    #+#             */
/*   Updated: 2025/08/20 16:48:42 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _nbr;
		static const int fractionnalBits = 8;
		static Fixed fromRaw(int raw);

	public:
		Fixed();
		Fixed(const int n);
		Fixed (const float f);
		Fixed(const Fixed &copie);
		Fixed &operator=(const Fixed &copie);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int 	toInt(void) const;
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++();   
	Fixed operator++(int); 
	Fixed &operator--();   
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); //thx gpt



#endif