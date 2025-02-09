#pragma once

#include <string>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _isSigned;
    public:
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &src);
        ~Form();
        Form &operator=(const Form &rhs);
        const std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat &bureaucrat);
        void execute(const Bureaucrat &executor) const;
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw(){
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

std::ostream &operator<<(std::ostream &o, Form const &src);
std::ostream &operator<<(std::ostream &o, Form::GradeTooHighException const &src);
std::ostream &operator<<(std::ostream &o, Form::GradeTooLowException const &src);