#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
        ShrubberyCreationForm(); //default constructor => it is protected so it can be inherited by eventual children :D
    public:
        ~ShrubberyCreationForm();// destructor
        ShrubberyCreationForm(const ShrubberyCreationForm &src); // copy constructor
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm &rhs); // copy assignation operator
        ShrubberyCreationForm(std::string target); // parametric constructor
        virtual void execute(Bureaucrat const & executor) const;
};


#endif