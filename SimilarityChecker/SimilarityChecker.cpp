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
		return 0;
	}

	enum MAX_POINT {
		MAX_POINT_LENGTH = 60,
	};
};