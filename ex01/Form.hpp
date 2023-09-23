#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	int					_is_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
public:
	Form(); // Default constructor
	Form(const Form &src); // Copy constructor
	Form(std::string const &name, int grade_to_sign, int grade_to_execute);
	~Form(); // Destructor
	Form	&operator=(const Form &src); // Assignment operator

	// Getters
	std::string const	&getName() const;
	int					getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Methods
	void				beSigned(const Bureaucrat &signer);

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

std::ostream	&operator<<(std::ostream &out, const Form &src);
