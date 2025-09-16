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
	int		getRawBits() const ;
	void	setRawBits(int const raw);
	float	toFloat() const ;
	int		toInt() const ;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);

#endif