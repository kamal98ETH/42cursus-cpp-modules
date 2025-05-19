/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:24:38 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/16 00:08:25 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		data;
	uintptr_t	raw;

	raw = Serializer::serialize(&data);
	if (&data == Serializer::deserialize(raw))
	{
		std::cout << "✅ Success: pointers match!\n";
	}
    else
	{
        std::cout << "❌ Failure: pointers differ.\n";
	}

	return (0);
}
