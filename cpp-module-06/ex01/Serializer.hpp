/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:24:35 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/17 21:32:09 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer(void);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif
