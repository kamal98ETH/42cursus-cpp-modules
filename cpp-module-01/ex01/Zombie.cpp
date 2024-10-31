/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:46:03 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/10/31 23:28:37 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	Zombie::name = "default";
}

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << ": Deeeaaaaaaaaaddddddddd..." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
