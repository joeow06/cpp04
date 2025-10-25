/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:41:47 by jow               #+#    #+#             */
/*   Updated: 2025/10/25 14:43:33 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain;

public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound() const;
	Brain *getBrain() const;
};

#endif