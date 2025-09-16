#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
private:
	int					_value;
	static int const	_fractionalBits = 8;
public:
	Fixed();
	Fixed(int const num);
	Fixed(float const num);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed	&operator=(const Fixed &other);

	bool	operator>(const Fixed &other) const ;
	bool	operator<(const Fixed &other) const ;
	bool	operator>=(const Fixed &other) const ;
	bool	operator<=(const Fixed &other) const ;
	bool	operator==(const Fixed &other) const ;
	bool	operator!=(const Fixed &other) const ;

	Fixed	operator+(const Fixed &other) const ;
	Fixed	operator-(const Fixed &other) const ;
	Fixed	operator*(const Fixed &other) const ;
	Fixed	operator/(const Fixed &other) const ;

	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	int		getRawBits() const ;
	void	setRawBits(int const raw);
	float	toFloat() const ;
	int		toInt() const ;

	static Fixed		&min(Fixed &first, Fixed &second);
	static const Fixed	&min(const Fixed &first, const Fixed &second);
	static Fixed		&max(Fixed &first, Fixed &second);
	static const Fixed	&max(const Fixed &first, const Fixed &second);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);

#endif