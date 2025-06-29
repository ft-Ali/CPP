#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) {}

void Bureaucrat::incrementGrade() {
    if (_grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const Form::GradeTooLowException &e) {
        std::cerr << this->_name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src) {
    if (this != &src) {
        this->_grade = src._grade;
    }
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & src) {
    return o << src.getName() << ", bureaucrat grade " << src.getGrade();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat::GradeTooHighException const & src) {
    return o << src.what();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat::GradeTooLowException const & src) {
    return o << src.what();
}
