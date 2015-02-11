//
// Command.cpp for Command in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:20:20 2015 julien gazzola
// Last update Wed Feb 11 11:53:39 2015 Cédric Voinnet
//

#include <fstream>
#include <iostream>
#include "Command.hh"

Command::Command()
{
  this->_funcPtrTab[INT8] = &Command::createInt8;
  this->_funcPtrTab[INT16] = &Command::createInt16;
  this->_funcPtrTab[INT32] = &Command::createInt32;
  this->_funcPtrTab[FLOAT] = &Command::createFloat;
  this->_funcPtrTab[DOUBLE] = &Command::createDouble;
}

void		Command::getInstructions()
{
  std::string	instruction;

  while (getline(std::cin, instruction) && instruction != ";;")
    {
      if (instruction != "" && instruction.at(0) != ';')
	this->_instructions.push_back(instruction);
    }
}

int		Command::getInstructions(char *filename)
{
  std::ifstream	file(filename);
  std::string	instruction;

  if (file.is_open())
    {
      while (getline(file, instruction))
	if (instruction != "" && instruction.at(0) != ';')
	  this->_instructions.push_back(instruction);
      file.close();
    } 
  else
    {
      std::cout << "Cannot open file: " << filename << std::endl;
      return (-1);
    }
  return (0);
}

int					Command::execution()
{
  std::vector<std::string>::iterator	currentInstruction = this->_instructions.begin();

  while (currentInstruction != this->_instructions.end()){
    std::cout << "Execution de: " << *currentInstruction << std::endl;
    if (parser(*currentInstruction))
      return (-1);
    ++currentInstruction;
  }
  return (0);
}

int	Command::parser(std::string line)
{
  (void) line;
  createOperand(INT8, "54");
  createOperand(INT16, "54");
  createOperand(INT32, "54");
  createOperand(FLOAT, "54");
  createOperand(DOUBLE, "54");
  return (0);
}

void	Command::push()
{
  std::cout << "C'est un push" << std::endl;
}

void	Command::pop()
{
  std::cout << "C'est un pop" << std::endl;
}

void	Command::dump()
{
  std::cout << "C'est un dump" << std::endl;
}

void	Command::assert()
{
  std::cout << "C'est un assert" << std::endl;
}

void	Command::add()
{
  std::cout << "C'est un add" << std::endl;
}

void	Command::sub()
{
  std::cout << "C'est un sub" << std::endl;
}

void	Command::mul()
{
  std::cout << "C'est un mul" << std::endl;
}

void	Command::div()
{
  std::cout << "C'est un div" << std::endl;
}

void	Command::mod()
{
  std::cout << "C'est un mod" << std::endl;
}

void	Command::printf()
{
  std::cout << "C'est un printf" << std::endl;
}

void	Command::exit()
{
  std::cout << "C'est un exit" << std::endl;
}

IOperand	*Command::createOperand(eOperandType type, const std::string & value)
{
  return ((this->*_funcPtrTab[type])(value));
}

IOperand	*Command::createInt8(const std::string & value)
{
  IOperand	*operand = new Int8(value);
  return (operand);
}

IOperand	*Command::createInt16(const std::string & value)
{
  std::cout << "createInt16 " << value << std::endl;
  return (NULL);
}

IOperand	*Command::createInt32(const std::string & value)
{
  std::cout << "createInt32 " << value << std::endl;
  return (NULL);
}

IOperand	*Command::createFloat(const std::string & value)
{
  std::cout << "createFloat " << value << std::endl;
  return (NULL);
}

IOperand	*Command::createDouble(const std::string & value)
{
  std::cout << "createDouble " << value << std::endl;
  return (NULL);
}
