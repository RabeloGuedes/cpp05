/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:17:49 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:55:12 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = obj._target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	if (this != &obj) {
		this->_target = obj._target;
		AForm::operator=(obj);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream	file(fileName.c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::FailedWriteFile();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
}

const char	*ShrubberyCreationForm::FailedWriteFile::what(void) const throw() {
	return ("Error: could not open file.");
}