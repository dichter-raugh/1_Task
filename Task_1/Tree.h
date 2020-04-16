#pragma once
#include<string>
#include<iostream>
class Tree
{
private:
	std::string phrase;
	int num;
	Tree* right;
	Tree* left;
public:
	Tree* SearchPhrase(std::string newPhrase) 
	{
		int n = phrase.compare(newPhrase);
		if (n == 0 || n < 0 && left == NULL || n > 0 && right == NULL) return this;
		else if (n < 0) return left->SearchPhrase(newPhrase);
		else return right->SearchPhrase(newPhrase);
	}
	void AddNum() 
	{
		num++;
	}
	void AddKnot(Tree knot) 
	{
		if (phrase.compare(knot.phrase) < 0) right = &knot;
		else left = &knot;
	}
	void Output(int n) 
	{
		if (left) left->Output(n);
		if (num >= n)
			std::cout << phrase << " (" << num << ")" << std::endl;
		if (right) right->Output(n);
	}
	Tree () 
	{
		phrase = "\0";
		num = 0;
		right = NULL;
		left = NULL;
	}
	Tree(std::string newPhrase)
	{
		phrase = newPhrase;
		num = 1;
		right = NULL;
		left = NULL;
	}
	~Tree() = default;
};

