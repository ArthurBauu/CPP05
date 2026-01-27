#include "Bureaucrat.hpp"

int main()
{
	//creating Bureaucrats
	std::cout << "\nCreating Bureaucrats:" << std::endl;
	Bureaucrat *a = new Bureaucrat();
	std::cout << a;
	Bureaucrat *b = new Bureaucrat("Bob");
	std::cout << b;
	Bureaucrat *c = new Bureaucrat("dummy", 149);
	std::cout << c;
	Bureaucrat *d = new Bureaucrat("Alice", 2);
	std::cout << d;

	//creating Bureaucrat with invalid grades
	std::cout << "\nCreating Bureaucrat with invalid grades:" << std::endl;
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

	//incrementing grade
	c->incrementGrade();
	std::cout << c;
	c->incrementGrade();
	std::cout << c;


	//going to 1
	std::cout << "\nUpgrading Alice grade from 2 to 1:" << std::endl;
	std::cout << d->getName() << " current grade: " << d->getGrade() << std::endl;
	d->incrementGrade(); 
	std::cout << d->getName() << " new grade: " << d->getGrade() << std::endl;
	std::cout << d;
 
	//trying to go under 1
	std::cout << "\nTrying to increment grade over 1:" << std::endl;
	try{
		d->incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Decreasing grade
	std::cout << "\nDecreasing grade after trying to go over 1:" << std::endl;
	d->decrementGrade();
	std::cout << d;

	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}