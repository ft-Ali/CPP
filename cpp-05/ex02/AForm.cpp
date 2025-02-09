#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &src)
    : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

const std::string AForm::getName() const {
    return _name;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

bool AForm::isSigned() const {
    return _isSigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed.";
}

std::ostream &operator<<(std::ostream &o, AForm const &form) {
    o << "Form: " << form.getName()
      << ", sign grade: " << form.getSignGrade()
      << ", exec grade: " << form.getExecGrade()
      << ", signed: " << (form.isSigned() ? "yes" : "no");
    return o;
}
