/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:40:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/14 03:03:07 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	int	ANIMALSNUM = 10;
	Animal*	animals[ANIMALSNUM];

	int	i = 0;
	while (i < ANIMALSNUM / 2)
	{
		animals[i] = new Cat();
		i++;
	}
	while (i < ANIMALSNUM)
	{
		animals[i] = new Dog();
		i++;
	}

	for (int i = 0; i < ANIMALSNUM; i++)
	{
		std::cout << " -> Animal number " << i << " :" << std::endl;
		std::cout << "	Is type of a " << animals[i]->getType() << ", and it sounds like ";
		animals[i]->makeSound(); 
	}
	
	for (int i = 0; i < ANIMALSNUM; i++)
	{
		delete animals[i];
	}
	
	return (0);
}