/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:32:26 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/27 21:43:15 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <Bureaucrat.hpp>
# include <iostream>
# include <fstream>
# include <cstdlib>

class Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		AForm(void);
		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);
		AForm(std::string name, int gradeToSign, int gradeToExec);
		virtual ~AForm(void);

		void		beSigned(Bureaucrat &obj);
		void		beSigned(const Bureaucrat &obj);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		virtual void	execute(Bureaucrat const & executor) const = 0;

		class	GradeTooLowException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
		class	GradeTooHighException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o,  AForm const &f);

#endif