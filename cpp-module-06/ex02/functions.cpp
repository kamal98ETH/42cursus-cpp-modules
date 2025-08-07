/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:18:42 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 02:26:36 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes.hpp"

Base*	generate(void)
{
	std::srand(std::time(0));
	int	chance = std::rand() % 3;
	if (chance == 0)
		return (new A());
	else if (chance == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is an object of type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is an object of type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is an object of type C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "This is an object of type A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "This is an object of type B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "This is an object of type C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
