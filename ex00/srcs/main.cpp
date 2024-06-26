/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:50 by anouri            #+#    #+#             */
/*   Updated: 2024/04/25 16:58:53 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << YELLOW << "*****************CREATE INVALID****************" << RESET << std::endl;
    try
    {
        Bureaucrat C("PDG", 170);
        std::cout <<  "PDG : \n" << C << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat B("DGA", -1);
        std::cout <<  "DGA : \n" << B << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << YELLOW << "*****************DEFAULT CONSTRUCTOR****************" << RESET << std::endl;
    Bureaucrat c = Bureaucrat();
    std::cout <<  "c : \n" << c << std::endl;
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