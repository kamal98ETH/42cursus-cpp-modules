/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:03:25 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/01 23:55:07 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce( void );
};

Zombie*	newZombie( std::string name );
void	randomChump(std::string name);

#endif
