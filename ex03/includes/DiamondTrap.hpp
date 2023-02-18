/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:25:43 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/23 14:25:46 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
    ~DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& oth);
    DiamondTrap& operator=(const DiamondTrap& oth);
    void    attack(const std::string& target);
    void    whoAmI();
private:
    DiamondTrap();
    std::string _name;
};
std::ostream&   operator<<(std::ostream& os, const DiamondTrap& obj);


#endif
