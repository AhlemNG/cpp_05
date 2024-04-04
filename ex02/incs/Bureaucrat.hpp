/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:59 by anouri            #+#    #+#             */
/*   Updated: 2024/03/14 16:53:03 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
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
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &src);
        ~Bureaucrat();
        Bureaucrat &operator=(Bureaucrat const &rhs);
        void gradeIsTooHigh();
        void gradeIsTooLow();
        std::string const getName() const;
        int getGrade() const;


        class GradeTooHighException : public std::exception
    {
        public:
            using exception::what; //is this allowed?
            const char *what() const throw()
            {
                return("Grade too high");
            }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        using exception::what; //is this allowed?
        const char *what()const throw()
        {
            return("Grade too low");
        }
    };

        void promote();
        void demote();
        void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream & o,Bureaucrat const &rhs);

#endif