//
// Operand.hh for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Wed Feb 11 14:30:55 2015 Cédric Voinnet
// Last update Mon Feb 16 11:53:04 2015 julien gazzola
//

#ifndef OPERAND_HH_
# define OPERAND_HH_

# include <string>
# include "IOperand.hh"

class Operand
{
private:
  IOperand			*(Operand::*_funcPtrTab[5]) (const std::string &);

public:
  Operand();
  ~Operand() {}

public:
  IOperand			*createOperand(eOperandType type, const std::string & value);

private:
  IOperand			*createInt8(const std::string & value);
  IOperand			*createInt16(const std::string & value);
  IOperand			*createInt32(const std::string & value);
  IOperand			*createFloat(const std::string & value);
  IOperand			*createDouble(const std::string & value);
};

#endif // !OPERAND_HH_
