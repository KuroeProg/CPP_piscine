#include "Fixed.hpp"

Fixed::Fixed() {
	this->_nbr = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copie) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = copie;
}

Fixed::Fixed(int const n) {
	// std::cout << "Int constructor called" << std::endl;
	this->_nbr = n << fractionnalBits;
}

Fixed::Fixed(float const f) {
	// std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf(f * (1 << fractionnalBits));
}

Fixed &Fixed::operator=(const Fixed &copie) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copie)
		this->_nbr = copie._nbr;
	return *this;
}


Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
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

bool Fixed::operator>(const Fixed &other) const {
	return this->_nbr > other._nbr; 
}

bool Fixed::operator<(const Fixed &other) const {
	return this->_nbr < other._nbr;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_nbr >= other._nbr;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_nbr <= other._nbr;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_nbr == other._nbr;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_nbr != other._nbr;
}

// Fixed.cpp
Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed::fromRaw(this->_nbr + other._nbr);
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed::fromRaw(this->_nbr - other._nbr);
}

Fixed Fixed::operator*(const Fixed &other) const {
	long tmp = (long)this->_nbr * (long)other._nbr;
	return Fixed::fromRaw(tmp >> fractionnalBits);
}

Fixed Fixed::operator/(const Fixed &other) const {
	long tmp = ((long)this->_nbr << fractionnalBits) / other._nbr;
	return Fixed::fromRaw(tmp);
}

Fixed &Fixed::operator++() { // pré
	this->_nbr++;
	return *this;
}

Fixed Fixed::operator++(int) { // post
	Fixed tmp(*this);
	this->_nbr++;
	return tmp;
}

Fixed &Fixed::operator--() { // pré
	this->_nbr--;
	return *this;
}

Fixed Fixed::operator--(int) { // post
	Fixed tmp(*this);
	this->_nbr--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

Fixed Fixed::fromRaw(int raw) {
	Fixed f;
	f._nbr = raw;
	return f;
}
