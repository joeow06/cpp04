/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:19:14 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 01:29:05 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materiaList[i])
				delete materiaList[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) : count(other.getCount())
{
	for(int i = 0; i < 4; i++)
	{
		if (other.getMateria(i))
			this->materiaList[i] = other.getMateria(i)->clone();
		else
			this->materiaList[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	for(int i = 0; i < 4; i++)
	{
		if (materiaList[i])
			delete materiaList[i];
		if (other.getMateria(i))
			this->materiaList[i] = other.getMateria(i)->clone();
		else
			this->materiaList[i] =	 NULL;
	}
	this->count = other.getCount();
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	if (count < 4)
	{
		materiaList[count] = materia->clone();
		delete materia;
		count++;
	}	
	else
	{
		delete materia;
		std::cout << "MateriaSource can know at most 4 Materias!" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < count; i++)
	{
		if (materiaList[i]->getType() == type)
			return (materiaList[i]->clone());
	}
	return NULL;
}

int MateriaSource::getCount() const
{
	return (count);
}

AMateria* MateriaSource::getMateria(int i) const
{
	return (materiaList[i]);
}