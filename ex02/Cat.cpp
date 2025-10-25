/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:54:00 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 14:43:43 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain)
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat meows..." << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}