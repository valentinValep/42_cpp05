#include "Form.hpp"

Form::Form(): _name("default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	// Default constructor
}

Form::Form(const Form &src): _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	// Copy constructor
	*this = src;
}

Form::Form(std::string const &name, int grade_to_sign, int grade_to_execute): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	// Destructor
}

Form	&Form::operator=(const Form &src)
{
	if (this == &src)
		return (*this);
	_is_signed = src._is_signed;
	return (*this);
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

int Form::getIsSigned() const
{
	return _is_signed;
}

std::string const &Form::getName() const
{
	return _name;
}

void Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << src.getName() << " form, grade required to sign: " << src.getGradeToSign() << ", grade required to execute: " << src.getGradeToExecute() << ", is signed: " << src.getIsSigned();
	return (out);
}
