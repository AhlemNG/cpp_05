#include "../incs/Intern.hpp"
#include "../incs/Colors.hpp"

Intern::Intern(/* args */)
{
    std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::~Intern()
{
    // std::cout << "destructor called for Intern" << std::endl;
}

Intern::Intern(const Intern &src)
{
    *this = src;
}
Intern &Intern::operator=(const Intern &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return(*this);
}

AForm *Intern::makeForm(std::string const name, std::string const target)
{
    switch (name[0])
    {
    case 'S':
    try{

        if (name.compare("ShrubberyCreationForm"))
            throw(AForm::NotvalidArgument());
        std::cout << "Intern creates" << name << RESET << std::endl;
        return(new ShrubberyCreationForm(target));
    }catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    case 'R':
        try
        {
            if (name.compare("RobotomyReqUestForm"))
                throw(AForm::NotvalidArgument());
            std::cout << "Intern creates" << name << RESET << std::endl;
            return(new RobotomyRequestForm(target));

        }catch(const std::exception &e)
        {
        std::cerr << e.what() << std::endl;
        }
    case 'P':
        try
        {
            if (name.compare("PresidentialPardonForm"))
                throw(AForm::NotvalidArgument());
            std::cout << "Intern creates" << name << RESET << std::endl;
            return(new PresidentialPardonForm(target));
        }catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }    
    default:
        break;
    }
    return (NULL);
}