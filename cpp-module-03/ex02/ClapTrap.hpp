/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:27 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/28 20:50:18 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class  ClapTrap
{
protected:
	std::string	name;
	int			hitPts;
	int			energyPts;
	int			attackDmg;
public:
	ClapTrap(void);  // Default constructor
	ClapTrap(std::string name);  // secondary constructor
	ClapTrap(const ClapTrap& other);  // Copy constructor
	ClapTrap& operator=(const ClapTrap& other);  // Assignment operator
	~ClapTrap(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif