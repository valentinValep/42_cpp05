#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	srand(time(NULL));

	Bureaucrat	ness("Ness", 2);
	Bureaucrat	hero("Hero", 150);
	Bureaucrat	rob("Rob", 50);
	PresidentialPardonForm	presidentialPardonForm("Link");
	PresidentialPardonForm	copy(presidentialPardonForm);
	PresidentialPardonForm	copy2 = presidentialPardonForm;
	RobotomyRequestForm		robotomyRequestForm("Young Link");
	ShrubberyCreationForm	shrubberyCreationForm("Toon Link");

	try
	{
		presidentialPardonForm.execute(ness);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	ness.signForm(presidentialPardonForm);
	ness.executeForm(presidentialPardonForm);
	hero.signForm(robotomyRequestForm);
	try
	{
		robotomyRequestForm.beSigned(hero);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	rob.signForm(robotomyRequestForm);
	rob.executeForm(robotomyRequestForm);
	ness.executeForm(robotomyRequestForm);
	rob.signForm(shrubberyCreationForm);
	rob.executeForm(shrubberyCreationForm);
}
