/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:56:47 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/21 23:22:41 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string	name;
		AMateria	*inventory[4];
		AMateria	**archive;
		int			totalArchive;
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character(void);
		
		std::string const&	getName(void) const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
		void	addArchive(AMateria *amateria);
		void	cleanArchive(void);
};

#endif