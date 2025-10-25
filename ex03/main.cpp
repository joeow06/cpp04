/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:07 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 02:21:33 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	ICharacter* me = new Character("me");
	
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
	
// 	return 0;
// }

int main()
{
	std::cout << "---------- Materia Source test----------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); //5th time will fail
	std::cout << std::endl;
	
	std::cout << "---------- Build \"me\" character ----------" << std::endl;
	ICharacter* me = new Character("me");
	std::cout << std::endl;
	
	std::cout << "---------- \"me\" equips materia ----------" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("fire"); // unknown magic!
	if (!tmp) // createMateria returns 0 if fail
		std::cout << "Unknown Magic Detected!" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure"); //5th materia will fail
	me->equip(tmp);
	me->equip(NULL);
	delete tmp; // Delete materia that wasnt equipped to avoid mem leak
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	
	std::cout << "---------- \"me\" use test ----------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(42, *bob); 		//invalid
	me->use(-123123, *bob); //invalid
	me->use(4, *bob);		//invalid
	std::cout << std::endl;

	std::cout << "---------- \"me\" unequip test ----------" << std::endl;
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	me->unequip(-1);
	me->unequip(4242);
	std::cout << std::endl;

	std::cout << "---------- \"me\" use after unequip test ----------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << std::endl;

	std::cout << "---------- \"me\" equip again test ----------" << std::endl;
	AMateria* newTmp;
	newTmp = src->createMateria("ice");
	me->equip(newTmp);
	newTmp = src->createMateria("cure");
	me->equip(newTmp);
	me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
	std::cout << std::endl;

	std::cout << "---------- character deep copy test ----------" << std::endl;
    ICharacter* alice = new Character("alice");
    tmp = src->createMateria("ice");
    alice->equip(tmp);
    tmp = src->createMateria("cure");
    alice->equip(tmp);
    
    Character* aliceCopy = new Character(*(Character*)alice);
    std::cout << "Original alice uses materia:" << std::endl;
    alice->use(0, *bob);
    alice->use(1, *bob);
    std::cout << "Copied alice uses materia:" << std::endl;
    aliceCopy->use(0, *bob);
    aliceCopy->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	delete alice;
	delete aliceCopy;
	
	return 0;
}

