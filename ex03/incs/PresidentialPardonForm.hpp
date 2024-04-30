/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:48:50 by anouri            #+#    #+#             */
/*   Updated: 2024/04/30 09:54:35 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_hpp
#define PRESIDENTIALPARDONFORM_hpp

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm: public AForm
{
private:
    /* data */
    std::string _target;
    PresidentialPardonForm(/* args */);
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const & src);
    PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
    ~PresidentialPardonForm();
    virtual void execute(Bureaucrat const & executor) const;
};


#endif