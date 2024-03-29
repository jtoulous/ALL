#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

Intern::Intern()
{
  createFormz[0] = &create_PresidentialPardon;
  createFormz[1] = &create_RobotomyRequest;
  createFormz[2] = &create_ShrubberyCreation;
}

Intern::Intern(Intern &ref)
{
  createFormz[0] = &create_PresidentialPardon;
  createFormz[1] = &create_RobotomyRequest;
  createFormz[2] = &create_ShrubberyCreation;
}

Intern::~Intern()
{}

Intern  &Intern::operator=(const Intern &ref)
{
  return (*this);
}

Form  *Intern::makeForm(std::string name, std::string target)
{
  std::string  Formz[3] = {"Presidential pardon", "Robotomy request", "Shrubbery creation"};
  int          z = 0;

  while (z < 3)
  {
    if (Formz[z].compare(name) == 0)
      return (createFormz[z](target));
    z++;
  }
  std::cout << "no matching form" << std::endl;
  return (NULL);
}

Form  *create_PresidentialPardon(std::string &target)
{
  PresidentialPardonForm  *new_form;

  new_form = new PresidentialPardonForm(target);
  return (new_form);
}

Form  *create_RobotomyRequest(std::string &target)
{
  RobotomyRequestForm  *new_form;

  new_form = new RobotomyRequestForm(target);
  return (new_form);
}

Form  *create_ShrubberyCreation(std::string &target)
{
  ShrubberyCreationForm  *new_form;

  new_form = new ShrubberyCreationForm(target);
  return (new_form);
}