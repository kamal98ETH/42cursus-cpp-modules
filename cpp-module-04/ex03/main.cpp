/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:05:13 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/24 01:11:01 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

int main()
{
	// in array of 3 materiasource where we loop to run the same code on the three of them
	IMateriaSource	*srcs[3];
	// create materiasource
	srcs[0] = new MateriaSource();
	// fill the materiasource with more than its capacity
	srcs[0]->learnMateria(new Ice());
	srcs[0]->learnMateria(new Cure());
	srcs[0]->learnMateria(new Ice());
	srcs[0]->learnMateria(new Cure());
	srcs[0]->learnMateria(new Ice());
	srcs[0]->learnMateria(new Cure());
	// copy materiasource
	srcs[1] = new MateriaSource(*(MateriaSource *)srcs[0]);
	// create a third materiasource (empty)
	srcs[2] = new MateriaSource();
	// copy assign third materiasource to copied materiasource
	*(MateriaSource *)srcs[2] = *(MateriaSource *)srcs[1];
		
	for (int i = 0; i < 3; i++)
	{
		std::cout << "	=> Materiasource number " << i +1 << std::endl; 
		// array of 3 characters (one created, other copy constructed, last created and assigned)
		ICharacter	*characters[3];
		// create first character
		characters[0] = new Character("test");
		// fill it more than maximum
		AMateria* tmp;
		tmp = srcs[i]->createMateria("ice");
		characters[0]->equip(tmp);
		tmp = srcs[i]->createMateria("cure");
		characters[0]->equip(tmp);
		tmp = srcs[i]->createMateria("ice");
		characters[0]->equip(tmp);
		tmp = srcs[i]->createMateria("cure");
		characters[0]->equip(tmp);
		tmp = srcs[i]->createMateria("ice");
		characters[0]->equip(tmp);
		tmp = srcs[i]->createMateria("cure");
		characters[0]->equip(tmp);
		// unequip a materia
		characters[0]->unequip(1);
		// create other characters
		characters[1] = new Character(*(Character *)characters[0]);
		characters[2] = new Character("tt");
		*(Character *)characters[2] = *(Character *)characters[1];
		
		// for all characters use all inventory (even empy one) on a dummy character
		for (int j = 0; j < 3; j++)
		{
			std::cout << "		-> Character number " << j +1 << std::endl;
			ICharacter* tmpChar = new Character("target");
			characters[j]->use(0, *tmpChar);
			characters[j]->use(1, *tmpChar);
			characters[j]->use(2, *tmpChar);
			characters[j]->use(3, *tmpChar);
			delete tmpChar;
		}
		// delete allocated memory
		for (int k = 0; k < 3; k++)
			delete characters[k];
	}
	
	// delete allocated memory
	for (int i = 0; i < 3; i++)
		delete srcs[i];

	return 0;
}
