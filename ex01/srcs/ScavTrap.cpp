/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:06:50 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/15 18:06:51 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

const static std::string RED = "\033[31m";
const static std::string GREEN = "\033[32m";
const static std::string NEUTRAL = "\033[0m";

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << GREEN << "ScavTrap Constructor with arg " << name << NEUTRAL << std::endl;
    setHP(100);
    setEP(50);
    setAD(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << GREEN << "ScavTrap Copy Constructor " << getName() << NEUTRAL << std::endl;
    setHP(100);
    setEP(50);
    setAD(20);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (&other == this)
        return *this;
    *this = other;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << getName() << " Gate keeper activated" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << GREEN << "ScavTrap Constructor " << getName() << NEUTRAL << std::endl;
    setHP(100);
    setEP(50);
    setAD(20);
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap Destructor " << getName() << NEUTRAL << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (getEP() <= 0 || getHP() <= 0)
    {
        std::cout << getName() << " can't attack anymore" << std::endl;
        return;
    }
    setEP(getEP() - 1);
    std::cout << "ScavTrap " << getName() << " attack " << target << " and lost " << getAD() << " hp" << std::endl;
}

std::ostream&   operator<<(std::ostream& os, const ScavTrap& obj)
{
    return os << obj.getName() << " stat(HP=" << obj.getHP() << ", EP=" << obj.getEP() << ", AD="
        << obj.getAD() << ")";
}
