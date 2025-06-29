#pragma once 

#include <string>
#include <iostream>
class AForm;

class Bureaucrat {
        private:
            std::string const _name;
            int _grade;
        public:
            Bureaucrat();
            Bureaucrat(std::string const name, int grade);
            Bureaucrat(Bureaucrat const & src);
            Bureaucrat & operator=(Bureaucrat const & src);
            ~Bureaucrat();
            std::string getName() const;
            int getGrade() const;
            void incrementGrade();
            void decrementGrade();
            void signForm(AForm  & form);
            void executeForm(AForm const & form) const;
            class GradeTooHighException : public std::exception {
                public:
                    virtual const char* what() const throw();
            };
            class GradeTooLowException : public std::exception {
                public:
                    virtual const char* what() const throw();
            };
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src);
std::ostream & operator<<(std::ostream & o, Bureaucrat::GradeTooHighException const & src);
std::ostream & operator<<(std::ostream & o, Bureaucrat::GradeTooLowException const & src);