#define CATCH_CONFIG_MAIN

#include"phrases.h"
#include"catch.hpp"

TEST_CASE("Counting phrases")
{
	std::map<std::string, int> test_phrases;
	std::stringstream test_file;
	SECTION("Text with one repeat")
	{
		test_file << "In the town where I was born Lived a man who sailed to sea And he told us of his life In the land of submarines";
		PhrasesFromFile(2, test_phrases, test_file);
		REQUIRE(test_phrases.find("In the") != test_phrases.end());
	}
}