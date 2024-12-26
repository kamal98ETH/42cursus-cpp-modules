/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:40:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/16 17:16:11 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	unsigned int	ANIMALSNUM = 10;
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
		delete animals[i];
	}

	// A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies are deep copies!

	
	return (0);
}