//
// Command.cpp for Command in /home/gazzol_j/rendu/abstractvm/src
// 
// Made by julien gazzola
// Login   <gazzol_j@epitech.net>
// 
// Started on  Tue Feb 10 10:20:20 2015 julien gazzola
// Last update Fri Feb 13 17:20:20 2015 Cédric Voinnet
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Command.hh"

Command::Command()
{
  _parserMap["push"] = make_pair(PUSH, &Command::push);
  _parserMap["assert"] = make_pair(ASSERT, &Command::assert);
  _parserMap["pop"] = make_pair(POP, &Command::pop);
  _parserMap["dump"] = make_pair(DUMP, &Command::dump);
  _parserMap["add"] = make_pair(ADD, &Command::add);
  _parserMap["sub"] = make_pair(SUB, &Command::sub);
  _parserMap["mul"] = make_pair(MUL, &Command::mul);
  _parserMap["div"] = make_pair(DIV, &Command::div);
  _parserMap["mod"] = make_pair(MOD, &Command::mod);
  _parserMap["print"] = make_pair(PRINT, &Command::print);
  _parserMap["exit"] = make_pair(EXIT, &Command::exit);
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

  while (currentInstruction != this->_instructions.end()){
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
  std::cout << "PREMIER KEYWORD: " << word << std::endl;
  result = _parserMap.find(word);
  if (result == _parserMap.end())
    return (false);
  if (result->second.first == PUSH || result->second.first == ASSERT)
    {
      ss >> word;
      std::cout << "SECOND KEYWORD: " << word << std::endl;
      
    }
  (result->second.second)(word);
  return (true);
}

void	Command::push(std::string str)
{
  std::cout << "C'est un push" << std::endl;
}

void	Command::pop(std::string str)
{
  std::cout << "C'est un pop" << std::endl;
}

void	Command::dump(std::string str)
{
  std::cout << "C'est un dump" << std::endl;
}

void	Command::assert(std::string str)
{
  std::cout << "C'est un assert" << std::endl;
}

void	Command::add(std::string str)
{
  std::cout << "C'est un add" << std::endl;
}

void	Command::sub(std::string str)
{
  std::cout << "C'est un sub" << std::endl;
}

void	Command::mul(std::string str)
{
  std::cout << "C'est un mul" << std::endl;
}

void	Command::div(std::string str)
{
  std::cout << "C'est un div" << std::endl;
}

void	Command::mod(std::string str)
{
  std::cout << "C'est un mod" << std::endl;
}

void	Command::print(std::string str)
{
  std::cout << "C'est un print" << std::endl;
}

void	Command::exit(std::string str)
{
  std::cout << "C'est un exit" << std::endl;
}
