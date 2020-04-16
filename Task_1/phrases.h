#pragma once
#include<string>
#include<map>
#include<iostream>
#include<fstream>


void PhrasesFromFile(int n, std::map<std::string, int>& phrases, std::istream &file)
{
	int i;
	std::string word, phrase;
	std::map<std::string, int>::iterator it;
	std::size_t space;
	for (i = 0; i < n - 1; i++)
	{
		std::cin >> word;
		phrase += word;
		phrase += " ";
	}
	while (file >> word)
	{
		phrase += word;
		it = phrases.find(phrase);
		if (it != phrases.end())
			it->second++;
		else
			phrases.insert(std::pair < std::string, int>(phrase, 1));
		space = phrase.find(" ");
		phrase = phrase.substr(space + 1, phrase.length() - space);
		phrase += " ";
	}
}
