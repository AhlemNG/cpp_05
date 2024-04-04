#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
        /* data */
        const std::string _name;
        bool    _isSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        AForm(); // default constructor
        AForm(const std::string name, bool isSigned, const int _signGrade, const int exec_grade); //param constructor
        AForm(AForm const &src); //copy constructor
        virtual ~AForm(); //destructor
        AForm &operator=(AForm const &rhs); //assignation operator
        const std::string getName() const;
        bool getState() const;
        int getSignGrade() const;
        int getExecGrade() const;
        class FormNotSigned : public std::exception
        {
        public:
            using exception::what; //is this allowed?
            const char *what() const throw()
            {
                return("Form is not signed");
            }
        };

        void beSigned(Bureaucrat b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkExecRequirements(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream & o, AForm const &rhs);

#endif