#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// Default constructor
}

Intern::Intern(const Intern &src)
{
	// Copy constructor
	*this = src;
}

Intern::~Intern()
{
	// Destructor
}

Intern	&Intern::operator=(const Intern &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	// better use the factory design pattern
	std::string	formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm		*forms[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
	AForm		*form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			form = forms[i];
		}
		else
			delete forms[i];
	}
	if (!form)
		throw Intern::FormNotFoundException();
	return form;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
