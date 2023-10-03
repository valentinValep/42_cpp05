#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	int					_is_signed;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
public:
	AForm(); // Default constructor
	AForm(const AForm &src); // Copy constructor
	AForm(std::string const &name, int grade_to_sign, int grade_to_execute);
	virtual ~AForm(); // Destructor
	AForm	&operator=(const AForm &src); // Assignment operator

	// Getters
	std::string const	&getName() const;
	int					getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Methods
	void				beSigned(const Bureaucrat &signer);
	virtual void		execute(const Bureaucrat &executor) const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &src);
