/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:40:06 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 01:52:06 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
	Animal *animals[8];
	for (int i = 0; i < 4; i++)
	    animals[i] = new Dog();
	for (int i = 4; i < 8; i++)
	    animals[i] = new Cat();
	for (int i = 0; i < 8; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 8; i++)
        delete animals[i];

	std::cout << "\n---------- Testing Dog Deep Copies ----------" << std::endl;
	Dog deep;
	Dog deepdeep = deep;
	std::cout << "Memory address for deep's brain is: " << deep.getBrain() << std::endl;
	std::cout << "Memory address for deepdeep's brain is: " << deepdeep.getBrain() << std::endl; 
	
	std::cout << "\n---------- Testing Cat Deep Copies ----------" << std::endl;
	Cat meow;
	Cat deepMeow= meow;
	std::cout << "Memory address for deep's brain is: " << meow.getBrain() << std::endl;
	std::cout << "Memory address for deepdeep's brain is: " << deepMeow.getBrain() << std::endl;  
	
	std::cout << std::endl;
	return 0;   
}