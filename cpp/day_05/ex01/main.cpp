#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>

int main()
{
  try 
  {
    Bureaucrat  bill("Bill", 145);
    std::cout << bill << std::endl;
    Form  f1("the death sentence", 151, 144);
    bill.signForm(f1);
    std::cout << f1 << std::endl;
  }
  catch (std::exception &e) 
  {
    std::cout << e.what() << std::endl;
  }
}