/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:55 by anouri            #+#    #+#             */
/*   Updated: 2024/04/08 13:37:17 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat() : _name("no_name"), _grade(1)
{
    std::cout << BLUE << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << BLUE << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << BLUE << "Bureaucrat parametric constructor called for : " << this->_name << RESET << std::endl;
    try{
        if (grade > 150)
            throw(Bureaucrat::GradeTooLowException());
        if (grade < 1)
            throw(Bureaucrat::GradeTooHighException());
    _grade = grade;
    }catch(const std::exception & e){
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name), _grade(src._grade)
{
    std::cout << BLUE << "Bureaucrat copy constructor called for : " << this->_name << RESET << std::endl;
}

//name is constant, once class is instantiated , it cannot be changed
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->_grade = rhs._grade;
    return(*this);
}

std::string const Bureaucrat::getName() const
{
    return(this->_name);
}
int Bureaucrat::getGrade() const
{
    return(this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
     return("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
     return("Grade too low");
}

void Bureaucrat::promote()
{
    try{
        if (_grade == 1)
            throw(Bureaucrat::GradeTooHighException());
        this->_grade--;
    }catch(const std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Bureaucrat::demote()
{
    try{
        if (_grade == 150)
            throw(Bureaucrat::GradeTooLowException());
        this->_grade++;
    }catch(const std::exception &e){
        std::cout << "Exception: " << e.what()<< std::endl;
    }
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << RED << this->getName() << " couldn't sign " << _name << " because " << e.what() << RESET << std::endl;
    }
    
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const &rhs)
{
    o << BLUE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
    return o;
}
