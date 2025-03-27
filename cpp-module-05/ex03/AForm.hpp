/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:46:41 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/25 00:31:45 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		AForm(void);
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm(void);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		void		beSigned(Bureaucrat bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		void	canExecute(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream &out, const AForm &form);

#endif