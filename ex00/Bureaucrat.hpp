#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>


class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		void setGrade(int grade);

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);

		~Bureaucrat();
		Bureaucrat & operator=(const Bureaucrat &rhs);

		const std::string 	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

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

std::ostream & operator<<(std::ostream &o, Bureaucrat *a);

#endif