#include <string>
#include <iostream>
#include <Windows.h>

void ToDownAll(std::string& line);
bool Findiga(std::string line, std::string word);
void ToUpAll(std::string& line);
int main()
{
	// не работает с русским(
	std::string line;
	std::getline(std::cin, line, '\n');
	if (line.size() <= 0)
	{
		std::cout << "Если строка пуста, то программа сообщает об этом\n";
	}
	else
	{
		std::cout << std::endl;
		line[0] = (char)toupper(line[0]);
		for (int i = 1; i < line.size(); i++)
		{
			line[i] = (char)tolower(line[i]);
		}
		std::cout << line;

		if (line[line.size() - 1] != '.')
		{
			std::cout << ".";
		}
	}
}


bool Findiga(std::string line, std::string word)
{
	
	ToDownAll(line);
	ToDownAll(word);

	int pos = line.find(word);

	if (pos != std::string::npos)
	{
		return true;
	}

	ToUpAll(line);
	ToUpAll(word);

	pos = line.find(word);
	if (pos != std::string::npos)
	{
		return true;
	}

	return false;
}
void ToDownAll(std::string &line)
{
	for (int i = 0; i < line.size() - 1; i++)
	{
		line[i] = (char)tolower(line[i]);
	}
}
void ToUpAll(std::string& line)
{
	for (int i = 0; i < line.size() - 1; i++)
	{
		line[i] = (char)toupper(line[i]);
	}
}