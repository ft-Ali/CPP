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
        AForm(const std::string &name, int signGrade, int execGrade);
        virtual ~AForm();
        AForm(const AForm &src);
        AForm &operator=(const AForm &rhs);
        
        const std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat &bureaucrat);
        
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, AForm const &src);