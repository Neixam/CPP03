/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:25:28 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/23 14:25:29 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

const static std::string RED = "\033[31m";
const static std::string GREEN = "\033[32m";
const static std::string NEUTRAL = "\033[0m";

DiamondTrap::DiamondTrap() :  ClapTrap(), FragTrap(), ScavTrap()
{
    _name = ScavTrap::getName();
    ScavTrap::setHP(100);
    ScavTrap::setAD(30);
    std::cout << GREEN << "DiamondTrap Constructor" << NEUTRAL << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED << "DiamondTrap Destructor " << _name << NEUTRAL << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    _name = name;
    ScavTrap::setHP(100);
    ScavTrap::setAD(30);
    std::cout << GREEN << "DiamondTrap Constructor with arg " << _name << NEUTRAL << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &oth) : ClapTrap(oth._name), FragTrap(oth._name), ScavTrap(oth._name)
{
    *this = oth;
    _name = ScavTrap::getName();
    std::cout << GREEN << "FragTrap Copy Constructor " << _name << NEUTRAL << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ancestor name is " << ScavTrap::name() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &oth)
{
    if (&oth == this)
        return *this;
    *this = oth;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

std::ostream&   operator<<(std::ostream& os, const DiamondTrap& obj)
{
	return os << obj.getName() << " stat(HP=" << obj.getHP() << ", EP=" << obj.getEP() << ", AD="
			  << obj.getAD() << ")";
}
