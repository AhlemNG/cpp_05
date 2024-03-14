/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:55 by anouri            #+#    #+#             */
/*   Updated: 2024/03/14 16:54:08 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

Bureaucrat::Bureaucrat() //init to 0?
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    try{
        gradeIsTooLow();
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    try{
        gradeIsTooHigh();
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): name(src.name), grade(src.grade)
{
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

void Bureaucrat::promote()
{
    this->grade--;
    try{
        gradeIsTooHigh();
    }catch(int i){
        std::cout << "too high\n";
        return;
    }
    std::cout << GREEN << this->name << " has been promoted" << RESET<< std::endl;
}

void  Bureaucrat::gradeIsTooLow()
{
    if(this->grade > 150)
        throw(this->grade);
}


void  Bureaucrat::gradeIsTooHigh()
{
    if(this->grade < 1)
        throw(this->grade);
}

void Bureaucrat::demote()
{
    this->grade++;
    try{
        gradeIsTooLow();
    }catch(int i){
        std::cout << "too low\n";
        return;
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
