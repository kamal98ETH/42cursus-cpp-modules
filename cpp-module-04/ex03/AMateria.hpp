/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:24:47 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/23 02:03:37 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <cstdlib>
# include "ICharacter.hpp"
# include "Character.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria(void);
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif