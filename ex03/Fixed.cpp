#include "Fixed.hpp"

/*				Constructors and destructor			*/

Fixed::Fixed() { _value = 0; }

Fixed::Fixed(int const num)
{
	_value = num * (1 << Fixed::_fractionalBits);
}

Fixed::Fixed(float const num)
{
	_value = (int)roundf(num * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other) { *this = other; }

/*				Assignment operator			*/

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (&other != this)
		_value = other.getRawBits();
	return (*this);
}

/*				Comparision operators			*/

bool	Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}

/*				Arithmetic operators			*/

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_value + other._value);
	
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;
	result.setRawBits(_value - other._value);

	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;
	
	long long	product = (long long)_value * (long long)other._value;
	result.setRawBits((int)(product >> Fixed::_fractionalBits));

	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	long long	numerator = ((long long)_value << Fixed::_fractionalBits);
	result.setRawBits((int)(numerator / other._value));

	return (result);
}

/*				Increment/Decrement			*/

Fixed	&Fixed::operator++()
{
	_value += 1;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	_value -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	_value += 1;

	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	_value -= 1;

	return (temp);
}

/*				Member functions			*/

int	Fixed::getRawBits() const { return (_value); }

void	Fixed::setRawBits(int const raw) { _value = raw; }

float	Fixed::toFloat() const
{
	return (_value / (float)(1 << Fixed::_fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (_value / (1 << Fixed::_fractionalBits));
}

/*				Static member functions			*/

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	return ((first < second) ? first : second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	return ((first < second) ? first : second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	return ((first > second) ? first : second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	return ((first > second) ? first : second);
}

/*				Output operator overload			*/

std::ostream	&operator<<(std::ostream &stream, const Fixed &obj)
{
	stream << obj.toFloat();
	return (stream);
}
