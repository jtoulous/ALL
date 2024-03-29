#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string in_target)
: Form("Shrubbery creation", 145, 137), target(in_target)
{}

const std::string &ShrubberyCreationForm::getTarget()
{
  return (target);
}

void  ShrubberyCreationForm::execution() const
{
  std::string   fileName = target + "_shruberry";
  std::ofstream outfile(fileName.c_str());

  if (outfile.is_open())
  {
    outfile <<  "       ccee88oo               ccee88oo              ccee88oo\n    C8O8O8Q8PoOb o8oo     C8O8O8Q8PoOb o8oo    C8O8O8Q8PoOb o8oo\n  dOB69QO8PdUOpugoO9bD  dOB69QO8PdUOpugoO9bD   dOB69QO8PdUOpugoO9bD\n CgggbU8OU qOp qOdoUOdcbCgggbU8OU qOp qOdoUOdcb  CgggbU8OU qOp qOdoUOdcb\n      6OuU  /p u gcoUodpP      6OuU  /p u gcoUodpP      6OuU  /p u gcoUodpP\n        \\\\\\\\\\\\//  /douUP         \\\\\\\\\\\\//  /douUP         \\\\\\\\\\\\//  /douUP\n         \\\\\\\\\\\\\\\\\\\\////\\\\\\\\\\\\\\          \\\\\\\\\\\\\\\\\\\\////\\\\\\\\\\\\\\          \\\\\\\\\\\\\\\\\\\\////\\\\\\\\\\\\\\\n          |||/\\\\\\\\\\   |||/\\\\\\\\\\   |||/\\\\\\\\\\\n          |||\\\\\\\\\\/   |||\\\\\\\\\\/   |||\\\\\\\\\\\\\n          |||||       |||||       |||||\n   .....//||||       //||||       //||||\n``````||||||     ||||||     ||||||\n`````||||||     ||||||     ||||||\n`````||||||     ||||||     ||||||\n`````||||||     ||||||     ||||||\n`````||||||     ||||||     ||||||\n^^**^^^^^^^**^ ^^**^^^^^^^**^ ^^**^^^^^^^**^"
            << std::endl;
    outfile.close();
  }
}