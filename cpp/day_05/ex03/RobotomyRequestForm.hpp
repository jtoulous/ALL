#pragma once

#include "Form.hpp"
#include <string>

class RobotomyRequestForm: public Form
{
  public:
          RobotomyRequestForm(std::string in_target);

          const std::string &getTarget();

  private:
          const std::string target;
          void  execution() const;
};