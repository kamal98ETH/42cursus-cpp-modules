/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:18:14 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/03 15:47:52 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		int		level;
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl(std::string level);
		void	complain(void);
};

#endif
