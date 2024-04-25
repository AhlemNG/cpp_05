/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:50 by anouri            #+#    #+#             */
/*   Updated: 2024/04/25 17:48:26 by anouri           ###   ########.fr       */
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


    Bureaucrat PDG("PDG", 1);
    Bureaucrat DRH("DRH", 4);
    Bureaucrat Archiviste("Archiviste", 10);

    ShrubberyCreationForm shrubbery("home");
    PDG.signForm(shrubbery);
    PDG.executeForm(shrubbery);
    RobotomyRequestForm rob("ggg");
    PDG.executeForm(rob);
    DRH.signForm(rob);
    PDG.executeForm(rob);
    PresidentialPardonForm L1995("blabla");
    Bureaucrat President("President", 1);
    President.signForm(L1995);
    President.executeForm(L1995);
    return(0);
}