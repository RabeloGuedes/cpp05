/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 02:41:02 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/27 21:34:01 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void): _name("no name"), _grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj._name), _grade(obj._grade) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj)
		_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}


int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

std::string	Bureaucrat::getName(void) const {
	return (_name);
}

void	Bureaucrat::increment(void) {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrement(void) {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high, can not be greater than 1");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is to low, can not be lower than 150");
}

std::ostream&	operator<<(std::ostream &s,Bureaucrat &obj) {
	s << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (s);
}

void	Bureaucrat::signForm(AForm &obj) {
	try {
		obj.beSigned(*this);
		std::cout << _name << " signed " << obj.getName() << std::endl;
	} catch (AForm::GradeTooLowException &error) {
		std::cerr << _name << " couldn't sign " << obj.getName() << " because " << error.what() << std::endl;
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknow error" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &error) {
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << error.what() << std::endl;
	} catch (std::exception &error) {
		std::cerr << error.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknow error" << std::endl;
	}
}