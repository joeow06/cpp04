/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 22:56:58 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 00:47:14 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *inventory[4];
		int itemCount;
		Floor floor;
		
	public:
		Character();
		~Character();
		Character(const Character &other);
		Character& operator=(const Character &other);

		Character(std::string name);
		const std::string& getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		int getItemCount() const;
		AMateria* getMateria(int i) const;
} ;

#endif