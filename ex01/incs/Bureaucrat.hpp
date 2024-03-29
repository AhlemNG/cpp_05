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
    std::string const getName() const;
    void gradeIsTooHigh();
    void gradeIsTooLow();
    int getGrade() const;
    void promote();
    void demote();
};

std::ostream &operator<<(std::ostream & o,Bureaucrat const &rhs);

#endif