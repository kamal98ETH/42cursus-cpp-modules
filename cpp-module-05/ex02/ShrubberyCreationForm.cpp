/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:19:54 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/27 06:50:57 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string	asciiTree(void)
{
	std::string	str = ".\n";
	str += "                                   .         ;  \n";
	str += "      .              .              ;%     ;;   \n";
	str += "        ,           ,                :;%  %;   \n";
	str += "         :         ;                   :;%;'     .,   \n";
	str += ",.        %;     %;            ;        %;'    ,;\n";
	str += "  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	str += "   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	str += "    ;%;      %;        ;%;        % ;%;  ,%;'\n";
	str += "     `%;.     ;%;     %;'         `;%%;.%;'\n";
	str += "      `:;%.    ;%%. %@;        %; ;@%;%'\n";
	str += "         `:%;.  :;bd%;          %;@%;'\n";
	str += "           `@%:.  :;%.         ;@@%;'   \n";
	str += "             `@%.  `;@%.      ;@@%;         \n";
	str += "               `@%%. `@%%    ;@@%;        \n";
	str += "                 ;@%. :@%%  %@@%;       \n";
	str += "                   %@bd%%%bd%%:;     \n";
	str += "                     #@%%%%%:;;\n";
	str += "                     %@@%%%::;\n";
	str += "                     %@@@%(o);  . '         \n";
	str += "                     %@@@o%;:(.,'         \n";
	str += "                 `.. %@@@o%::;         \n";
	str += "                    `)@@@o%::;         \n";
	str += "                     %@@(o)::;        \n";
	str += "                    .%@@@@%::;         \n";
	str += "                    ;%@@@@%::;.          \n";
	str += "                   ;%@@@@%%:;;;. \n";
	str += "               ...;%@@@@@%%:;;;;,..\n";
	return (str);
}

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	(void) other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void	ShrubberyCreationForm::action(void) const
{
	std::string	filename = target + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw std::ios_base::failure("ERROR: File cannot be opened");
	file << asciiTree();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	action();
}
