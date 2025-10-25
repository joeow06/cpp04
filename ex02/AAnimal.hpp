/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:40:31 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 01:11:27 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	AAnimal(std::string _type);

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif