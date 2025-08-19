#include "Fixed.hpp"

Fixed::Fixed() {
	this->_nbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copie) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = n << fractionnalBits;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf(f * (1 << fractionnalBits));
}

Fixed &Fixed::operator=(const Fixed &copie) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copie)
		this->_nbr = copie._nbr;
	return *this;
}


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// int		Fixed::getRawBits(void) const {
// 	return _nbr;
// }

void	Fixed::setRawBits(int const raw) {
	this->_nbr = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_nbr / (1 << fractionnalBits);
}

int		Fixed::toInt(void) const {
	return _nbr >> fractionnalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}