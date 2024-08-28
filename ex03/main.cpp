/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:14:44 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:41:44 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main(void) {

	{
	std::cout << "=====================TEST INTERN WITH SHRUBBERY CREATION FORM=====================" << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "home");

		try {
			Bureaucrat bureaucrat("bureaucrat", 1);
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			delete form;
			std::cerr << e.what() << std::endl;
		}
	}
	{
	std::cout << "=====================TEST INTERN WITH ROBOTOMY REQUEST FORM=====================" << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("robotomy request", "home");

		try {
			Bureaucrat bureaucrat("bureaucrat", 1);
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			delete form;
			std::cerr << e.what() << std::endl;
		}
	}
	{
	std::cout << "=====================TEST INTERN WITH PRESIDENTIAL PARDON FORM=====================" << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "home");

		try {
			Bureaucrat bureaucrat("bureaucrat", 1);
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			delete form;
			std::cerr << e.what() << std::endl;
		}
	}
	{
	std::cout << "=====================TEST INTERN WITH FORM NOT FOUND=====================" << std::endl;
		Intern intern;
		AForm *form = intern.makeForm("form not found", "home");

		try {
			Bureaucrat bureaucrat("bureaucrat", 1);
			if (form) {
				bureaucrat.signForm(*form);
				bureaucrat.executeForm(*form);
			}
			delete form;
		} catch (std::exception &e) {
			delete form;
			std::cerr << e.what() << std::endl;
		}
	}

    return 0;
}