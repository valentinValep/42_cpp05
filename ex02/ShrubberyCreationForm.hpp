#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	std::string	_target;
public:
	ShrubberyCreationForm(); // Default constructor
	ShrubberyCreationForm(const ShrubberyCreationForm &src); // Copy constructor
	ShrubberyCreationForm(std::string const &target);
	~ShrubberyCreationForm(); // Destructor
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src); // Assignment operator

	void	execute(Bureaucrat const &executor) const;
};
