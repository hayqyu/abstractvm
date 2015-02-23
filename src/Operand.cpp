//
// Operand.cpp for abstractvm in /home/voinne_c/rendu/cpp_abstractvm
// 
// Made by Cédric Voinnet
// Login   <voinne_c@epitech.net>
// 
// Started on  Wed Feb 11 14:26:25 2015 Cédric Voinnet
// Last update Mon Feb 23 11:30:24 2015 Cédric Voinnet
//

#include "Operand.hh"
#include "IOperand.hh"
#include "Calc.hh"

Operand::Operand()
{
  this->_funcPtrTab[INT8] = &Operand::createInt8;
  this->_funcPtrTab[INT16] = &Operand::createInt16;
  this->_funcPtrTab[INT32] = &Operand::createInt32;
  this->_funcPtrTab[FLOAT] = &Operand::createFloat;
  this->_funcPtrTab[DOUBLE] = &Operand::createDouble;
}

IOperand	*Operand::createOperand(eOperandType type, const std::string & value)
{
  return ((this->*_funcPtrTab[type])(value));
}

IOperand	*Operand::createInt8(const std::string & value)
{
  IOperand	*operand = new Calc<char>(value);
  return (operand);
}

IOperand	*Operand::createInt16(const std::string & value)
{
  IOperand	*operand = new Calc<short>(value);
  return (operand);
}

IOperand	*Operand::createInt32(const std::string & value)
{
  IOperand	*operand = new Calc<int>(value);
  return (operand);
}

IOperand	*Operand::createFloat(const std::string & value)
{
  IOperand	*operand = new Calc<float>(value);
  return (operand);
}

IOperand	*Operand::createDouble(const std::string & value)
{
  IOperand	*operand = new Calc<double>(value);
  return (operand);
}
