#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat(const std::string in_name, int in_grade)
: name(in_name)/*, high(), low()*/
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
: name(ref.name), grade(ref.grade)/*, high(), low()*/ 
{}

const std::string &Bureaucrat::getName()
{
  return (name);
}

int &Bureaucrat::getGrade()
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

////////////////////////////////
///////   EXCEPTION   //////////
////////////////////////////////

/*Bureaucrat::GradeTooHighException::GradeTooHighException()
: msg("Grade too high")
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}
*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return ("Grade Too High");
}

/*Bureaucrat::GradeTooLowException::GradeTooLowException()
: msg("Grade too low")
{}*/

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return ("Grade Too Low");
}

std::ostream  &operator<<(std::ostream &os, Bureaucrat &to_insert)
{
  os << to_insert.getName() << ", bureaucrat grade " << to_insert.getGrade();
  return (os);
}