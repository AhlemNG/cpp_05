/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:50 by anouri            #+#    #+#             */
/*   Updated: 2024/03/19 16:01:54 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << YELLOW << "*****************CREATE INVALID****************" << RESET << std::endl;
    
    Bureaucrat C("invalid", 170);
    std::cout <<  "PDG : \n" << C << std::endl;
    Bureaucrat B("DGA", -1);
    std::cout <<  "DGA : \n" << B << std::endl;


    std::cout << YELLOW << "*****************PROMOTE DEMOTE*****************" << RESET << std::endl;
    
    Bureaucrat A("PDG", 1);
    std::cout << GRAY << "PDG : \n" << A << std::endl;
    A.promote();
    std::cout <<  "PDG : \n" << A << std::endl;

    A.demote();
    std::cout <<  "PDG : \n" << A << std::endl;

    A.promote();
    std::cout <<  "PDG : \n" << A << std::endl;

    std::cout << YELLOW << "*****************COPY CONSTRUCTOR*****************" << RESET << std::endl;
    Bureaucrat E(A);
    std::cout <<  "copy : \n" << E << std::endl;
    E.demote();
    std::cout <<  "copy : \n" << E << std::endl;
    std::cout <<  "PDG : \n" << A << std::endl;

    std::cout << YELLOW << "*****************ASSIGNMENT OPERATOR*****************" << RESET << std::endl;
    Bureaucrat F("assistante de direction", 15);
    E = F;
    std::cout <<  "E : \n" << E << std::endl;
    std::cout <<  "F : \n" << F << std::endl;

    return(0);
}