/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 00:14:44 by arabelo-          #+#    #+#             */
/*   Updated: 2024/06/29 16:59:57 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int		main(void) {
	{
		std::cout << "=========================== TESTING RICHARD | GRADE 1 ==========================" << std::endl << std::endl;
		Bureaucrat	a("Richard", 1);

		try {
			a.increment();
		} catch (Bureaucrat::GradeTooHighException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << a << std::endl;
		std::cout << std::endl << "=========================== TESTING RICHARD | GRADE 1 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING HARRY | GRADE 150 ==========================" << std::endl << std::endl;
		Bureaucrat	b("Harry", 150);

		try {
			b.decrement();
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << b << std::endl;
		std::cout << std::endl << "=========================== TESTING HARRY | GRADE 150 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING LAURENCE | GRADE 151 ==========================" << std::endl << std::endl;
		try {
			Bureaucrat	b("Laurence", 151);
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING LAURENCE | GRADE 151 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING DERICK | GRADE 0 ==========================" << std::endl << std::endl;
		try {
			Bureaucrat	b("Derick", 0);
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING DERICK | GRADE 0 ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING ROBERT | GRADE 1 - POSITIVE INFINITY ==========================" << std::endl << std::endl;
		Bureaucrat	b("Robert", 1);
		std::cout << b << std::endl;
		try {
			while (true)
				b.decrement();
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING ROBERT | GRADE 1 - POSITIVE INFINITY ==========================" << std::endl << std::endl;
	}
	{
		std::cout << "=========================== TESTING JOHN | GRADE 150 - NEGATIVE INFINITY ==========================" << std::endl << std::endl;
		Bureaucrat	b("John", 150);
		std::cout << b << std::endl;
		try {
			while (true)
				b.increment();
		} catch (Bureaucrat::GradeTooLowException &error) {
			std::cerr << error.what() << std::endl;
		} catch (std::exception &error) {
			std::cerr << error.what() << std::endl;
		} catch (...) {
			std::cerr << "Unknow error" << std::endl;
		}
		std::cout << std::endl << "=========================== TESTING JOHN | GRADE 150 - NEGATIVE INFINITY ==========================" << std::endl << std::endl;
	}
}