#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// Creating intern and declaring form pointers
	std::cout << "Creating intern" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* ttf = NULL;

	// Creating forms
	std::cout << "\ncreating forms" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
	
	// Trying to create a form that does not exist
	std::cout << "\ntrying to create a form that does not exist" << std::endl;
	try { 
		ttf = someRandomIntern.makeForm("this form does not exist", "Target"); 
	} 
	catch (const std::exception &e) 
	{ 
		std::cerr << e.what() << std::endl; 
	}

	// Displaying created forms
	std::cout << "\ncreated forms" << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *ppf << std::endl;
	
	(void)ttf;
	
	// Bureaucrat creation and working with forms
	std::cout << "\ncreating bureaucrat" << std::endl;
	Bureaucrat *alice = new Bureaucrat("Alice", 2);
	Bureaucrat *bob = new Bureaucrat("Bob", 150);

	std::cout << "\nsigning forms" << std::endl;
	alice->signForm(*rrf);
	alice->signForm(*scf);
	alice->signForm(*ppf);
	try {
		bob->signForm(*scf);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nexecuting forms" << std::endl;
	rrf->execute(*alice);
	scf->execute(*alice);
	ppf->execute(*alice);
	try {
		scf->execute(*bob);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Cleaning up
	std::cout << "\ncleaning up" << std::endl;
	delete alice;
	delete bob;
	delete rrf;
	delete scf;
	delete ppf;
	if (ttf)
		delete ttf;

	return 0;
}