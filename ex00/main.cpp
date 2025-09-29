#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *a = new Bureaucrat();
	std::cout << a;
	Bureaucrat *b = new Bureaucrat("Bob");
	std::cout << b;
	Bureaucrat *c = new Bureaucrat("dummy", 149);
	std::cout << c;
	Bureaucrat *d = new Bureaucrat("Alice", 2);
	std::cout << d;

	try
	{
		Bureaucrat* e = new Bureaucrat("Charlie", 151);
		std::cout << e;
		delete e;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat* f = new Bureaucrat("Eve", 0);
		std::cout << f;
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//going to 150
	c->decrementGrade(); 
	std::cout << c;
	//trying to go over 150
	try{
		c->decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// decreasing grade
	c->incrementGrade();
	std::cout << c;
	c->incrementGrade();
	std::cout << c;


	//going to 1
	d->incrementGrade(); 
	std::cout << d;
	//trying to go under 1
	try{
		d->incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// increasing grade
	d->decrementGrade();
	std::cout << d;




	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}