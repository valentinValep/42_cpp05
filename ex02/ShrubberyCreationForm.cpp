#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("")
{
	// Default constructor
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src)
{
	// Copy constructor
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// Destructor
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	this->_target = src._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file((this->_target + "_shrubbery").c_str());
	file << "               ,@@@@@@@," << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "       |o|        | |         | |" << std::endl;
	file << "       |.|        | |         | |" << std::endl;
	file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	file.close();
}
