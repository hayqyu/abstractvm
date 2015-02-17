//
// Command.hh for command in /home/gazzol_j/rendu/abstractvm/headers
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:07:43 2015 julien gazzola
// Last update Tue Feb 17 10:43:25 2015 Cédric Voinnet
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
  typedef void	(Command::*fptr)();
  typedef enum	eAsmInstr
    {
      PUSH,
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

  bool								_exit;
  std::vector<std::string>					_instructions;
  std::vector<IOperand::IOperand *>				_stack;
  std::map<std::string, std::pair<eAsmInstr, fptr> >		_parserMap;
  std::string							_word;

public:
  Command();
  ~Command();

public:
  void				getInstructions();
  bool				getInstructions(char *);

public:
  bool				execution();

private:
  bool				parser(std::string);

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
  void			print();
  void			exit();
};

#endif // !COMMAND_HH_
