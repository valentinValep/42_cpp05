#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	srand(time(NULL));

	Bureaucrat	ness("Ness", 2);
	Bureaucrat	hero("Hero", 150);
	Bureaucrat	rob("Rob", 50);
	AForm		*form;
	Intern		intern;

	form = intern.makeForm("robotomy request", "Donkey Kong");
	rob.signForm(*form);
	rob.executeForm(*form);
	delete form;
	form = intern.makeForm("presidential pardon", "Diddy Kong");
	rob.signForm(*form);
	rob.executeForm(*form);
	delete form;
	form = intern.makeForm("shrubbery creation", "Dixie Kong");
	rob.signForm(*form);
	rob.executeForm(*form);
	delete form;
}
