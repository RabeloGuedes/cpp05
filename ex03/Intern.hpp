/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:12:09 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:35:20 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <Bureaucrat.hpp>
# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <PresidentialPardonForm.hpp>
# include <utility>

typedef AForm *(*formCreate)(std::string target);
typedef std::pair<std::string, formCreate> formPair;

class Intern {
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);
		Intern &operator=(const Intern &assign);

		AForm *makeForm(std::string formName, std::string target);
};

#endif