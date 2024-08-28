/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:39:46 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:52:07 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <AForm.hpp>

class	ShrubberyCreationForm: public AForm {
	private:
		std::string	_target;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);

		void	execute(Bureaucrat const & executor) const;

		class	FailedWriteFile: public std::exception {
			public:
				const char	*what(void) const throw();
		};
};

#endif