#pragma once

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
  public:
          PresidentialPardonForm(std::string in_target);

          //void   execution() const;

          const std::string &getTarget();

  private:
          const std::string  target;
          void   execution() const;

};