#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form(std::string in_name, int in_SignLvl, int in_ExecLvl)
: name(in_name), signature(false)
{
  if (in_SignLvl < 1)
    throw Form::GradeTooHighException("Signature lvl for the form is too high");
  if (in_SignLvl > 150)
    throw Form::GradeTooLowException("Signature lvl for the form is too low");
  if (in_ExecLvl < 1)
    throw Form::GradeTooHighException("Execution lvl for the form is too high");
  if (in_ExecLvl > 150)
    throw Form::GradeTooHighException("Execution lvl for the form is too low");
  
  SignLvl = in_SignLvl;
  ExecLvl = in_ExecLvl;
}

Form::Form(const Form &ref)
: name(ref.name), signature(ref.signature), SignLvl(ref.SignLvl), ExecLvl(ref.ExecLvl) 
{}

Form::~Form()
{}

Form  &Form::operator=(const Form &to_affect)
{
  (std::string)name = to_affect.name;
  signature = to_affect.signature;
  SignLvl = to_affect.SignLvl;
  ExecLvl = to_affect.ExecLvl;
  return (*this);
}

const std::string &Form::getName() const
{
  return (name);
}

bool        Form::isSigned()
{
  return (signature);
}

int &Form::getSignLvl()
{
  return (SignLvl);
}

int &Form::getExecLvl()
{
  return (ExecLvl);
}

void   Form::beSigned(const Bureaucrat &brc)
{
  try
  {  
    if (brc.getGrade() > SignLvl)
      throw (Form::GradeTooLowException("need a higher "));
  }
  catch (Form::GradeTooLowException &e)
  {
    std::cout << brc.getName() << " is not authorized to sign " << getName() << std::endl;
    return ;
  }
  if (isSigned())
    std::cout << brc.getName() << " couldn't sign " << getName() << ", someone else already signed it" << std::endl;
  else
  {
    signature = true;
    std::cout << brc.getName() << " signed the " << getName() << std::endl;
  }
}

void    Form::execute(const Bureaucrat &executor) const
{
  if (signature == false)
    throw (Form::signature_prob(getName() + " is not signed, can't be executed"));
  if (executor.getGrade() > ExecLvl)
    throw (Form::GradeTooLowException(executor.getName() + "'s grade is too low for execution"));
  execution();
}

//////////////////////////////
//        EXCEPTION         //
//////////////////////////////

Form::GradeTooHighException::GradeTooHighException(std::string in_msg)
: msg(in_msg)
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

const char *Form::GradeTooHighException::what() const throw()
{
  return (msg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string in_msg)
: msg(in_msg)
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

const char *Form::GradeTooLowException::what() const throw()
{
  return (msg.c_str());
}

Form::signature_prob::signature_prob(std::string in_msg)
: msg(in_msg)
{}

Form::signature_prob::~signature_prob() throw()
{}

const char *Form::signature_prob::what() const throw()
{
  return (msg.c_str());
}

std::ostream  &operator<<(std::ostream &os, Form &to_insert)
{
        os << to_insert.getName() << "(grade to sign: " << to_insert.getSignLvl() 
           << ", grade to execute: " << to_insert.getExecLvl() << ")";
        return (os); 
}