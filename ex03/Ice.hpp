/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:34:30 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 18:12:37 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);

		AMateria* clone() const;
		void use(ICharacter& target);
} ;

#endif