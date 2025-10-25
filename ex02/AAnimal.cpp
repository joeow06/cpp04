/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:44:33 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 01:18:33 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unknown")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "AAnimal assignment operator called" << std::endl;
	return (*this);
}

AAnimal::AAnimal(std::string _type) : type(_type)
{
	std::cout << "AAnimal parametized constructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}

void AAnimal::makeSound() const
{
	std::cout << "Unknown has no sound..." << std::endl;
}