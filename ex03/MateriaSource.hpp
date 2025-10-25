/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:19:25 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 17:44:13 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOUCE_HPP
#define MATERIASOUCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		int index;
		AMateria *materiaList[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource& operator=(const MateriaSource &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type); 
} ;

#endif