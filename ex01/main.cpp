#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	ness("Ness", 2);
	Bureaucrat	hero("Hero", 43);
	Form		form1("Final Destination", 2, 2);
	Form		form2("Pokemon Stadium 2", 42, 42);

	std::cout << ness << std::endl; // print "Ness, bureaucrat grade 2"
	std::cout << hero << std::endl; // print "Hero, bureaucrat grade 43"
	std::cout << form1 << std::endl; // print "FD, bureaucrat grade 2, bureaucrat grade 2, is signed : 0"
	std::cout << form2 << std::endl; // print "PS2, bureaucrat grade 42, bureaucrat grade 42 is signed : 0"
	try
	{
		ness.signForm(form1); // print "Ness signs FD"
		std::cout << form1 << std::endl; // print "FD, bureaucrat grade 2, bureaucrat grade 2, is signed : 1"
		form1.beSigned(hero);
		std::cout << "Should not be printed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too low"
	}
	std::cout << form1 << std::endl; // print "FD, bureaucrat grade 2, bureaucrat grade 2, is signed : 1"

	try
	{
		ness.signForm(form2); // print "Ness signs PS2"
		std::cout << form2 << std::endl; // print "PS2, bureaucrat grade 42, bureaucrat grade 42 is signed : 1"
		hero.signForm(form2); // print "Hero cannot sign PS2 because his grade is too low"
		std::cout << "Can be printed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form	form3("FD", 0, 42);
		std::cout << form3 << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too high"
	}

	try
	{
		Form	form3("FD", 151, 42);
		std::cout << form3 << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too low"
	}

	try
	{
		Form	form3("FD", 42, 0);
		std::cout << form3 << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too high"
	}

	try
	{
		Form	form3("FD", 42, 151);
		std::cout << form3 << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too low"
	}

	try
	{
		Form	form3("FD", 0, 0);
		std::cout << form3 << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too high"
	}
}
