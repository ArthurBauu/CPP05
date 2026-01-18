#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	// Creating bureaucrats and forms
	std::cout << "----- Creating bureaucrats and forms -----" << std::endl;
	Bureaucrat *a = new Bureaucrat("Alice", 2);
	std::cout << a;

	Bureaucrat *b = new Bureaucrat("Bob", 149);
	std::cout << b;

	ShrubberyCreationForm *f = new ShrubberyCreationForm("Tree");
	std::cout << f;

	ShrubberyCreationForm *i = new ShrubberyCreationForm("office");
	std::cout << i;

	RobotomyRequestForm *r = new RobotomyRequestForm("Irobot");
	std::cout << r;

	PresidentialPardonForm *p = new PresidentialPardonForm("Marvin");
	std::cout << p;



	// Signing forms
	std::cout << "\n----- Signing forms -----" << std::endl;
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

	// Executing ShrubberyCreationForms
	std::cout << "\n----- Executing Shrubbery forms -----" << std::endl;
	try
	{
		f->execute(*a);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- Bob Executing Shrubbery forms -----"<<std::endl;
	try
	{
		i->execute(*b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Signing and executing RobotomyRequestForm
	std::cout << "\n----- Signing and executing Robotomy form -----" << std::endl;
	try
	{
		b->signForm(*r);
		std::cout << r;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		a->signForm(*r);
		std::cout << r;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		r->execute(*a);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Signing and executing PresidentialPardonForm
	std::cout << "\n----- Signing and executing Presidential Pardon form -----" << std::endl;

	try
	{
		b->signForm(*p);
		std::cout << p;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		a->signForm(*p);
		std::cout << p;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		p->execute(*a);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Cleaning up
	std::cout << "\n----- Cleaning up -----" << std::endl;
	delete a;
	delete b;
	delete f;
	delete i;
	delete r;
	delete p;
	
	return 0;
}