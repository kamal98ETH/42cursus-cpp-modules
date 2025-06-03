/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:48:51 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/24 04:06:23 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "MutantStack.hpp"

// template <typename T, typename Container> MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {}

// template <typename T, typename Container> MutantStack<T, Container>::~MutantStack(void) {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}
		
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end()
{
	return (this->c.end());
}

