#include <string>

using namespace std;

class SimilarityChecker
{
public:
	bool isLengthSame(string input1, string input2)
	{
		return input1.size() == input2.size();
	}

	int getLengthPoint(string input1, string input2)
	{
		if (isLengthSame(input1, input2))
			return MAX_POINT_LENGTH;

		if ((input1.size() >= input2.size() * 2) ||
			(input2.size() >= input1.size() * 2))
			return 0;

		double tmp1, tmp2;

		if (input1.size() > input2.size())
		{
			tmp1 = input1.size();
			tmp2 = input2.size();
		}
		else
		{
			tmp1 = input2.size();
			tmp2 = input1.size();
		}

		int lenDiff;
		lenDiff = tmp1 - tmp2;

		int result;
		result = (1 - lenDiff / tmp2) * 60;

		return result;

	}

	enum MAX_POINT {
		MAX_POINT_LENGTH = 60,
	};
};