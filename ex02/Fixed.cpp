#include "Fixed.hpp"

/*				Constructors and destructor			*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	_value = num * (1 << Fixed::_fractionalBits);
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)roundf(num * (1 << Fixed::_fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*				Assignment operator			*/

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
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

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

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
