#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(0)); // init aléatoire une seule fois
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor); // check form signed + grade

    std::cout << "* VRRRRRRRRRRRR *" << std::endl;

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully ✅" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << " ❌" << std::endl;
}
