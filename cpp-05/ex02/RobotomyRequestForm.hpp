#pragma once

#include "AForm.hpp"
#include <cstdlib>  // Pour rand()
#include <ctime>    // Pour time()
#include <iostream>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    void execute(Bureaucrat const &executor) const;
};
