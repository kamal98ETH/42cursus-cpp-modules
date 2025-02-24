/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:40:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/13 16:44:12 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << " -> Type of object j (The Dog):" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << " -> Type of object i (The Cat):" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << " -> Sound of object i (The Cat):" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << " -> Sound of object j (The Dog):" << std::endl;
	j->makeSound();
	std::cout << " -> Sound of object meta (The Animal):" << std::endl;
	meta->makeSound();


	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << " -> Type of object wrongAnimal:" << std::endl;
	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << " -> Type of object wrongCat:" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << " -> Sound of object wrongAnimal:" << std::endl;
	wrongAnimal->makeSound();
	std::cout << " -> Sound of object wrongCat:" << std::endl;
	wrongCat->makeSound();


	delete meta;
	delete j;
	delete i;
	delete wrongCat;
	delete wrongAnimal;
	
	return (0);
}