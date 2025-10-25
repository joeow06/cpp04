/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:31:37 by jow               #+#    #+#             */
/*   Updated: 2025/10/26 01:38:29 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &other)
{
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	(void) other;
	return (*this);
}

AMateria::AMateria(std::string const & type) : _type(type) {}

const std::string& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Unknown magic used on " << target.getName() << std::endl;
}