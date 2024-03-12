#include "learn/animals.hpp"
#include <fstream>
void Animals::saveToFile(const std::string& absolutePath){
	std::string a;
	std::ofstream writer(absolutePath);
	writer.write(_name.c_str(),_name.size());
	writer.close();
}
