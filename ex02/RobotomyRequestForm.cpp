/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 01:47:45 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:51:23 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>
#include <time>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): AForm(obj) {
	this->_target = obj._target;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	if (this != &obj) {
		this->_target = obj._target;
		AForm::operator=(obj);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	int random_number;
	std::srand(time());

	random_number = rand() % 2;
	std::cout << "Bzzzzzz Bzzzzzz Bzzzzzz" << std::endl;
	if (random_number != 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		throw FailedRobotomize();
}


const char	*RobotomyRequestForm::FailedRobotomize::what(void) const throw() {
	return ("Robotomization failed");
}
