#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	Intern someRandomIntern;
	AForm* rrf;
	AForm* scf;
	AForm* ppf;
	AForm* ttf;

	std::cout << "\ncreating forms..." << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
	
	try { 
		ttf = someRandomIntern.makeForm("this form does not exist", "Target"); 
	} 
	catch (const std::exception &e) 
	{ 
		std::cerr << e.what() << std::endl; 
	}

	std::cout << "\ncreated forms..." << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *ppf << std::endl;
	
	// (void)ttf;
	

	std::cout << "\nrecruting bureaacrat" << std::endl;
	Bureaucrat *john = new Bureaucrat("Alice", 2);

	std::cout << "\nsigning forms..." << std::endl;
	john->signForm(*rrf);
	john->signForm(*scf);
	john->signForm(*ppf);

	std::cout << "\nexecuting forms..." << std::endl;
	rrf->execute(*john);
	scf->execute(*john);
	ppf->execute(*john);

	std::cout << "\ncleaning up..." << std::endl;
	delete john;
	delete rrf;
	delete scf;
	delete ppf;
	delete ttf;

	return 0;
}