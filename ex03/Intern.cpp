/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:12:11 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 18:16:33 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern(void) {}

Intern::Intern(const Intern &copy) {
	(void)copy;
}

Intern::~Intern(void) {}

Intern	&Intern::operator=(const Intern &assign) {
	(void)assign;
	return (*this);
}

static AForm	*createShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}

static	formPair	*makePairs(void) {
	formPair	z;
	static formPair	formList[3];
	z = std::make_pair("shrubbery creation", &createShrubberyCreationForm);
	formList[0] = z;
	z = std::make_pair("robotomy request", &createRobotomyRequestForm);
	formList[1] = z;
	z = std::make_pair("presidential pardon", &createPresidentialPardonForm);
	formList[2] = z;
	return (formList);;
}

AForm	*Intern::makeForm(std::string formName, std::string target) {
	formPair	*formList = makePairs();

	for (int i = 0; i < 3; i++) {
		if (formList[i].first == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((formList[i].second)(target));
		}
	}
	std::cerr << "Form not found" << std::endl;
	return (NULL);
}