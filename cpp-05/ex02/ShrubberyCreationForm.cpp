#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

// Constructor / Destructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

// Execute
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Failed to open output file" << std::endl;
        return;
    }

    outfile << "       _-_      \n"
            << "    /~~   ~~\\   \n"
            << " /~~         ~~\\ \n"
            << "{               }\n"
            << " \\  _-     -_  / \n"
            << "   ~  \\\\ //  ~   \n"
            << "_- -   | | _- _  \n"
            << "  _ -  | |   -_  \n"
            << "      // \\\\      \n";

    outfile.close();
}
