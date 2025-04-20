#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _isSigned;

    public:
        // Constructors / Destructor
        AForm(const std::string &name, int signGrade, int execGrade);
        AForm(const AForm &src);
        AForm();
        virtual ~AForm();
        AForm &operator=(const AForm &rhs);

        // Accessors
        const std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool isSigned() const;

        // Main methods
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Grade too high.";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Grade too low.";
                }
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Form is not signed.";
                }
        };
};

// Operator overload
std::ostream &operator<<(std::ostream &o, AForm const &src);