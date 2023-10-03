#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("")
{
	// Default constructor
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm(src)
{
	// Copy constructor
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// Destructor
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	this->_target = src._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
