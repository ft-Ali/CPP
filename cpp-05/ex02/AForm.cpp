#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors / Destructor
AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
    if (_signGrade < 1 || _execGrade < 1)
        throw AForm::GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm()
    : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) {}

AForm::AForm(const AForm &src)
    : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

// Accessors
const std::string AForm::getName() const { return _name; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecGrade() const { return _execGrade; }

bool AForm::isSigned() const { return _isSigned; }

// Sign method
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

// Operator overload
std::ostream &operator<<(std::ostream &o, AForm const &form) {
    o << "Form: " << form.getName()
      << ", sign grade: " << form.getSignGrade()
      << ", exec grade: " << form.getExecGrade()
      << ", signed: " << (form.isSigned() ? "yes" : "no");
    return o;
}
