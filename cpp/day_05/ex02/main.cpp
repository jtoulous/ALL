#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <exception>

int main()
{
  try 
  {
    Bureaucrat  bill("Bill", 4);
    std::cout << bill << std::endl;
    PresidentialPardonForm  f1("bobby");
    Form  *f2 = new ShrubberyCreationForm("garden");
    bill.signForm(f1);
    std::cout << f1 << std::endl;
    bill.executeForm(f1);
    bill.signForm(*f2);
    bill.executeForm(*f2);
  }
  catch (std::exception &e) 
  {
    std::cout << e.what() << std::endl;
  }
}