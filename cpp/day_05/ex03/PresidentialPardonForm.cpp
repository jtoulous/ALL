#include "PresidentialPardonForm.hpp"
#include "Form.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(std::string in_target)
: Form("Presidential Pardon", 25, 5), target(in_target)  
{}

void  PresidentialPardonForm::execution() const
{
  std::cout << target << " was pardonned by Zaphod Beeblebrox"
            << std::endl;
}

const std::string &PresidentialPardonForm::getTarget()
{
  return (target);
}