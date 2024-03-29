#include "../incs/Form.hpp"
#include "../incs/Exceptions.hpp"

Form::Form() : _name("no_name"), _isSigned(0), _signGrade(0), _execGrade(0)
{
    std::cout << RED << "Form default constructor called for: " << _name << std::endl;
}
Form::Form(const std::string name, bool isSigned, const int signGrade, const int execGrade): _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade)
{
   std::cout << RED << "Form parametric constructor called for: " << _name << std::endl;
    try{
        if (signGrade < 1)
            throw(GradeTooHighException());
        else if (signGrade > 150)
            throw(GradeTooLowException());
        if (execGrade < 1)
            throw(GradeTooHighException());
        else if (execGrade > 150)
            throw(GradeTooLowException());
    }catch(const std::exception &e)
    {
        std::cout << "EXCEPTION: " << e.what() << RESET << std::endl;
    }
}
Form::Form(Form const &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
    std::cout << RED << "Form copy constructor called for: " << _name << std::endl;
}
Form::~Form()
{
    std::cout << RED << "Form destructor called for: " << _name << std::endl;
}
Form & Form::operator=(Form const &rhs)
{
    std::cout << RED << "copy assignation operator called for: " << _name << std::endl;
    if(this != &rhs)
    {
        // _name = rhs._name;
        _isSigned = rhs._isSigned;
        // _signGrade = rhs._signGrade;
        // _execGrade = rhs._execGrade;
    }
    return (*this);
}

std::string const Form::getName() const
{
    return(_name);
}
bool Form::getState() const
{
    return (_isSigned);
}
int Form::getSignGrade() const
{
    return (_signGrade);
}
int Form::getExecGrade() const
{
    return (_execGrade);
}

std::ostream & operator>>(std::ostream & o, Form const &rhs)
{
    o << BLUE << rhs.getName() << ", Form " << rhs.getSignGrade() << rhs.getExecGrade() << "." << RESET << std::endl;
    return o;
}