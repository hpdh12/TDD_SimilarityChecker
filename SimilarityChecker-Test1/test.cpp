#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, getAlphaPointMax)
{
	int point = checker.getAlphaPoint("ASD", "DSA");
	EXPECT_EQ(SimilarityChecker::MAX_POINT_ALPHA, point);
}