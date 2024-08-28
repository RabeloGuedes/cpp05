/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 01:45:15 by arabelo-          #+#    #+#             */
/*   Updated: 2024/08/28 03:46:24 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <AForm.hpp>

class PresidentialPardonForm: public AForm {
	private:
		std::string	_target;
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);
		void	execute(Bureaucrat const & executor) const;
};

#endif