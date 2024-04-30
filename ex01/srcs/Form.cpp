/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:13 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 09:48:15 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Form.hpp"

Form::Form() : _name("no_name"), _isSigned(0), _signGrade(1), _execGrade(1)
{
    std::cout << LBLUE << "Form default constructor called for: " << _name << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int signGrade, const int execGrade): _name(name), _isSigned(isSigned), _signGrade(signGrade), _execGrade(execGrade)
{
   std::cout << LBLUE << "Form parametric constructor called for: " << _name << std::endl;
    try{
        if (signGrade < 1)
            throw(Form::GradeTooHighException());
        else if (signGrade > 150)
            throw(Form::GradeTooLowException());
        if (execGrade < 1)
            throw(Form::GradeTooHighException());
        else if (execGrade > 150)
            throw(Form::GradeTooLowException());
    }catch(const std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}
Form::Form(Form const &src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
    std::cout << LBLUE << "Form copy constructor called for: " << _name << std::endl;
}
Form::~Form()
{
    std::cout << LBLUE << "Form destructor called for: " << _name << std::endl;
}
Form & Form::operator=(Form const &rhs)
{
    std::cout << LBLUE << "copy assignation operator called for: " << _name << std::endl;
    if(this != &rhs)
    {
        // _name = rhs._name;
        _isSigned = rhs._isSigned;
        // _signGrade = rhs._signGrade;
        // _execGrade = rhs._execGrade;
    }
    return (*this);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return("Form::Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return("Form::Grade too low");
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

std::ostream & operator<<(std::ostream & o, Form const &rhs)
{
    o << GRAY "Form " <<  rhs.getName() << ", isSigned = " << rhs.getState() << ", signGrade = " << rhs.getSignGrade() << ", execGrade = " <<rhs.getExecGrade() << "." << RESET << std::endl;
    return o;
}

void Form::beSigned(Bureaucrat b)
{
    if (b.getGrade() > _signGrade)
        throw(Bureaucrat::GradeTooLowException());
    _isSigned = 1;
    std::cout << GREEN << b.getName() << " signed " << _name << RESET << std::endl;
}