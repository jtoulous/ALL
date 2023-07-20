#ifndef FORM_HPP
# define FORM_HPP

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

          bool                        isSigned();
          const std::string           &getName() const;
          int                         &getSignLvl();
          int                         &getExecLvl();
          virtual const std::string   &getTarget() = 0;

          void              beSigned(const Bureaucrat &brc);          
          void              execute(const Bureaucrat &executor) const;
          //virtual void      execution() const = 0;
        
          class GradeTooHighException;
          class GradeTooLowException;
          class signature_prob;
  protected:
          const std::string name;
          bool              signature;
          int               SignLvl;
          int               ExecLvl;
          virtual void      execution() const = 0;

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

class Form::signature_prob: public std::exception
{
  public: 
          signature_prob(std::string in_msg);
          ~signature_prob() throw();
          const char * what() const throw();
  private:
          std::string msg;
};

#endif