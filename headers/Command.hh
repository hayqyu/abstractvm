//
// Command.hh for command in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:07:43 2015 julien gazzola
// Last update Fri Feb 13 15:55:27 2015 Cédric Voinnet
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

# include <vector>
# include <algorithm>
# include <string>
# include <map>
# include <utility>
# include "IOperand.hh"

class					Command
{
private:
  typedef void	(Command::*fptr)(std::string);
  typedef enum	eAsmInstr
    {
      PUSH = 1,
      ASSERT,
      POP,
      DUMP,
      ADD,
      SUB,
      MUL,
      DIV,
      MOD,
      PRINT,
      EXIT
    }		eAsmInstr;

  std::vector<std::string>					_instructions;
  std::vector<IOperand::IOperand>				_nbStack;
  std::map<std::string, std::pair<eAsmInstr, fptr> >		_parserMap;

public:
  Command();
  ~Command() {}

public:
  void				getInstructions();
  bool				getInstructions(char *);

public:
  bool				execution();

private:
  bool				parser(std::string);

private:
  void			push(std::string);
  void			pop(std::string);
  void			dump(std::string);
  void			assert(std::string);
  void			add(std::string);
  void			sub(std::string);
  void			mul(std::string);
  void			div(std::string);
  void			mod(std::string);
  void			print(std::string);
  void			exit(std::string);
};

#endif // !COMMAND_HH_
