/*
** main.c for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb 10 11:23:10 2015 Cédric Voinnet
// Last update Thu Feb 12 10:50:37 2015 Cédric Voinnet
*/

#include <iostream>
#include <string>
#include "Command.hh"
#include "Int8.hh"
#include "Int32.hh"

int		main(int ac, char **av)
{
  // Command	*runTime = new Command();

  // if (ac == 1)
  //   runTime->getInstructions();
  // else
  //   if (runTime->getInstructions(av[1]))
  //     return (-1);
  // if (runTime->execution())
  //   {
  //     delete runTime;
  //     return (-1);
  //   }
  // delete runTime;

  IOperand	*operand1 = new Int8("1");
  IOperand	*operand2 = new Int8("2");
  IOperand	*result;

  result = *operand1 * *operand2;
  std::cout << result->toString() << std::endl;
  return (0);
}
