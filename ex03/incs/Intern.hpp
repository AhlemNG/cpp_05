/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:33:01 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 12:40:56 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        /* data */
    public:
        Intern(/* args */);
        Intern(const Intern &src);
        Intern &operator=(const Intern &rhs);
        ~Intern();

      class NotAvalidFormName : public std::exception
        {
            public:
            using exception::what; //is this allowed?
            const char *what() const throw();
        };
        AForm *makeForm(std::string const name, std::string const target);
};


#endif