/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:11:41 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/27 18:24:00 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>

Form::Form(void): _name("No name"), _gradeToSign(150), _gradeToExec(150) {
	_isSigned = false;
}

Form::Form(const Form &obj): _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec) {
	_isSigned = false;
}

Form	&Form::operator=(const Form &obj) {
	if (this != &obj)
		_isSigned = obj._isSigned;
	return (*this);
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
	_isSigned = false;
}

Form::~Form(void) {}

std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	Form::getGradeToExec(void) const {
	return (_gradeToSign);
}

void	Form::beSigned(Bureaucrat &obj) {
	if (obj.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

std::ostream	&operator<<(std::ostream &o,  Form const &f)
{
	o << "Form name is: " << f.getName() << std::endl;
	o << "Form signed status: " << f.getIsSigned() << std::endl;
	o << "Form grade to sign: " << f.getGradeToSign() << std::endl;
	o << "Form grade to execute: " << f.getGradeToExec() << std::endl;
	return (o);
}