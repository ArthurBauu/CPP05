#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// Creating intern
	Intern someRandomIntern;
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* ttf = NULL;

	// Creating forms
	std::cout << "\ncreating forms..." << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
	
	// Trying to create a form that does not exist
	std::cout << "trying to create a form that does not exist..." << std::endl;
	try { 
		ttf = someRandomIntern.makeForm("this form does not exist", "Target"); 
	} 
	catch (const std::exception &e) 
	{ 
		std::cerr << e.what() << std::endl; 
	}

	// Displaying created forms
	std::cout << "\ncreated forms..." << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *ppf << std::endl;
	
	(void)ttf;
	
	// Bureaucrat recruting and working with forms
	std::cout << "\nrecruting bureaucrat" << std::endl;
	Bureaucrat *alice = new Bureaucrat("Alice", 2);

	std::cout << "\nsigning forms..." << std::endl;
	alice->signForm(*rrf);
	alice->signForm(*scf);
	alice->signForm(*ppf);

	std::cout << "\nexecuting forms..." << std::endl;
	rrf->execute(*alice);
	scf->execute(*alice);
	ppf->execute(*alice);

	// Cleaning up
	std::cout << "\ncleaning up..." << std::endl;
	delete alice;
	delete rrf;
	delete scf;
	delete ppf;
	if (ttf)
		delete ttf;

	return 0;
}