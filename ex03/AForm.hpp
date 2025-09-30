#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;





	public:
		AForm();
		AForm(const AForm &src);
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		AForm &operator=(const AForm &rhs);

		const std::string getName(void) const;
		bool		isSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const &executor) const;

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
	
	protected: 
		virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &a);

#endif