/*
** main.c for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb 10 11:23:10 2015 Cédric Voinnet
// Last update Fri Feb 13 10:56:08 2015 Cédric Voinnet
*/

#include <iostream>
#include <string>
#include "Command.hh"
#include "Int8.hh"
#include "Int32.hh"

int		main(int ac, char **av)
{
  Command	*runTime = new Command();

  if (ac == 1)
    runTime->getInstructions();
  else
    if (runTime->getInstructions(av[1]))
      return (-1);
  if (runTime->execution())
    {
      delete runTime;
      return (-1);
    }
  delete runTime;
}
