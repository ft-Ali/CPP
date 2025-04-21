#pragma once

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    void execute(Bureaucrat const &executor) const;
};
