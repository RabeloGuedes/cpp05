/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 02:25:44 by arabelo-          #+#    #+#             */
/*   Updated: 2024/07/02 17:42:00 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <Form.hpp>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		size_t				_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, size_t grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat	&operator=(const Bureaucrat &obj);
		~Bureaucrat(void);
		size_t		getGrade(void) const;
		std::string	getName(void) const;
		void		increment(void);
		void		decrement(void);

		void	signForm(Form &obj);

		class	GradeTooHighException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
		class	GradeTooLowException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream &s, Bureaucrat &obj);

#endif