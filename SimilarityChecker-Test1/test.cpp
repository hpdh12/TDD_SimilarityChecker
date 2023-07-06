#include "pch.h"
#include "../SimilarityChecker/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, getAlphaPointMax)
{
	EXPECT_EQ(40, checker.getAlphaPoint("ASD", "DSA"));
}