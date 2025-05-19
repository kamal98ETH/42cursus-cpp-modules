/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:10:53 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/19 03:16:28 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes.hpp"

int	main()
{
	Base	*objPtr = generate();
	Base	&objRef = *objPtr;

	identify(objPtr);
	identify(objRef);
	
	return (0);
}
