#pragma once

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

Form  *create_PresidentialPardon(std::string &target);
Form  *create_RobotomyRequest(std::string &target);
Form  *create_ShrubberyCreation(std::string &target);

class Intern
{
  public:
          Intern();
          Intern(Intern &ref);
          ~Intern();

          Intern  &operator=(const Intern &ref);

          Form  *makeForm(std::string name, std::string target);
          Form  *(*createFormz[3])(std::string &);

        // Form  *create_PresidentialPardon(std::string &target);
        // Form  *create_RobotomyRequest(std::string &target);
        // Form  *create_ShrubberyCreation(std::string &target);
};