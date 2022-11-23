/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:06:57 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/15 18:06:58 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
    ~ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& oth);
    ScavTrap&   operator=(const ScavTrap& oth);
    void        attack(const std::string& target);
    void        guardGate();
    ScavTrap();
};

std::ostream&   operator<<(std::ostream& os, const ScavTrap& obj);
#endif
