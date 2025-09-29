#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat *a = new Bureaucrat("Alice", 2);
	std::cout << a;

	ShrubberyCreationForm *f = new ShrubberyCreationForm("home");
	std::cout << f;

	ShrubberyCreationForm *i = new ShrubberyCreationForm("office");
	std::cout << i;


	std::cout << "----- Signing forms -----" << std::endl;
	try
	{
		a->signForm(*f);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		a->signForm(*i);
		std::cout << i;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}



	return 0;
}