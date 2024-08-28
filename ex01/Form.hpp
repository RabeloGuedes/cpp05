/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:32:26 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/27 18:23:44 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <Bureaucrat.hpp>

class Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		Form(void);
		Form(const Form &obj);
		Form	&operator=(const Form &obj);
		Form(std::string name, int gradeToSign, int gradeToExec);
		~Form(void);

		void		beSigned(Bureaucrat &obj);
		void		beSigned(const Bureaucrat &obj);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		class	GradeTooLowException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
		class	GradeTooHighException: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &o,  Form const &f);

#endif