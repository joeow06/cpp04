/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:19:32 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 01:31:09 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

# include <iostream>
//forward declare (prevent circular dependancy)
class AMateria;

class Floor
{
	private:
		struct FloorNode
		{
			AMateria *floorTrash;
			FloorNode *next;
		} ;
		FloorNode *head;

	public:
		Floor();
		~Floor();
		Floor(const Floor &other);
		Floor& operator=(const Floor &other);

		void addToFloor(AMateria *trash);
		void clearFloor();
} ;

#endif