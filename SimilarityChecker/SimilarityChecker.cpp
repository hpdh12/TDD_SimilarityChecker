#include <string>

using namespace std;

class SimilarityChecker
{
public:
	bool isLengthSame(string input1, string input2)
	{
		return input1.size() == input2.size();
	}

	double getLenLonger(string input1, string input2)
	{
		if (input1.size() > input2.size())
		{
			return input1.size();
		}

		return input2.size();
	}

	double getLenShorter(string input1, string input2)
	{
		if (input1.size() > input2.size())
		{
			return input2.size();
		}
		return input1.size();
	}

	int getLengthPoint(string input1, string input2)
	{
		if (isLengthSame(input1, input2))
			return MAX_POINT_LENGTH;

		if ((input1.size() >= input2.size() * 2) ||
			(input2.size() >= input1.size() * 2))
			return 0;

		double lenLonger = getLenLonger(input1, input2);
		double lenShorter = getLenShorter(input1, input2);

		int lenDiff = lenLonger - lenShorter;

		int result = (1 - lenDiff / lenShorter) * 60;

		return result;

	}

	enum MAX_POINT {
		MAX_POINT_LENGTH = 60,
	};
};