#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    Intern someRandomIntern;

    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
    AForm* unknown = someRandomIntern.makeForm("coffee form", "Nobody");

    Bureaucrat bob("Bob", 1);

    std::cout << std::endl;

    if (shrub) {
        try {
            shrub->beSigned(bob);
            shrub->execute(bob);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete shrub;
    }

    if (robot) {
        try {
            robot->beSigned(bob);
            robot->execute(bob);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete robot;
    }

    if (pardon) {
        try {
            pardon->beSigned(bob);
            pardon->execute(bob);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete pardon;
    }

    if (unknown) {
        delete unknown;
    }

    return 0;
}
