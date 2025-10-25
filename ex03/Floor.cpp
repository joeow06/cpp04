/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:19:30 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 01:31:19 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include "AMateria.hpp"

Floor::Floor() : head(NULL) {}

Floor::Floor(const Floor &other)
{
	this->head = other.head;
}

Floor& Floor::operator=(const Floor &other)
{
	if (this != &other)
		this->head = other.head;
	return (*this);
}

Floor::~Floor()
{
	clearFloor();
}

void Floor::addToFloor(AMateria *trash)
{
	if (!trash)
		return ;
	FloorNode *node = new FloorNode;
	node->floorTrash = trash;
	node->next = head;
	head = node;
}

void Floor::clearFloor()
{
	while (head)
	{
		FloorNode *tmp = head;
		head = head->next;
		delete tmp->floorTrash;
		delete tmp;
	}
}