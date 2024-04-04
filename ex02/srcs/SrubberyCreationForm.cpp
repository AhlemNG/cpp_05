#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << BLUE << "ShrubberyCreationForm  default constructor called for target " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 0, 145, 137)
{
    std::cout << BLUE << "ShrubberyCreationForm parametric constructor called for target " << _target << std::endl;
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << BLUE << "ShrubberyCreationForm destructor called for target " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src): AForm(src)
{
    std::cout << BLUE << "ShrubberyCreationForm  copy constructor called for target " << _target << std::endl;
    _target = src._target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) // copy assignation operator
{
    std::cout << BLUE << "ShrubberyCreationForm  copy assignation operator called for target " << _target << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->_isSigned = rhs.getState();
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw(AForm::FormNotSigned());
    else if (executor.getGrade() > _execGrade)
        throw(Bureaucrat::GradeTooLowException());
    else 
    {
        std::fstream file((_target + "_shrubbery").c_str());
        if(!file.is_open())
        {
            std::cout << "error" << std::endl;
        }
        file << "      _-_" << std::endl;
        file << "  /~~      ~~\"" << std::endl;
        file << " /~~         ~~\"" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "   ~  \\ //  ~" << std::endl;
        file << "_- -   | | _- _" << std::endl;
        file << "  _ -  | |   -_" << std::endl;
        file << "      // \\" << std::endl;
        file.close(); 
    }
}
