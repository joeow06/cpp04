/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:04:59 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 18:16:25 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria &other);
		AMateria& operator=(const AMateria &other);
	
		AMateria(std::string const & type);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
} ;

#endif