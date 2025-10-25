/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:40:06 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 14:54:51 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;
	AAnimal *animals[8];
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
	Cat deepMeow = meow;
	std::cout << "meow's idea is " << meow.getBrain()->getIdeas() << std::endl;
	std::cout << "deepMeow's idea is " << deepMeow.getBrain()->getIdeas() << std::endl;
	std::cout << "Memory address for deep's brain is: " << meow.getBrain() << std::endl;
	std::cout << "Memory address for deepdeep's brain is: " << deepMeow.getBrain() << std::endl;

	std::cout << std::endl;
	return 0;
}

/*
* Abstract classes:
*  1. Have at least one pure virtual function
*  2. Cannot make an instance of an abstract class
*		e.g. Shape imAShape; <-- this wont work
*  3. Have to use pointers to abstract class
*		e.g. Shape *imAShape; <-- this works
*
* Pure virtual function:
*  1. virtual void draw() = 0; declares a pure virtual function,
		forcing derived classes to provide their own implementation.
*
* Concrete classes:
*   1. Inherits from abstract classes and overwrites the pure virtual function
*	2. On the other hand, the purpose of Concrete class is that is acts as "Final" and 
*		optionally single class, and thus does not need to provide virtual destructor.
*	3. Anyone who would attempt to derive from concrete class is potentially summoning demons to it's code, 
		because concrete classes are not used for this.
* 	4. Concrete classes do not share it's implementation with derived classes by default, meaning it's implementation is "final" 
		and here in that class, representation and definition are in one class, part of each other, not overriden not shared.
*/