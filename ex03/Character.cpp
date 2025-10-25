/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:55:28 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 00:48:27 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""), inventory(), itemCount(0) {}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

Character::Character(const Character &other) 
	: _name(other.getName()), itemCount(other.getItemCount())
{
	for (int i = 0; i < 4; i++)
	{
		if (other.getMateria(i))
			this->inventory[i] = other.getMateria(i)->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->itemCount = other.getItemCount();
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (other.getMateria(i))
				this->inventory[i] = other.getMateria(i)->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);	
}

Character::Character(std::string name) 
	: _name(name), inventory(), itemCount(0) {}

const std::string& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	if (itemCount < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!inventory[i])
			{
				inventory[i] = m;
				itemCount++;
				std::cout << "Character " << this->getName() << " equipped " 
							<< m->getType() << std::endl;
				return ;
			}
		}
	}
	else
	{
		std::cout << "Character " << this->getName() 
					<< "'s Inventory is full!" << std::endl;
		return ;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
	{
		std::cout << "Invalid index! Character " << this->getName() 
				<< " cannot unequip slot " << idx << std::endl;
		return ;
	}
	else if (!inventory[idx])
	{
		std::cout << "Character " << this->getName() 
				<< "'s slot " << idx << " is empty!" << std::endl;
		return ;
	}
	
	AMateria *trash = inventory[idx];
	inventory[idx] = NULL;
	floor.addToFloor(trash);
	itemCount--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
	else
		std::cout << "Character " << this->getName() 
		<< " is unable to use its Materia at slot " << idx << std::endl;
}

int Character::getItemCount() const
{
	return (this->itemCount);
}

AMateria* Character::getMateria(int i) const
{
	if (i < 0 || i >= 4)
		return NULL;
	return inventory[i];
}
