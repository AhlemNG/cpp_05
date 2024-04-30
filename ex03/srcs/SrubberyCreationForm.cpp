/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SrubberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:49:46 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 13:10:26 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 0, 145, 137)
{
    std::cout << BLUE << "ShrubberyCreationForm  default constructor called for target " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 0, 145, 137)
{
    _target = target;
    std::cout << BLUE << "ShrubberyCreationForm parametric constructor called for: " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << YELLOW << "ShrubberyCreationForm destructor called for: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src): AForm(src)
{
    _target = src._target;
    std::cout << BLUE << "ShrubberyCreationForm  copy constructor called for: " << _target << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) // copy assignation operator
{
    std::cout << BLUE << "ShrubberyCreationForm  copy assignation operator called for: " << _target << std::endl;
    if (this != &rhs)
    {
        _target = rhs._target;
        this->_isSigned = rhs.getState();
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!_isSigned)
        throw(AForm::FormNotSigned());
    else if (executor.getGrade() > _execGrade)
        throw(Bureaucrat::GradeTooLowException());
    else 
    {
        std::ofstream file((_target + "_shrubbery").c_str());
        if(!file.is_open())
        {
            std::cout << "error file" << std::endl;
        }
        file << "      _-_" << std::endl;
        file << "  /~~      ~~\\" << std::endl;
        file << " /~~        ~~\\" << std::endl;
        file << "{              }" << std::endl;
        file << " \\  _-    -_ /" << std::endl;
        file << "   ~  \\  /  ~" << std::endl;
        file << "  _- - | | - -_" << std::endl;
        file << "   _-  | |  -_" << std::endl;
        file << "       / \\" << std::endl;

        file.close(); 
    }
}
