/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:50 by anouri            #+#    #+#             */
/*   Updated: 2024/04/25 17:38:18 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Bureaucrat.hpp"
#include "../incs/Form.hpp"

#include <iostream>

int main()
{
    Bureaucrat PDG("PDG", 1);
    Bureaucrat DRH("DRH", 4);
    Bureaucrat Archiviste("Archiviste", 10);

    std::cout << YELLOW << "\n*****************invalid FORM*****************\n" << RESET << std::endl;
    Form demission("demission",0, 0, 4);
    Form attestationTravail("Attestation de travail",0, 4, 170);

    std::cout << YELLOW << "\n*****************CONSTRUCTION*****************\n" << RESET << std::endl;
    
    Form vacation("congé",0, 5, 5);
    Form vacation1(vacation);
    std::cout << vacation << std::endl;
    std::cout << vacation1 << std::endl;
    std::cout << YELLOW << "\n*****************beSIgned*****************\n" << RESET << std::endl;
    
    Archiviste.signForm(vacation);
    PDG.signForm(vacation);
    std::cout << vacation << std::endl;
    std::cout << vacation1 << std::endl;
    DRH.signForm(vacation1);
    return(0);
}