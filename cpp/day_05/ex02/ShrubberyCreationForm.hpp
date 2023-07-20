#pragma once

#include "Form.hpp"
#include <string>

class ShrubberyCreationForm: public Form
{
  public:
        ShrubberyCreationForm(std::string in_target);

        const std::string &getTarget();

  private:
        const std::string target;
        void  execution() const;
};