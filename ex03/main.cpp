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
	std::cout << "---------- Init Materia Source ----------" << std::endl;
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
	std::cout << std::endl;

	std::cout << "---------- \"me\" unequip materia test ----------" << std::endl;
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	me->unequip(-1);
	me->unequip(4242);
	std::cout << std::endl;

	
	ICharacter* bob = new Character("bob");
	
	std::cout << "---------- \"me\" use materia test ----------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}

