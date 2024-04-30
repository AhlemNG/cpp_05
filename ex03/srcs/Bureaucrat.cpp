/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:55 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 12:55:06 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat() : _name("no_name"), _grade(1)
{
    std::cout << BLUE << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << YELLOW << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    _grade = grade;
    std::cout << BLUE << "Bureaucrat parametric constructor called for : " << this->_name << RESET << std::endl;
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
    return("Bureaucrat::Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat::Grade too low");
}

void Bureaucrat::promote()
{
    try{
        if (_grade == 1)
            throw(Bureaucrat::GradeTooHighException());
        this->_grade--;
    }catch(const std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

void Bureaucrat::demote()
{
    try{
        if (_grade == 150)
            throw(Bureaucrat::GradeTooLowException());
        this->_grade++;
    }catch(const std::exception &e){
        std::cout << e.what()<< std::endl;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
    
}

void Bureaucrat::executeForm(AForm const & form)
{
    try{
        form.execute(*this);
        std::cout << LCYAN << _name << " executed " << form.getName() << RESET << std::endl;
    }catch(std::exception const &e){
        std::cout<< RED << _name << " could not execute Form" << RESET << std::endl;
        std::cout << RED << form.getName() << " Exception : "<< e.what() << RESET << std::endl;
    }
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const &rhs)
{
    o << BLUE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
    return o;
}
