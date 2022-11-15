/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:48 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/10 14:58:49 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
public:
    ClapTrap(const std::string& name);
    ~ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap&       operator=(const ClapTrap& other);
    void            attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    std::string     getName() const;
    unsigned int    getHP() const;
    unsigned int    getEP() const;
    unsigned int    getAD() const;
private:
    ClapTrap();
    std::string     _name;
    unsigned int    _hitPoint;
    unsigned int    _energyPoint;
    unsigned int    _attackDamage;
};

std::ostream&   operator<<(std::ostream& os, const ClapTrap& obj);
#endif
