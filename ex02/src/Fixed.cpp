/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:37:07 by mleonard          #+#    #+#             */
/*   Updated: 2024/06/04 19:01:16 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(int value)
{
    this->value = value << fractionalBits;
}

Fixed::Fixed(float value)
{
    this->value = (int)roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &other)
{
    this->value = other.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed &Fixed::operator+(Fixed const &other)
{
    float newValue = this->toFloat() + other.toFloat();
    return *(new Fixed(newValue));
}

Fixed &Fixed::operator-(Fixed const &other)
{
    float newValue = this->toFloat() - other.toFloat();
    return *(new Fixed(newValue));
}

Fixed &Fixed::operator*(Fixed const &other)
{
    float newValue = this->toFloat() * other.toFloat();
    return *(new Fixed(newValue));
}

Fixed &Fixed::operator/(Fixed const &other)
{
    float newValue = this->toFloat() / other.toFloat();
    return *(new Fixed(newValue));
}

Fixed &Fixed::operator++()
{
    ++value;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--()
{
    --value;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

int Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return roundf(this->toFloat());
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
