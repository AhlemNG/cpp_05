#include "../incs/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 0, 72, 45)
{
    std::cout << BLUE << "RobotomyRequestForm parametric constructor called " << RESET << std::endl;
    _target = target;
}
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src): AForm(src)
{
    std::cout << BLUE << "RobotomyRequestForm copy constructor called " << RESET << std::endl;
    _target = src._target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs)
{
    std::cout << BLUE << "RobotomyRequestForm copy assignation operator called " << RESET << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->_isSigned = rhs.getState();
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(/* args */): AForm()
{
    // std::cout << BLUE << "RobotomyRequestForm constructor called " << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << BLUE << "RobotomyRequestForm destructor called " << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try{
        AForm::checkExecRequirements(executor);
    std::cout << "some drilling noise" << std::endl;
    std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;

    }catch(std::exception const & e){
        std::cout << "the robotomy failed" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }
}