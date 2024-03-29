/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:55 by anouri            #+#    #+#             */
/*   Updated: 2024/03/19 16:00:49 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include <exception>
Bureaucrat::Bureaucrat() : _name("no_name"), _grade(0)
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
            throw(GradeTooLowException());
        if (grade < 1)
            throw(GradeTooHighException());
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

void Bureaucrat::promote()
{
    try{
        if (_grade == 1)
            throw(GradeTooHighException());
        this->_grade--;
    }catch(const std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    // std::cout << GREEN << this->_name << " has been promoted" << RESET<< std::endl;
}

void Bureaucrat::demote()
{
    try{
        if (_grade == 150)
            throw(GradeTooLowException());
        this->_grade++;
    }catch(const std::exception &e){
        std::cout << "Exception: " << e.what()<< std::endl;
    }
    // std::cout << LRED << this->_name << " has been demoted" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream & o, Bureaucrat const &rhs)
{
    o << BLUE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
    return o;
}
