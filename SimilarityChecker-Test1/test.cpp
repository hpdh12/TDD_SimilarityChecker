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
	string input1 = "ABC";
	string input2 = "BBQY";
	SimilarityChecker checker;

	int point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(40, point);

	input1 = "ABCDE";
	input2 = "BBQ";

	point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(20, point);
}