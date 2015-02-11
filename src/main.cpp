/*
** main.c for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
** 
** Made by Cédric Voinnet
** Login   <voinne_c@epitech.net>
** 
** Started on  Tue Feb 10 11:23:10 2015 Cédric Voinnet
// Last update Tue Feb 10 16:07:54 2015 Cédric Voinnet
*/

#include "Command.hh"

int		main(int ac, char **av)
{
  Command	*runTime = new Command();

  if (ac == 1)
    runTime->getInstructions();
  else
    if (runTime->getInstructions(av[1]))
      return (-1);
  if (runTime->execution())
    return (-1);
  return (0);
}
