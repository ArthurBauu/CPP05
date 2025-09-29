#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Complete Form construction called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form & Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}


const std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::isSigned(void) const
{
	return this->_signed;
}

int Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign())
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
	}
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream & operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() << ", signed: " << (a->isSigned() ? "true" : "false") << ", grade required to sign: " << a->getGradeToSign() << ", grade required to execute: " << a->getGradeToExecute() << "." << std::endl;
	return o;
}