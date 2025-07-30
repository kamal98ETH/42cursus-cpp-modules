/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:48:51 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/30 03:03:11 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{}

template <typename T, typename Container>
typename MutantStack<T, Container>::MutantStack&
MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{}

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

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}
		
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

