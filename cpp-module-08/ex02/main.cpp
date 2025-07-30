/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:58:36 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/30 03:10:02 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	my_test(void)
{
	std::cout << "######## my own tests ########\n";
	MutantStack<int>	mystack;
	for (int i = 0; i <= 42; i++)
	{
		mystack.push(i);
	}
	std::cout << "printing non-const stack...\n";
	for (MutantStack<int>::iterator it = mystack.begin(); it < mystack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	
	std::cout << "printing const stack...\n";
	const MutantStack<int> my_const_stack = mystack;
	for (MutantStack<int>::const_iterator it = my_const_stack.begin(); it < my_const_stack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

int	main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	while (s.size())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	
	my_test();

	return (0);
}
