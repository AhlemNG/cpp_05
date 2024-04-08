#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        /* data */
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm( RobotomyRequestForm const &src);
        RobotomyRequestForm & operator=( RobotomyRequestForm const &rhs);
        ~RobotomyRequestForm();
        virtual void execute(Bureaucrat const & executor) const;
};

#endif