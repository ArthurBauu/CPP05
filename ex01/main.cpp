#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	// Creating Bureaucrat Alice with grade 2
	std::cout << "\nCreating Bureaucrat Alice with grade 2:" << std::endl;
	Bureaucrat *a = new Bureaucrat("Alice", 2);
	std::cout << a;

	// Creating Forms
	std::cout << "\nCreating Forms:" << std::endl;
	Form *f = new Form("Giving presidential status", 1, 1);
	std::cout << f;
	
	Form *g = new Form("Giving parking ticket", 150, 150);
	std::cout << g;

	Form *i = new Form("Extremly important form", 2, 2);
	std::cout << i;

	// Alice tries to sign the forms
	std::cout << "\nAlice tries to sign the forms:" << std::endl;
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
		a->signForm(*g);
		std::cout << g;
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

	// Trying to create a form with invalid grade
	std::cout << "\nCreating a form with invalid grade '151':" << std::endl;
	try
	{
			Form *h = new Form("Impossible form", 151, 1);
			std::cout << h;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//cleaning up
	std::cout << "\nCleaning up:" << std::endl;
	delete a;
	delete f;
	delete g;
	delete i;


	return 0;
}