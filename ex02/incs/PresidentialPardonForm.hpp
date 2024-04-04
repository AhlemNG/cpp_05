#ifndef PRESIDENTIALPARDONFORM_hpp
#define PRESIDENTIALPARDONFORM_hpp

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm: public AForm
{
private:
    /* data */
    std::string _target;
    PresidentialPardonForm(/* args */);
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
    ~PresidentialPardonForm();
    virtual void execute(Bureaucrat const & executor) const;
};


#endif