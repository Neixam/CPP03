/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:02:31 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/23 11:02:32 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

const static std::string RED = "\033[31m";
const static std::string GREEN = "\033[32m";
const static std::string NEUTRAL = "\033[0m";

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap Destructor " << getName() << NEUTRAL << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << GREEN << "FragTrap Constructor with arg " << getName() << NEUTRAL << std::endl;
    setHP(100);
    setEP(100);
    setAD(30);
}

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << GREEN << "FragTrap Constructor " << getName() << NEUTRAL << std::endl;
    setHP(100);
    setEP(100);
    setAD(30);
}

FragTrap::FragTrap(const FragTrap &oth) : ClapTrap(oth)
{
    std::cout << GREEN << "FragTrap Copy Constructor " << getName() << NEUTRAL << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &oth)
{
    if (&oth == this)
        return *this;
    *this = oth;
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (getEP() <= 0 || getHP() <= 0)
    {
        std::cout << getName() << " can't attack anymore" << std::endl;
        return;
    }
    setEP(getEP() - 1);
    std::cout << "FragTrap " << getName() << " attack " << target << " and lost " << getAD() << " hp" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "Let's go HIGH FIVE - *" << getName()
        <<  " raise his hand and waiting for anybody complicity*" << std::endl;
}

std::ostream&   operator<<(std::ostream& os, const FragTrap& obj)
{
    return os << obj.getName() << " stat(HP=" << obj.getHP() << ", EP=" << obj.getEP() << ", AD="
              << obj.getAD() << ")";
}