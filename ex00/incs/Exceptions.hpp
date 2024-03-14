/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:59:12 by anouri            #+#    #+#             */
/*   Updated: 2024/03/14 16:11:33 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION
#define EXCEPTION

#include "Colors.hpp"
#include <exception>
#include <iostream>

class GradeTooHighException : public std::exception
{
public:
    using exception::what; //is this allowed?
    const char *what()
    {
        return("Grade too high");
    }
};

class GradeTooLowException : public std::exception
{
public:
    using exception::what; //is this allowed?
    const char *what()
    {
        return("Grade too low");
    }
};

#endif