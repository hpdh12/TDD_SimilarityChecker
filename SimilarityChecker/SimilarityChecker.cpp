#include <string>

using namespace std;

class SimilarityChecker
{
public:
	int getLengthPoint(string input1, string input2)
	{
		if (input1.size() == input2.size())
			return MAX_POINT_LENGTH;
		return 0;
	}

	enum MAX_POINT {
		MAX_POINT_LENGTH = 60,
	};
};