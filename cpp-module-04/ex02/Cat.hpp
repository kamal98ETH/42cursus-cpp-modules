/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:26:58 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/13 18:24:29 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain*	brain;
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat&	operator=(const Cat &other);
		~Cat(void);
		
		void	makeSound(void) const;
};

#endif