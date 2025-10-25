/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:08:40 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 18:18:09 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);

		AMateria* clone() const;
		void use(ICharacter& target);
} ;

#endif