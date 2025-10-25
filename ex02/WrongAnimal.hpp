/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:40:31 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 00:51:47 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	WrongAnimal(std::string _type);

	std::string getType() const;
	void makeSound() const;
};

#endif