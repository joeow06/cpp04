/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:37:34 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 22:55:23 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") 
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	// *this = other;
	// std::cout << "Ice copy constructor called" << std::endl;
	(void) other;
}

Ice& Ice::operator=(const Ice &other)
{
	// this->_type = other._type;
	// std::cout << "Ice assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	(void) target;
}