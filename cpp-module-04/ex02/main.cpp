/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:40:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/17 15:59:51 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	// this doesn't work
	// Animal	animal;
	
	// while this works
	Dog	mydog;
	Cat	mycat;

	mydog.makeSound();
	mycat.makeSound();
	
	return (0);
}