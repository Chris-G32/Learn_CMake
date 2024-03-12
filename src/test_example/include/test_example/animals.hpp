#ifndef ANIMALS_HPP_
#define ANIMALS_HPP_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Animals
{
public:
	Animals() { _name = names[std::rand() % 4]; }
	Animals(std::string name) : _name(name) {}
	void saveToFile(const std::string &); // Takes an absolute path to a file
	std::string getName() { return _name; }
	static const std::vector<std::string> names;

	private : std::string _name;
};
const std::vector<std::string> Animals::names = {"jerry", "dave", "steve", "daniel"};

#endif
