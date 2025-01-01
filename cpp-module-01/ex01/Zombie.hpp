/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:45:30 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/01 01:54:17 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(void) : name("default") {};
	Zombie(std::string name) : name(name) {};
	~Zombie(void);
	void	announce( void );
};

Zombie*	zombieHorde(int N, std::string name);

#endif
