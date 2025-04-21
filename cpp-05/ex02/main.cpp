#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);

        ShrubberyCreationForm treeForm("garden");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Rick");

        std::cout << "\n--- Signing forms ---" << std::endl;
        boss.signForm(treeForm);
        boss.signForm(robotForm);
        boss.signForm(pardonForm);

        std::cout << "\n--- Executing forms ---" << std::endl;
        boss.executeForm(treeForm);
        boss.executeForm(robotForm);
        boss.executeForm(pardonForm);

        std::cout << "\n--- Done ---" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
