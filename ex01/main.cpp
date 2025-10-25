/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:40:06 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 14:09:23 by jow              ###   ########.fr       */
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
	deep.getBrain()->setIdeas("Im a dog and i love barking!");
	Dog deepdeep = deep;
	std::cout << "Deep's idea is " << deep.getBrain()->getIdeas() << std::endl;
	std::cout << "Deepdeep's idea is " << deepdeep.getBrain()->getIdeas() << std::endl;
	std::cout << "Memory address for deep's brain is: " << deep.getBrain() << std::endl;
	std::cout << "Memory address for deepdeep's brain is: " << deepdeep.getBrain() << std::endl;

	std::cout << "\n---------- Testing Cat Deep Copies ----------" << std::endl;
	Cat meow;
	meow.getBrain()->setIdeas("Im a cat and i love meowing!");
	Cat deepMeow= meow;
	std::cout << "meow's idea is " << meow.getBrain()->getIdeas() << std::endl;
	std::cout << "deepMeow's idea is " << deepMeow.getBrain()->getIdeas() << std::endl;
	std::cout << "Memory address for deep's brain is: " << meow.getBrain() << std::endl;
	std::cout << "Memory address for deepdeep's brain is: " << deepMeow.getBrain() << std::endl;  
	
	std::cout << std::endl;
	return 0;   
}