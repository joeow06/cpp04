/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:54:00 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 14:43:21 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain)
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog woofs..." << std::endl;
}

Brain* Dog::getBrain() const
{
	return (brain);
}