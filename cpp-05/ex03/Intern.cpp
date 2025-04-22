#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &other) {
    (void)other;
}
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

typedef AForm* (*FormCreator)(const std::string &target);

static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cerr << "Intern couldn't find form: " << formName << std::endl;
    return NULL;
}
