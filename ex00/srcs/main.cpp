/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:50 by anouri            #+#    #+#             */
/*   Updated: 2024/03/14 16:46:01 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat A("moudir", 5);
    std::cout << YELLOW << "*****************TEST*****************" << RESET << std::endl;
    std::cout << GRAY << "moudir : \n" << A << std::endl;
    
    A.promote();
    std::cout <<  "moudir : \n" << A << std::endl;

    A.demote();
    std::cout <<  "moudir : \n" << A << std::endl;

    std::cout << YELLOW << "*****************TEST*****************" << RESET << std::endl;
    Bureaucrat B("Idou Lissar", 0);
    return(0);
}