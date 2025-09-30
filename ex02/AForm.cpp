#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Complete AForm construction called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm & AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}


const std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::isSigned(void) const
{
	return this->_signed;
}

int AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign())
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
	}
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream & operator<<(std::ostream &o, AForm *a)
{
	o << "AForm " << a->getName() << ", signed: " << (a->isSigned() ? "true" : "false") << ", grade required to sign: " << a->getGradeToSign() << ", grade required to execute: " << a->getGradeToExecute() << "." << std::endl;
	return o;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw std::runtime_error("Form is not signed");
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		this->executeAction();
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
}