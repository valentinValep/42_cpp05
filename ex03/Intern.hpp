#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
private:
	/* data */
public:
	Intern(); // Default constructor
	Intern(const Intern &src); // Copy constructor
	~Intern(); // Destructor
	Intern	&operator=(const Intern &src); // Assignment operator

	AForm	*makeForm(std::string formName, std::string target);

	class FormNotFoundException: public std::exception
	{
			virtual const char *what() const throw();
	};
};
