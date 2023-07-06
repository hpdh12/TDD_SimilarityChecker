#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityChecker, getLengthPointMaxWhenLengthIsSame) {
	string input1 = "ABC";
	string input2 = "BBQ";
	SimilarityChecker checker;
	
	int point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(SimilarityChecker::MAX_POINT_LENGTH, point);
}

TEST(SimilarityChecker, getLengthPointZeroWhenDifferentOverTwoTimes) {
	string input1 = "ABC";
	string input2 = "BBQBBQ";
	SimilarityChecker checker;

	int point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(0, point);
}

TEST(SimilarityChecker, getLengthPointPartial) {
	vector<vector<string>> inputs = {
		{ "ABC", "BBQY" },
		{ "ABCDE", "BBQ" },
	};
	vector<int> expecteds = {
		40,
		20,
	};
	SimilarityChecker checker;

	for (int i = 0; i < inputs.size(); i++)
	{
		string input1 = inputs[i][0];
		string input2 = inputs[i][1];
		int expected = expecteds[i];

		int point = checker.getLengthPoint(input1, input2);
		EXPECT_EQ(expected, point);
	}
}