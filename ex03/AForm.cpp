#include "AForm.hpp"

AForm::AForm(): _name("default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	// Default constructor
}

AForm::AForm(const AForm &src): _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	// Copy constructor
	*this = src;
}

AForm::AForm(std::string const &name, int grade_to_sign, int grade_to_execute): _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	// Destructor
}

AForm	&AForm::operator=(const AForm &src)
{
	if (this == &src)
		return (*this);
	_is_signed = src._is_signed;
	return (*this);
}

int AForm::getGradeToSign() const
{
	return _grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return _grade_to_execute;
}

int AForm::getIsSigned() const
{
	return _is_signed;
}

std::string const &AForm::getName() const
{
	return _name;
}

void AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_is_signed)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > _grade_to_execute)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << src.getName() << " form, grade required to sign: " << src.getGradeToSign() << ", grade required to execute: " << src.getGradeToExecute() << ", is signed: " << src.getIsSigned();
	return (out);
}
