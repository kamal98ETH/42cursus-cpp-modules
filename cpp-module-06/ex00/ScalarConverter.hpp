/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:39:21 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 01:32:31 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cmath>
# include <climits>
# include <iomanip>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
}	t_type;

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter(void);

		static t_type	get_type(const std::string& literal);
		static void		handle_char(const std::string& literal, char &c, int &i, float &f, double &d);
		static void		handle_int(const std::string& literal, char &c, int &i, float &f, double &d);
		static void		handle_float(const std::string& literal, char &c, int &i, float &f, double &d);
		static void		handle_double(const std::string& literal, char &c, int &i, float &f, double &d);
	public:
		static void	convert(const std::string& literal);
};

#endif