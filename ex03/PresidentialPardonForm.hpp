#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm(); // Default constructor
	PresidentialPardonForm(const PresidentialPardonForm &src); // Copy constructor
	PresidentialPardonForm(std::string const &target);
	~PresidentialPardonForm(); // Destructor
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &src); // Assignment operator

	void	execute(Bureaucrat const &executor) const;
};
