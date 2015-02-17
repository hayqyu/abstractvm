//
// Command.cpp for Command in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:20:20 2015 julien gazzola
// Last update Tue Feb 17 10:57:17 2015 Cédric Voinnet
//

#include <fstream>
#include <sstream>
#include <iostream>
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
    {
      if (instruction != "" && instruction.at(0) != ';')
	this->_instructions.push_back(instruction);
    }
  _instructions.push_back("exit");
}

bool		Command::getInstructions(char *filename)
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
      return (false);
    }
  return (true);
}

bool					Command::execution()
{
  std::vector<std::string>::iterator	currentInstruction = this->_instructions.begin();

  while (currentInstruction != this->_instructions.end() && !this->_exit){
    if (!parser(*currentInstruction))
      return (false);
    ++currentInstruction;
  }
  return (true);
}

bool								Command::parser(std::string line)
{
  std::stringstream						ss(line);
  std::map<std::string, std::pair<eAsmInstr, fptr> >::iterator	result;
  std::string							word;

  ss >> word;
  result = _parserMap.find(word);
  if (result == _parserMap.end())
    return (false);
  if (result->second.first == PUSH || result->second.first == ASSERT)
    {
      ss >> word;
      this->_word = word;
    }
  (this->*(result->second.second))();
  return (true);
}

void	Command::push()
{
  Operand	creator;
  std::cout << "C'est un push" << std::endl;

  this->_stack.push_back(creator.createOperand(INT8, "12"));
}

void	Command::pop()
{
  IOperand	*poped;
  std::cout << "C'est un pop" << std::endl;

  if (this->_stack.empty())
    std::cout << "\tStack is empty" << std::endl;
  else
    {
      poped = this->_stack.back();
      this->_stack.pop_back();
      delete poped;
    }
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
  IOperand	*op1;
  IOperand	*op2;

  std::cout << "C'est un add" << std::endl;

  if (this->_stack.size() < 2)
    std::cout << "Oh oh, moins de 2 élements" << std::endl;

  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  std::cout << op1->toString() << std::endl;
  std::cout << op2->toString() << std::endl;
  this->_stack.push_back(*op1 + *op2);
}

void	Command::sub()
{
  IOperand	*op1;
  IOperand	*op2;

  std::cout << "C'est un sub" << std::endl;

  if (this->_stack.size() < 2)
    std::cout << "Oh oh, moins de 2 élements" << std::endl;

  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  std::cout << op1->toString() << std::endl;
  std::cout << op2->toString() << std::endl;
  this->_stack.push_back(*op1 - *op2);
}

void	Command::mul()
{
  IOperand	*op1;
  IOperand	*op2;

  std::cout << "C'est un mul" << std::endl;

  if (this->_stack.size() < 2)
    std::cout << "Oh oh, moins de 2 élements" << std::endl;

  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  std::cout << op1->toString() << std::endl;
  std::cout << op2->toString() << std::endl;
  this->_stack.push_back(*op1 * *op2);
}

void	Command::div()
{
  IOperand	*op1;
  IOperand	*op2;

  std::cout << "C'est un div" << std::endl;

  if (this->_stack.size() < 2)
    std::cout << "Oh oh, moins de 2 élements" << std::endl;

  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  std::cout << op1->toString() << std::endl;
  std::cout << op2->toString() << std::endl;
  this->_stack.push_back(*op1 / *op2);
}

void	Command::mod()
{
  IOperand	*op1;
  IOperand	*op2;

  std::cout << "C'est un mod" << std::endl;

  if (this->_stack.size() < 2)
    std::cout << "Oh oh, moins de 2 élements" << std::endl;

  op2 = this->_stack.back();
  op1 = this->_stack.back();
  this->_stack.pop_back();
  this->_stack.pop_back();
  std::cout << op1->toString() << std::endl;
  std::cout << op2->toString() << std::endl;
  this->_stack.push_back(*op1 % *op2);
}

void	Command::print()
{
  std::cout << "C'est un print" << std::endl;
}

void	Command::exit()
{
  this->_exit = true;
}
