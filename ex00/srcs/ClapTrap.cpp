/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:39 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/10 14:58:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{

}

ClapTrap::~ClapTrap()
{

}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this == &other)
        return *this;
    _name = other.getName();
    _hitPoint = other.getHP();
    _energyPoint = other.getEP();
    _attackDamage = other.getAD();
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoint <= 0 || _hitPoint <= 0)
    {
        std::cout << _name << " can't attack anymore" << std::endl;
        return;
    }
    _energyPoint--;
    std::cout << _name << " attack " << target << " and lost " << _attackDamage << " hp" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoint <= 0 || _hitPoint <= 0)
    {
        std::cout << _name << " can't repaired anymore" << std::endl;
        return;
    }
    _energyPoint--;
    _hitPoint += amount;
}

ClapTrap::ClapTrap() : _name("Joe"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{

}

std::string ClapTrap::getName() const
{
    return _name;
}

unsigned int ClapTrap::getHP() const
{
    return _hitPoint;
}

unsigned int ClapTrap::getEP() const
{
    return _energyPoint;
}

unsigned int ClapTrap::getAD() const
{
    return _attackDamage;
}
