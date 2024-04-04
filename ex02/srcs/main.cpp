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

#include "../incs/Bureaucrat.hpp"
#include "../incs/AForm.hpp"
#include "../incs/ShrubberyCreationForm.hpp"
#include "../incs/RobotomyRequestForm.hpp"
#include "../incs/PresidentialPardonForm.hpp"


#include <iostream>

int main()
{
//     std::cout << YELLOW << "*****************CREATE INVALID****************" << RESET << std::endl;
    
//     Bureaucrat C("invalid", 170);
//     std::cout <<  "PDG : \n" << C << std::endl;
//     Bureaucrat B("DGA", -1);
//     std::cout <<  "DGA : \n" << B << std::endl;

//     std::cout << YELLOW << "*****************PROMOTE DEMOTE*****************" << RESET << std::endl;
    
//     Bureaucrat A("PDG", 1);
//     std::cout << GRAY << "PDG : \n" << A << std::endl;
//     A.promote();
//     std::cout <<  "PDG : \n" << A << std::endl;

//     A.demote();
//     std::cout <<  "PDG : \n" << A << std::endl;

//     A.promote();
//     std::cout <<  "PDG : \n" << A << std::endl;

//     std::cout << YELLOW << "*****************COPY CONSTRUCTOR*****************" << RESET << std::endl;
//     Bureaucrat E(A);
//     std::cout <<  "copy : \n" << E << std::endl;
//     E.demote();
//     std::cout <<  "copy : \n" << E << std::endl;
//     std::cout <<  "PDG : \n" << A << std::endl;

//     std::cout << YELLOW << "*****************ASSIGNMENT OPERATOR*****************" << RESET << std::endl;
//     Bureaucrat F("assistante de direction", 15);
//     E = F;
//     std::cout <<  "E : \n" << E << std::endl;
//     std::cout <<  "F : \n" << F << std::endl;

    Bureaucrat PDG("PDG", 1);
    Bureaucrat DRH("DRH", 4);
    Bureaucrat Archiviste("Archiviste", 10);

    // std::cout << YELLOW << "\n*****************invalid FORM*****************\n" << RESET << std::endl;
    // Form demission("demission",0, 0, 4);
    // Form attestationTravail("Attestation de travail",0, 4, 170);

    // std::cout << YELLOW << "\n*****************CONSTRUCTION*****************\n" << RESET << std::endl;
    // Form congé("congé",0, 5, 5);
    // Form congè(congé);
    // std::cout << congé << std::endl;
    // std::cout << YELLOW << "\n*****************beSIgned*****************\n" << RESET << std::endl;

    // congé.beSigned(Archiviste);
    // congé.beSigned(PDG);
    ShrubberyCreationForm shrubbery("home");
    // shrubbery.beSigned(PDG);
    shrubbery.execute(PDG);
    return(0);
}