/*
** main.c for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb 10 11:23:10 2015 Cédric Voinnet
// Last update Fri Feb 20 11:03:47 2015 Cédric Voinnet
*/

#include <iostream>
#include <string>
#include "Command.hh"
#include "Error.hh"

int		main(int ac, char **av)
{
  Command	*runTime = new Command();

  try {
    if (ac == 1)
      runTime->getInstructions();
    else
      runTime->getInstructions(av[1]);
    runTime->execution();
  } catch (Error const &error) {
    std::cout << "Error: " << error.what() << std::endl;
  }
  delete runTime;
}
