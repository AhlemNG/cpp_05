#include "../incs/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(/* args */): AForm("PresidentialPardonForm", 0, 25, 5)
{
    // std::cout << BLUE << "PresidentialPardonForm constructor called " << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 0, 25, 5)
{
    std::cout << BLUE << "PresidentialPardonForm parametric constructor called " << RESET << std::endl;
    _target = target;

}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src)
{
 std::cout << BLUE << "PresidentialPardonForm copy constructor called " << RESET << std::endl;
    _target = src._target;
}
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
     std::cout << BLUE << " PresidentialPardonForm copy assignation operator called " << RESET << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->_isSigned = rhs.getState();
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << BLUE << "PresidentialPardonForm destructor called " << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw(AForm::FormNotSigned());
    else if (executor.getGrade() > _execGrade)
        throw(Bureaucrat::GradeTooLowException());
    else 
        std::cout << GREEN <<_target <<" has been pardoned by Zaphod Beeblerox" << RESET << std::endl;
}