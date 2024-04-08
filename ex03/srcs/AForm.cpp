#include "../incs/AForm.hpp"

AForm::AForm() : _name("no_name"), _isSigned(0), _signGrade(0), _execGrade(0)
{
    std::cout << LBLUE << "AForm default constructor called for: " << _name << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, const int signGrade, const int execGrade): _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade)
{
   std::cout << LBLUE << "AForm parametric constructor called for: " << _name << std::endl;
    try{
        if (signGrade < 1)
            throw(Bureaucrat::GradeTooHighException());
        else if (signGrade > 150)
            throw(Bureaucrat::GradeTooLowException());
        if (execGrade < 1)
            throw(Bureaucrat::GradeTooHighException());
        else if (execGrade > 150)
            throw(Bureaucrat::GradeTooLowException());
    }catch(const std::exception &e)
    {
        std::cout << RED << "EXCEPTION: " << e.what() << RESET << std::endl;
    }
}
AForm::AForm(AForm const &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
    std::cout << LBLUE << "AForm copy constructor called for: " << _name << std::endl;
}
AForm::~AForm()
{
    std::cout << LBLUE << "AForm destructor called for: " << _name << std::endl;
}
AForm & AForm::operator=(AForm const &rhs)
{
    std::cout << LBLUE << "copy assignation operator called for: " << _name << std::endl;
    if(this != &rhs)
    {
        // _name = rhs._name;
        _isSigned = rhs.getSignGrade();
        // _signGrade = rhs._signGrade();
        // _execGrade = rhs._execGrade();
    }
    return (*this);
}

std::string const AForm::getName() const
{
    return(_name);
}
bool AForm::getState() const
{
    return (_isSigned);
}
int AForm::getSignGrade() const
{
    return (_signGrade);
}
int AForm::getExecGrade() const
{
    return (_execGrade);
}

const char *AForm::FormNotSigned::what() const throw()
{
    return("Form is not signed");
}

std::ostream & operator<<(std::ostream & o, AForm const &rhs)
{
    o << GRAY "AForm " <<  rhs.getName() << ", isSigned = " << rhs.getState() << ", signGrade = " << rhs.getSignGrade() << ", execGrade = " <<rhs.getExecGrade() << "." << RESET << std::endl;
    return o;
}


void AForm::beSigned(Bureaucrat b)
{
    if (b.getGrade() > _signGrade)
        throw(Bureaucrat::GradeTooLowException());
    _isSigned = 1;
    std::cout << GREEN << b.getName() << " signed " << _name << RESET << std::endl;
}

void AForm::checkExecRequirements(Bureaucrat const & executor) const 
{
    if (!_isSigned)
        throw(AForm::FormNotSigned());
    if (executor.getGrade() > _execGrade)
        throw(Bureaucrat::GradeTooLowException());
    std::cout << "check is ok\n";
}

const char *AForm::NotvalidArgument::what() const throw()
{
    return "not a valid argument";
}