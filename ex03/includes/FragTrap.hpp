/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:02:39 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/23 11:02:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
    ~FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& oth);
    FragTrap&   operator=(const FragTrap& oth);
    void        attack(const std::string& target);
    void        highFivesGuys();
    FragTrap();
};

std::ostream&   operator<<(std::ostream& os, const FragTrap& obj);
#endif
