#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string in_target)
: Form("Robotomy request", 72, 45), target(in_target) 
{}

const std::string &RobotomyRequestForm::getTarget()
{
  return (target); 
}

void  RobotomyRequestForm::execution() const
{
  int result;

  std::srand(std::time(0));
  result = rand();
  
  std::cout << "BrrrrrrrrrrrrrrrrrrrrrrrZZZZZZZZZZZZZZZZZZZZZZZZZZZZZzzzzzzzzzzzzzzzzzzzzzzzzzzz!"
            << std::endl;
  
  if (result % 2 == 0)
    std::cout << target << " was successfully robotomised!" 
              << std::endl;
  else
    std::cout << "the robotomisation on " << target << " was unsuccessfull"
              << std::endl;
}