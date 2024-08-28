/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 02:25:44 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/25 01:24:24 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat	&operator=(const Bureaucrat &obj);
		~Bureaucrat(void);
		int			getGrade(void) const;
		std::string	getName(void) const;
		void		increment(void);
		void		decrement(void);

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