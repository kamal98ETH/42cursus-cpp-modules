/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:34 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/23 00:51:18 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& other);
		Cure&	operator=(const Cure& other);
		~Cure(void);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
