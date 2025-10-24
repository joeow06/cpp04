/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:40:06 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 00:50:33 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "---------- Default Tests ----------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Animal type is: " << j->getType() << std::endl;
	std::cout << "Animal type is: " << i->getType() << std::endl;
	std::cout << "Animal type is: " << meta->getType() << std::endl;	
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	
	std::cout << "\n---------- Copy Constructor Tests ----------" << std::endl;
	Dog stackDog;
	Dog newStackDog(stackDog);
	std::cout << "Animal type is: " << stackDog.getType() << std::endl;
	std::cout << "Animal type is: " << newStackDog.getType() << std::endl;
	
	std::cout << "\n---------- Copy Assignment Operator Tests ----------" << std::endl;
	Dog kiki;
	Dog newKiki = kiki;
	std::cout << "Animal type is: " << kiki.getType() << std::endl;
	std::cout << "Animal type is: " << newKiki.getType() << std::endl;

    std::cout << "\n---------- WrongAnimal Tests ----------" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "WrongAnimal type is: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat type is: " << wrongCat->getType() << std::endl;
    wrongMeta->makeSound();
    wrongCat->makeSound();
    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n---------- Stack Allocation and Scope ----------" << std::endl;
    {
        Cat stackCat;
        stackCat.makeSound();
        std::cout << "Stack Cat type: " << stackCat.getType() << std::endl;
    } // Destructor for stackCat called here

    std::cout << "\n---------- Array of Animals (Polymorphism) ----------" << std::endl;
    const int N = 4;
    Animal* animals[N];
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < N; ++i) {
        std::cout << animals[i]->getType();
        animals[i]->makeSound();
    }
    for (int i = 0; i < N; ++i) {
        delete animals[i];
    }
	std::cout << std::endl;
	return 0;
}