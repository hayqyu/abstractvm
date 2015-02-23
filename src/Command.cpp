//
// Command.cpp for Command in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:20:20 2015 julien gazzola
// Last update Mon Feb 23 11:19:52 2015 Cédric Voinnet
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Error.hh"
#include "Operand.hh"
#include "Command.hh"

Command::Command()
{
  this->_exit = false;
  _parserMap["push"] = std::make_pair(PUSH, &Command::push);
  _parserMap["assert"] = std::make_pair(ASSERT, &Command::assert);
  _parserMap["pop"] = std::make_pair(POP, &Command::pop);
  _parserMap["dump"] = std::make_pair(DUMP, &Command::dump);
  _parserMap["add"] = std::make_pair(ADD, &Command::add);
  _parserMap["sub"] = std::make_pair(SUB, &Command::sub);
  _parserMap["mul"] = std::make_pair(MUL, &Command::mul);
  _parserMap["div"] = std::make_pair(DIV, &Command::div);
  _parserMap["mod"] = std::make_pair(MOD, &Command::mod);
  _parserMap["print"] = std::make_pair(PRINT, &Command::print);
  _parserMap["exit"] = std::make_pair(EXIT, &Command::exit);

  _typeVector.push_back(std::make_pair("int8(", INT8));
  _typeVector.push_back(std::make_pair("int16(", INT16));
  _typeVector.push_back(std::make_pair("int32(", INT32));
  _typeVector.push_back(std::make_pair("float(", FLOAT));
  _typeVector.push_back(std::make_pair("double(", DOUBLE));
}

Command::~Command()
{
  IOperand	*poped;

  while (!this->_stack.empty())
    {
      poped = this->_stack.back();
      delete poped;
      this->_stack.pop_back();
    }
}

void		Command::getInstructions()
{
  std::string	instruction;

  while (getline(std::cin, instruction) && instruction != ";;")
    this->_instructions.push_back(instruction.substr(0, instruction.find(";")));
  _instructions.push_back("exit");
}

void			Command::getInstructions(char *filename)
{
  std::ifstream		file(filename);
  std::string		instruction;
  std::stringstream	error;

  if (file.is_open())
    {
      while (getline(file, instruction))
	this->_instructions.push_back(instruction.substr(0, instruction.find(";")));
      file.close();
    }
  else
    {
      error << "Cannot open file: " << filename;
      throw Error(error.str());
    }
}

void					Command::execution()
{
  std::vector<std::string>::iterator	currentInstruction = this->_instructions.begin();
  std::stringstream			error;

  while (currentInstruction != this->_instructions.end() && !this->_exit){
    if (*currentInstruction != "")
      parser(*currentInstruction);
    ++currentInstruction;
  }
  if (!this->_exit)
    {
      error << "No exit instruction";
      throw Error(error.str());
    }
}

void							Command::parser(std::string line)
{
  std::stringstream						ss(line);
  std::stringstream						error;
  std::map<std::string, std::pair<eAsmInstr, fptr> >::iterator	result;
  std::string							word;

  ss >> word;
  result = _parserMap.find(word);
  if (result == _parserMap.end())
    {
      error << "Unknown command: " << word;
      throw Error(error.str());
    }
  ss >> word;
  if (result->second.first == PUSH || result->second.first == ASSERT)
    this->_value = word;
  else if (word != result->first)
    {
      error << result->first << " doesn't take argument";
      throw Error(error.str());
    }
  (this->*(result->second.second))();
}

void								Command::checkValue()
{
  std::vector<std::pair<std::string, eOperandType> >::iterator	it;
  bool								ok = false;
  std::stringstream						error;
  size_t							begPos;
  size_t							endPos;
  size_t							len;
  std::string							value;

  it = this->_typeVector.begin();
  while (it != this->_typeVector.end())
    {
      if ((begPos = this->_value.find(it->first)) != std::string::npos)
	{
	  this->_type = it->second;
	  len = it->first.size();
	  ok = true;
	}
      ++it;
    }
  if (!ok)
    {
      error << "Unknown value type: " << this->_value;
      throw Error(error.str());
    }
  if ((endPos = this->_value.find(")")) != this->_value.size() - 1)
    {
      error << this->_value << " : Missing \")\"";
      throw Error(error.str());
    }
  begPos += len + 1;
  len = endPos - begPos;
  this->_value = this->_value.substr(begPos, len);
}

void	Command::push()
{
  Operand	creator;

  checkValue();
  this->_stack.push_back(creator.createOperand(this->_type, this->_value));
}

void	Command::pop()
{
  IOperand		*poped;
  std::stringstream	error;

  if (this->_stack.empty())
    {
      error << "Stack is empty";
      throw Error(error.str());
    }
  poped = this->_stack.back();
  this->_stack.pop_back();
  delete poped;
}


void	Command::dump()
{
  std::vector<IOperand::IOperand*>::iterator	it = this->_stack.end();

  while (it != this->_stack.begin())
    {
      --it;
      std::cout << (*it)->toString() << std::endl;
    }
}

void	Command::assert()
{
  std::stringstream	error;

  checkValue();
  if (this->_stack.empty())
    {
      error << "Stack is empty";
      throw Error(error.str());
    }
  if (this->_type != this->_stack.back()->getType() || this->_value != this->_stack.back()->toString())
    {
      error << "Values differ";
      throw Error(error.str());
    }
}

void			Command::add()
{
  IOperand		*op1;
  IOperand		*op2;
  std::stringstream	error;

  if (this->_stack.size() < 2)
    {
      error << "Operation needs 2 operands";
      throw Error(error.str());
    }
  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  this->_stack.push_back(*op1 + *op2);
  delete op1;
  delete op2;
}

void			Command::sub()
{
  IOperand		*op1;
  IOperand		*op2;
  std::stringstream	error;

  if (this->_stack.size() < 2)
    {
      error << "Operation needs 2 operands";
      throw Error(error.str());
    }
  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  this->_stack.push_back(*op1 - *op2);
  delete op1;
  delete op2;
}

void			Command::mul()
{
  IOperand		*op1;
  IOperand		*op2;
  std::stringstream	error;

  if (this->_stack.size() < 2)
    {
      error << "Operation needs 2 operands";
      throw Error(error.str());
    }
  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  this->_stack.push_back(*op1 * *op2);
  delete op1;
  delete op2;
}

void			Command::div()
{
  IOperand		*op1;
  IOperand		*op2;
  std::stringstream	error;

  if (this->_stack.size() < 2)
    {
      error << "Operation needs 2 operands";
      throw Error(error.str());
    }
  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  this->_stack.push_back(*op1 / *op2);
  delete op1;
  delete op2;
}

void			Command::mod()
{
  IOperand		*op1;
  IOperand		*op2;
  std::stringstream	error;

  if (this->_stack.size() < 2)
    {
      error << "Operation needs 2 operands";
      throw Error(error.str());
    }
  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  this->_stack.push_back(*op1 % *op2);
  delete op1;
  delete op2;
}

void	Command::print()
{
  std::stringstream	error;
  std::stringstream	tmp;
  char			toPrint;

  if (this->_stack.empty())
    {
      error << "Stack is empty";
      throw Error(error.str());
    }
  if (this->_stack.back()->getType() != INT8)
    {
      error << "Value is not of type int8";
      throw Error(error.str());
    }
  tmp << this->_stack.back()->toString();
  tmp >> toPrint;
  std::cout << toPrint << std::endl;
}

void	Command::exit()
{
  this->_exit = true;
}
