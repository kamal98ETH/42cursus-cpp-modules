/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:15:43 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/09/18 01:08:28 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	for (i = 1; argv[i]; i++)
		for (j = 0; argv[i][j]; j++)
		argv[i][j] = ::toupper(argv[i][j]);
	for (i = 1; argv[i]; i++)
		std::cout << argv[i];
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << endl;
	return (0);
}
