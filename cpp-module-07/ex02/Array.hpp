/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:02:11 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/20 15:56:28 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T> class Array
{
	private:
		T			*arr;
		std::size_t	len;
	public:
		Array(void)
		{
			len = 0;
			arr = new T[0];
		};
		Array(unsigned int n)
		{
			len = n;
			arr = new T[n];
		};
		Array(const Array& other)
		{
			len = other.size();
			arr = new T[len];

			for (std::size_t i = 0; i < len; i++)
			{
				arr[i] = other.arr[i];
			}
		};
		Array&	operator=(const Array& other)
		{
			if (&other != this)
			{
				delete[]	arr;
				len = other.size();
				arr = new T[len];

				for (std::size_t i = 0; i < len; i++)
				{
					arr[i] = other.arr[i];
				}
			}
			return (*this);
		}
		~Array()
		{
			delete[] arr;
		};
		
		T&	operator[](std::size_t index)
		{
			if (index >= len)
				throw std::out_of_range("Array index out of range");
			return (arr[index]);
		};

		// should this be?
		const T&	operator[](std::size_t index) const
		{
			if (index >= len)
				throw std::out_of_range("Array index out of range");
			return (arr[index]);
		};
		
		std::size_t	size(void) const
		{
			return (len);
		};
};

#endif
