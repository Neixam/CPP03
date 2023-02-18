/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:43 by ambouren          #+#    #+#             */
/*   Updated: 2022/11/10 14:58:44 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    {
        ScavTrap tonny("Tonny");
        ClapTrap diego("Diego");
        ClapTrap toto("Toto");
        ClapTrap toto2(toto);

        std::cout << tonny << std::endl;
        std::cout << diego << std::endl;
        tonny.attack(diego.getName());
        diego.takeDamage(tonny.getAD());
        std::cout << tonny << std::endl;
        std::cout << diego << std::endl;

        std::cout << toto << std::endl;
        toto.beRepaired(25);
        std::cout << toto << std::endl;

        std::cout << toto2 << std::endl;
        toto2.takeDamage(55);
        std::cout << toto2 << std::endl;
        toto2.attack(toto.getName());
    }
    {
        ClapTrap tonny("Tonny");
        ScavTrap baptiste("Baptiste");
        ScavTrap coco = baptiste;

        std::cout << coco << std::endl;
        for (int i = 0; tonny.getEP(); i++)
        {
            tonny.attack("Baptiste");
            baptiste.takeDamage(tonny.getAD());
        }
        tonny.beRepaired(25);
        baptiste.guardGate();
        std::cout << coco << std::endl;
        baptiste.attack(coco.getName());
        coco.takeDamage(baptiste.getAD());
        std::cout << coco << std::endl;
    }
    {
        FragTrap tonny("Tonny");

        tonny.attack("no body");
        tonny.highFivesGuys();
    }
    {
        DiamondTrap didier("Didier");

        didier.whoAmI();
		std::cout << didier << std::endl;
        didier.attack("me");
    }
    return 0;
}
