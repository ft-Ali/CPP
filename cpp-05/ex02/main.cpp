#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);      // Grade le plus haut
        Bureaucrat bob("Bob", 45);         // Suffisant pour robotomy
        Bureaucrat charlie("Charlie", 140); // Suffisant juste pour shrubbery
        Bureaucrat dave("Dave", 150);      // Trop bas pour tout

        std::cout << "\n-- Creating Forms --\n";
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n-- Signing Forms --\n";
        charlie.signForm(shrub); // OK
        bob.signForm(robot);     // OK
        alice.signForm(pardon);  // OK

        std::cout << "\n-- Executing Forms --\n";
        charlie.executeForm(shrub); // OK
        bob.executeForm(robot);     // OK
        alice.executeForm(pardon);  // OK

        std::cout << "\n-- Failures --\n";
        dave.signForm(pardon);      // FAIL
        dave.executeForm(shrub);    // FAIL
        shrub.beSigned(dave);       // FAIL

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
