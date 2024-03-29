#ifndef FORM_HPP
# define FORM_HPP

//#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
  public:
          Form(std::string in_name, int in_SignLvl, int in_ExecLvl);
          Form(const Form &ref);
          ~Form();
          Form  &operator=(const Form &to_affect);

          const std::string &getName();
          bool        isSigned();
          int         &getSignLvl();
          int         &getExecLvl();

          void              beSigned(const Bureaucrat &brc);          

          class GradeTooHighException;
          class GradeTooLowException;

  private:
          const std::string name;
          bool              signature;
          int               SignLvl;
          int               ExecLvl;
};

std::ostream    &operator<<(std::ostream &os, Form &to_insert);

class Form::GradeTooHighException: public std::exception
{
  public: 
          GradeTooHighException(std::string in_msg);
          ~GradeTooHighException() throw();
          const char * what() const throw();
  private:
          std::string msg;
};

class Form::GradeTooLowException: public std::exception
{
  public: 
          GradeTooLowException(std::string in_msg);
          ~GradeTooLowException() throw();
          const char * what() const throw();
  private:
          std::string msg;
};

#endif