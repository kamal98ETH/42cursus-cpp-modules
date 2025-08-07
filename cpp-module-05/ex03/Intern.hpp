/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:48:30 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 01:03:16 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm*	makeSC(std::string formTarget);
		AForm*	makeRR(std::string formTarget);
		AForm*	makePP(std::string formTarget);
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern&	operator=(const Intern& other);
		~Intern(void);

		AForm*	makeForm(std::string formName, std::string formTarget);
};

#endif
