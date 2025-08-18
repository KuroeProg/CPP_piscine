#include "Fixed.hpp"

Fixed::Fixed() {
	this->_nbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copie) {
	std::cout << "Copy constructor called" << std::endl;
	this->_nbr = copie.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copie) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copie)
		this->_nbr = copie.getRawBits();
	return *this;
}


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _nbr;
}

void	Fixed::setRawBits(int const raw) {
	this->_nbr = raw;
}