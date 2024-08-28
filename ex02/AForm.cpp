/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:11:41 by arabelo-          #+#    #+#             */
/*   Updated: 2024/07/02 23:08:27 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>

AForm::AForm(void): _name("No name"), _gradeToSign(150), _gradeToExec(150) {
	_isSigned = false;
}

AForm::AForm(const AForm &obj): _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec) {
	_isSigned = false;
}

AForm	&AForm::operator=(const AForm &obj) {
	if (this != &obj)
		_isSigned = obj._isSigned;
	return (*this);
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else if (_gradeToSign < 0 || _gradeToExec < 0)
		throw AForm::GradeTooHighException();
	_isSigned = false;
}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	AForm::getGradeToExec(void) const {
	return (_gradeToSign);
}

void	AForm::beSigned(Bureaucrat &obj) {
	if (obj.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low");
}

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high");
}

std::ostream	&operator<<(std::ostream &o,  AForm const &f)
{
	o << "AForm name is: " << f.getName() << std::endl;
	o << "AForm signed status: " << f.getIsSigned() << std::endl;
	o << "AForm grade to sign: " << f.getGradeToSign() << std::endl;
	o << "AForm grade to execute: " << f.getGradeToExec() << std::endl;
	return (o);
}