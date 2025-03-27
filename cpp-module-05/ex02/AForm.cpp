/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:46:24 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/22 07:08:07 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm&	AForm::operator=(const AForm& other)
{
	// if (this != &other)
	// {
	// 	this->~AForm();
	// 	new (this) AForm(other);
	// }
	(void)other;
	return (*this);
}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool		AForm::getSigned(void) const
{
	return (_signed);
}

int			AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int			AForm::getExecGrade(void) const
{
	return (_execGrade);
}


void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream&	operator<<(std::ostream &out, const AForm &form)
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

void	AForm::canExecute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (!_signed)
		throw FormNotSignedException();
}
