#include"phrases.h"

int main(int argc, char* argv[]) 
{
	int i,n = 2,m = 2;
	std::string argument, filename;
	std::map<std::string, int> phrases;
	std::ifstream file;
	std::map<std::string, int>::iterator it;
	for (i = 0; i < argc; i++)
	{
		argument = argv[i];
		if (argument.compare("-n"))
		{
			n = (int)argv[i + 1];
		}
		if (argument.compare("-m"))
		{
			m = (int)argv[i + 1];
		}
		if (argument.find(".txt") != std::string::npos)
		{
			filename = argument;
		}
	}
	if (filename.empty())
	{
		PhrasesFromFile(n, phrases, std::cin);
	}
	else
	{
		file.open(filename);
		PhrasesFromFile(n, phrases, file);
		file.close();
	}
	for (it = phrases.begin(); it != phrases.end(); ++it)
	{
		if (it->second >= m)
			std::cout << it->first << "(" << it->second << ")" << std::endl;
	}
}

