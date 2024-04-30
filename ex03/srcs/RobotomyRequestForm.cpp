/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:49:39 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 09:56:29 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/RobotomyRequestForm.hpp"
#include <time.h>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(/* args */): AForm("RobotomyRequestForm", 0, 72, 45)
{
    // std::cout << BLUE << "RobotomyRequestForm constructor called " << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 0, 72, 45)
{
    std::cout << BLUE << "RobotomyRequestForm parametric constructor called " << RESET << std::endl;
    _target = target;
}
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src): AForm(src)
{
    std::cout << BLUE << "RobotomyRequestForm copy constructor called " << RESET << std::endl;
    _target = src._target;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs)
{
    std::cout << BLUE << "RobotomyRequestForm copy assignation operator called " << RESET << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->_isSigned = rhs.getState();
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << BLUE << "RobotomyRequestForm destructor called " << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
     if (!_isSigned)
        throw(AForm::FormNotSigned());
    else if (executor.getGrade() > _execGrade)
        throw(Bureaucrat::GradeTooLowException());
    else 
    {
        std::cout << GREEN <<"some drilling noise" << RESET <<std::endl;
        srand(time(NULL));
        int value = rand() % 2;
        if (value == 1)
            std::cout << GREEN << _target << " has been robotomized successfully"<< RESET << std::endl;
        else
            std::cout << RED << _target << ": Robotomy has failed"<< RESET << std::endl;
    }
}