/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:26 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 09:48:28 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        const std::string getName() const;
        bool getState() const;
        int getSignGrade() const;
        int getExecGrade() const;
        class FormNotSigned : public std::exception
        {
        public:
            using exception::what; //is this allowed?
            const char *what() const throw();
        };

        void beSigned(Bureaucrat b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkExecRequirements(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream & o, AForm const &rhs);

#endif