#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
    private:
        /* data */
        const std::string _name;
        bool    _isSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        Form(); // default constructor
        Form(const std::string name, bool isSigned, const int _signGrade, const int exec_grade); //param constructor
        Form(Form const &src); //copy constructor
        ~Form(); //destructor
        Form &operator=(Form const &rhs); //assignation operator

        const std::string getName() const;
        bool getState() const;
        int getSignGrade() const;
        int getExecGrade() const;
};

std::ostream &operator>>(std::ostream & o, Form const &rhs);

#endif