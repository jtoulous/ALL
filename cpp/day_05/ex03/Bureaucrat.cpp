#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade)
: name(in_name)
{
  if (in_grade > 150)
    throw (Bureaucrat::GradeTooLowException());
  if (in_grade < 1)
    throw (Bureaucrat::GradeTooHighException());
  grade = in_grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
: name(ref.name), grade(ref.grade)
{}

const std::string &Bureaucrat::getName() const
{
  return (name);
}

int Bureaucrat::getGrade() const
{
  return (grade);
}

void  Bureaucrat::promote()
{
  if (grade == 1)
    throw (Bureaucrat::GradeTooHighException());
  grade--;
}

void  Bureaucrat::demote()
{
  if (grade == 150)
    throw (Bureaucrat::GradeTooLowException());
  grade++; 
}

void  Bureaucrat::signForm(Form &to_sign)
{
  if (nullCheck(&to_sign) == true)
    return ;
  to_sign.beSigned(*this);
}

void  Bureaucrat::executeForm(const Form &form)
{
  if (nullCheck(&form) == true)
    return ;
  try 
  {
    form.execute(*this);
  }
  catch(Form::signature_prob &e)
  {
    std::cout << e.what() << std::endl;
    return ;
  }
  catch(Form::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
    return ;
  }
  std::cout << name << " has executed the " << form.getName()
            << std::endl;
}

bool  Bureaucrat::nullCheck(const Form *form)
{
  if (form == NULL)
    return (true);
  else
    return (false);
}

////////////////////////////////
///////   EXCEPTION   //////////
////////////////////////////////

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade Too Low");
}

std::ostream  &operator<<(std::ostream &os, Bureaucrat &to_insert)
{
  os << to_insert.getName() << ", bureaucrat grade " << to_insert.getGrade();
  return (os);
}