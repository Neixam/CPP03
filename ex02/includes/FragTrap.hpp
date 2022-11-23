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
#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
public:
    ~FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& oth);
    FragTrap&   operator=(const FragTrap& oth);
    void        attack(const std::string& target);
    void        highFivesGuys(void);
private:
    FragTrap();
};

std::ostream&   operator<<(std::ostream& os, const FragTrap& obj);
#endif
