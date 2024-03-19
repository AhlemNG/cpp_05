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
Bureaucrat::Bureaucrat() //init to 0?
{
    std::cout << BLUE << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << BLUE << "Bureaucrat destructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    std::cout << BLUE << "Bureaucrat parametric constructor called for : " << this->name << RESET << std::endl;
    try{
        gradeIsTooLow();
    }catch(GradeTooLowException & e){
        std::cerr << "Exception: " << e.what() << '\n';
    }
    try{
        gradeIsTooHigh();
    }catch(GradeTooHighException & e){
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): name(src.name), grade(src.grade)
{
    std::cout << BLUE << "Bureaucrat copy constructor called for : " << this->name << RESET << std::endl;
}

//name is constant, once class is instatiated , it cannot be changed
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        this->grade = rhs.grade;
    return(*this);
}

std::string const Bureaucrat::getName() const
{
    return(this->name);
}
int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void  Bureaucrat::gradeIsTooLow()
{
    if(this->grade > 150)
        throw(GradeTooLowException());
}


void  Bureaucrat::gradeIsTooHigh()
{
    if(this->grade < 1)
        throw(GradeTooHighException());
}


void Bureaucrat::promote()
{
    this->grade--;
    try{
        gradeIsTooHigh();
    }catch(GradeTooHighException &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << GREEN << this->name << " has been promoted" << RESET<< std::endl;
}

void Bureaucrat::demote()
{
    this->grade++;
    try{
        gradeIsTooLow();
    }catch( GradeTooLowException &e){
        std::cout << "Exception: " << e.what()<< std::endl;
    }
    std::cout << LRED << this->name << " has been demoted" << RESET << std::endl;
}

// const char *Bureaucrat::GradeTooHighException::what(){
//     return "Grade too high";
// }

// catch(std::exception & e){
//     std::cout << e.what() << std::endl;
// }





std::ostream &operator<<(std::ostream & o, Bureaucrat const &rhs)
{
    o << BLUE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
    return o;
}
