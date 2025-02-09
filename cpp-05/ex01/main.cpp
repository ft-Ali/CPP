#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "===== Test 1: Creating and displaying a valid Bureaucrat =====" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 2: Creating a Bureaucrat with an excessively high grade =====" << std::endl;
    try {
        Bureaucrat alice("Alice", 0); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 3: Bureaucrat signing a Form =====" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 10);
        Form formA("FormA", 15, 50);

        std::cout << formA << std::endl;
        formA.beSigned(charlie); // Should succeed
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 4: Executing a signed and unsigned Form =====" << std::endl;
    try {
        Bureaucrat dave("Dave", 5);
        Form formB("FormB", 10, 5);

        std::cout << formB << std::endl;
        formB.beSigned(dave); // Should succeed
        std::cout << formB << std::endl;
        formB.execute(dave);  // Should also succeed
        std::cout << "Form executed successfully" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 5: Bureaucrat with low grade trying to sign a Form =====" << std::endl;
    try {
        Bureaucrat eve("Eve", 20);
        Form formC("FormC", 10, 5);

        std::cout << formC << std::endl;
        formC.beSigned(eve); // Should fail
        std::cout << formC << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== Test 6: Bureaucrat with low grade trying to execute a Form =====" << std::endl;
    try {
        Bureaucrat frank("Frank", 10);
        Form formD("FormD", 5, 5);

        std::cout << formD << std::endl;
        formD.beSigned(frank);
        std::cout << formD << std::endl;
        formD.execute(frank);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

        std::cout << "\n===== Test 7: Executing an unsigned form =====" << std::endl;
    try {
        Bureaucrat george("George", 1);
        Form formE("FormE", 10, 5);

        std::cout << formE << std::endl;
        formE.execute(george); // should fail cus form is not signed
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}