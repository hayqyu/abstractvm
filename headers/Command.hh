//
// Command.hh for command in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:07:43 2015 julien gazzola
// Last update Wed Feb 11 18:13:42 2015 Cédric Voinnet
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

# include <vector>
# include <algorithm>
# include <string>
# include <map>
# include "IOperand.hh"

class					Command
{
private:
  typedef enum	eAsmInstr
    {
      PUSH = 1,
      POP,
      DUMP,
      ASSERT,
      ADD,
      SUB,
      MUL,
      DIV,
      MOD,
      PRINT,
      EXIT
    }		eAsmInstr;

  std::vector<std::string>		_instructions;
  std::vector<IOperand::IOperand>	_nbStack;
  std::map<eAsmInstr, std::string>	_;

public:
  Command();
  ~Command() {}

public:
  void				getInstructions();
  int				getInstructions(char *);

public:
  int				execution();

private:
  int				parser(std::string);

private:
  void			push();
  void			pop();
  void			dump();
  void			assert();
  void			add();
  void			sub();
  void			mul();
  void			div();
  void			mod();
  void			printf();
  void			exit();
};

#endif // !COMMAND_HH_
