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

const static std::string RED = "\033[31m";
const static std::string GREEN = "\033[32m";
const static std::string NEUTRAL = "\033[0m";

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << GREEN << "ClapTrap Constructor with arg " << name << NEUTRAL << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED << "ClapTrap Destructor " << _name << NEUTRAL << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << GREEN << "ClapTrap Copy Constructor " << _name << NEUTRAL << std::endl;
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
    std::cout << "ClapTrap" << _name << " attack " << target << " and lost " << _attackDamage << " hp" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= _hitPoint)
        _hitPoint = 0;
    else
        _hitPoint -= amount;
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
    std::cout << GREEN << "ClapTrap Constructor" << NEUTRAL << std::endl;
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

void ClapTrap::setHP(unsigned int hp)
{
    _hitPoint = hp;
}

void ClapTrap::setEP(unsigned int ep)
{
    _energyPoint = ep;
}

void ClapTrap::setAD(unsigned int ad)
{
    _attackDamage = ad;
}

std::string ClapTrap::name() const
{
    return _name + "_clap_name";
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& obj)
{
    return os << obj.getName() << " stat(HP=" << obj.getHP() << ", EP=" << obj.getEP() << ", AD="
       << obj.getAD() << ")";
}