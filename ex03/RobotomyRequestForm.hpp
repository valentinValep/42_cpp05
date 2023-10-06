#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm(); // Default constructor
	RobotomyRequestForm(const RobotomyRequestForm &src); // Copy constructor
	RobotomyRequestForm(std::string const &target);
	~RobotomyRequestForm(); // Destructor
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &src); // Assignment operator

	void	execute(Bureaucrat const &executor) const;
};
