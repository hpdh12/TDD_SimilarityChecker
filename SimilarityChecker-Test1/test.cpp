#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, getLengthPointMaxWhenLengthIsSame) {
	string input1 = "ABC";
	string input2 = "BBQ";
	
	int point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(SimilarityChecker::MAX_POINT_LENGTH, point);
}

TEST_F(SimilarityCheckerFixture, getLengthPointZeroWhenDifferentOverTwoTimes) {
	string input1 = "ABC";
	string input2 = "BBQBBQ";

	int point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(0, point);
}

TEST_F(SimilarityCheckerFixture, getLengthPointPartial) {
	vector<vector<string>> inputs = {
		{ "ABC", "BBQY" },
		{ "ABCDE", "BBQ" },
	};
	vector<int> expecteds = {
		40,
		20,
	};

	for (int i = 0; i < inputs.size(); i++)
	{
		string input1 = inputs[i][0];
		string input2 = inputs[i][1];
		int expected = expecteds[i];

		int point = checker.getLengthPoint(input1, input2);
		EXPECT_EQ(expected, point);
	}
}