/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:59 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 09:54:10 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        /* data */
        std::string const _name;   
        int _grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        std::string const getName() const;
        int getGrade() const;
        void promote();
        void demote();
        class GradeTooHighException : public std::exception
        {
            public:
            using exception::what; //is this allowed?
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
            using exception::what; //is this allowed?
            const char *what()const throw();
        };
        void signForm(AForm &form);
        void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream & o,Bureaucrat const &rhs);

#endif