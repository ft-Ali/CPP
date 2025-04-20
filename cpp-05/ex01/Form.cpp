#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
    if (signGrade < 1 || execGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form()
    : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) {}

Form::~Form() {}

Form::Form(const Form &src)
    : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned) {}

const std::string Form::getName() const {
    return this->_name;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecGrade() const {
    return this->_execGrade;
}

bool Form::isSigned() const {
    return this->_isSigned;
}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade) {
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
}

void Form::execute(const Bureaucrat &executor) const {
    if (!this->_isSigned) {
        throw Form::FormNotSignedException();
    }
    if (executor.getGrade() > this->_execGrade) {
        throw Form::GradeTooLowException();
    }
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}


std::ostream &operator<<(std::ostream &o, Form const &src) {
    return o << "Form: " << src.getName() << ", sign grade: " << src.getSignGrade() << ", exec grade: " << src.getExecGrade() << ", signed: " << (src.isSigned() ? "yes" : "no");
}

std::ostream &operator<<(std::ostream &o, Form::GradeTooHighException const &src) {
    return o << src.what();
}

std::ostream &operator<<(std::ostream &o, Form::GradeTooLowException const &src) {
    return o << src.what();
}