/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:46:24 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/06 15:28:34 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->~Form();
		new (this) Form(other);
	}
	return (*this);
}

Form::~Form(void) {}

std::string	Form::getName(void) const
{
	return (_name);
}

bool		Form::getSigned(void) const
{
	return (_signed);
}

int			Form::getSignGrade(void) const
{
	return (_signGrade);
}

int			Form::getExecGrade(void) const
{
	return (_execGrade);
}


void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream&	operator<<(std::ostream &out, const Form &form)
{
	out << "Form "
		<< form.getName()
		<< " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << ", its sign grade is "
		<< form.getSignGrade()
		<< ", and its execution grade is "
		<< form.getExecGrade()
		<< "." 
		<< std::endl;
	return (out);
}

