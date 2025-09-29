#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat* a = new Bureaucrat();
	std::cout << a;
	Bureaucrat* b = new Bureaucrat("Bob");
	std::cout << b;
	Bureaucrat* c = new Bureaucrat(42);
	std::cout << c;
	Bureaucrat* d = new Bureaucrat("Alice", 21);
	std::cout << d;

	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}