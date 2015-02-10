//
// command.hh for command in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:07:43 2015 julien gazzola
// Last update Tue Feb 10 10:44:56 2015 julien gazzola
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

#include <string>

class	Command
{
private:
  std::vector<std::string>	instruction;

public:
  Command() {}
  ~Command() {}
public:
  void				push(..);
  void				pop();
  void				dump();
  void				assert(..);
  void				add();
  void				sub();
  void				mul();
  void				div();
  void				mod();
  void				printf();
  void				exit();
};

#endif /* !COMMAND_HH_ */
