#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;

	public:
		Form();
		Form(const Form &src);
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		~Form();

		Form &operator=(const Form &rhs);

		const std::string getName(void) const;
		bool		isSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(const Bureaucrat &b);


		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Form *a);

#endif