#include "../incs/Intern.hpp"
#include "../incs/Colors.hpp"
#include <string>

Intern::Intern(/* args */)
{
    std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::~Intern()
{
    std::cout << YELLOW << "destructor called for Intern" << RESET << std::endl;
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

const char *Intern::NotAvalidFormName::what() const throw(){
    return ("Intern::Not a valid form name");
}

AForm *Intern::makeForm(std::string const name, std::string const target)
{

    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    for(int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            switch (i)
            {
                case 0:
                    std::cout << GRAY << "Intern creates " << name << RESET << std::endl;
                    return(new ShrubberyCreationForm(target));
                case 1:
                        std::cout << GRAY << "Intern creates " << name << RESET << std::endl;
                        return(new RobotomyRequestForm(target));
                case 2:
                        std::cout << GRAY << "Intern creates " << name << RESET << std::endl;
                        return(new PresidentialPardonForm(target));
                default:
                    break;
            }
        }
    }
    throw(NotAvalidFormName());
    return (NULL);
}