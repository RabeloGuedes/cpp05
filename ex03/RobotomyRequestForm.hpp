/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 01:40:47 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:54:09 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>

class	RobotomyRequestForm: public AForm {
	private:
		std::string	_target;
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		void	execute(Bureaucrat const & executor) const;

		class	FailedRobotomize: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

#endif