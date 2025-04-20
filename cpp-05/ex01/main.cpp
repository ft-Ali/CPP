#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "===== Test 1: Bureaucrat can sign but cannot execute =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        Form formA("FormA", 100, 20); // Bob peut signer (50 < 100) mais pas exécuter (50 > 20)
        bob.signForm(formA);
        formA.execute(bob);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 2: Bureaucrat cannot sign (grade too low) =====" << std::endl;
    try {
        Bureaucrat alice("Alice", 120);
        Form formB("FormB", 100, 100);
        alice.signForm(formB); // Doit échouer
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 3: Bureaucrat can sign and execute =====" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 10);
        Form formC("FormC", 20, 10);
        charlie.signForm(formC);
        formC.execute(charlie); // Doit marcher
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 4: Execute without signing =====" << std::endl;
    try {
        Bureaucrat dave("Dave", 1);
        Form formD("FormD", 1, 1);
        formD.execute(dave); // Pas signé → exception
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
