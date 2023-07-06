#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

TEST(SimilarityChecker, getLengthPointMaxWhenLengthIsSame) {
	string input1 = "ABC";
	string input2 = "BBQ";
	SimilarityChecker checker;
	
	int point = checker.getLengthPoint(input1, input2);
	EXPECT_EQ(60, point);
}