#include <string>

using namespace std;

class SimilarityChecker
{
public:

	int getLengthPoint(string input1, string input2)
	{
		if (isLengthSame(input1, input2))
			return MAX_POINT_LENGTH;

		if (isDoubleLenGap(input1, input2))
			return MIN_POINT_LENGTH;

		int lenShorter = getLenShorter(input1, input2);
		int lenLonger = getLenLonger(input1, input2);

		int lenDiff = lenLonger - lenShorter;

		int result = (int)((1 - (double)lenDiff / lenShorter) * MAX_POINT_LENGTH);

		return result;

	}

	enum MAX_POINT {
		MAX_POINT_LENGTH = 60,
		MIN_POINT_LENGTH = 0,
	};
private:
	bool isLengthSame(string input1, string input2)
	{
		return input1.size() == input2.size();
	}

	bool isDoubleLenGap(string input1, string input2)
	{
		return (input1.size() >= input2.size() * 2) ||
			(input2.size() >= input1.size() * 2);
	}

	int getLenLonger(string input1, string input2)
	{
		if (input1.size() > input2.size())
		{
			return (int)input1.size();
		}

		return (int)input2.size();
	}

	int getLenShorter(string input1, string input2)
	{
		if (input1.size() > input2.size())
		{
			return (int)input2.size();
		}
		return (int)input1.size();
	}
};