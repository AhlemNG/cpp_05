#include "../incs/PresidentialPardonForm.hpp"

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
PresidentialPardonForm::PresidentialPardonForm(/* args */): AForm()
{
    // std::cout << BLUE << "PresidentialPardonForm constructor called " << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << BLUE << "PresidentialPardonForm destructor called " << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try{
        AForm::checkExecRequirements(executor);
    std::cout << _target <<" has been pardoned by Zaphod Beeblerox" << std::endl;
    }catch(std::exception const & e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
}