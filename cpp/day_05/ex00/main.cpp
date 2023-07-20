#include "Bureaucrat.hpp"
#include <exception>

int main()
{
  Bureaucrat  bill("Bill", 150);
  
  try
  {  
    //Bureaucrat  bill("Bill", 150);
    //std::cout << "all good" << std::endl;
    bill.demote();
  }
  catch (std::exception &e) 
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << bill << std::endl;
  return (0);
}