/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:47:56 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 12:34:30 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "../incs/Bureaucrat.hpp"
#include <exception>

class Bureaucrat;

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
        void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream & o, Form const &rhs);

#endif