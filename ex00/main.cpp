#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	pyra("Pyra", 2);
	Bureaucrat	mythra("Mythra", 149);

	std::cout << pyra << std::endl; // print "Pyra, bureaucrat grade 2"
	std::cout << mythra << std::endl; // print "Mythra, bureaucrat grade 149"
	try
	{
		pyra.incrementGrade();
		std::cout << pyra << std::endl; // print "Pyra, bureaucrat grade 1"
		pyra.incrementGrade();
		std::cout << pyra << std::endl; // Should not be printed
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl; // print "Grade too high"
	}
	std::cout << pyra << std::endl; // print "Pyra, bureaucrat grade 1"
	try
	{
		mythra.decrementGrade();
		std::cout << mythra << std::endl; // print "Mythra, bureaucrat grade 150"
		mythra.decrementGrade();
		std::cout << mythra << std::endl; // Should not be printed
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl; // print "Grade too low"
	}
	std::cout << mythra << std::endl; // print "Mythra, bureaucrat grade 150"
	try
	{
		Bureaucrat	steve("Steve", 0);
		std::cout << steve << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too high"
	}
	try
	{
		Bureaucrat	steve("Steve", 151);
		std::cout << steve << std::endl; // Should not be printed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n'; // print "Grade too low"
	}
	return (0);
}
