/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:01:46 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/10/26 16:53:43 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
