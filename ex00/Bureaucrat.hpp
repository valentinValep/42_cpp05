#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat(); // Default constructor
	Bureaucrat(const Bureaucrat &src); // Copy constructor
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat(); // Destructor
	Bureaucrat	&operator=(const Bureaucrat &src); // Assignment operator

	// Getters
	std::string const	&getName() const;
	int					getGrade() const;

	// Methods
	void				incrementGrade();
	void				decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);
