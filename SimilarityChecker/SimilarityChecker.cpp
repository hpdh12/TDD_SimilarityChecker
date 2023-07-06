#include <string>
#include <map>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphaPoint(string str, string text)
	{
		map<char, bool> mapInput1, mapTotal;
		for (auto ch : str)
		{
			mapInput1[ch] = true;
			mapTotal[ch] = true;
		}
		int cntSame = 0;
		map<char, bool> mapInput2;
		for (auto ch : text)
		{
			if(mapInput2.find(ch) == mapInput2.end())
			{
				if (mapInput1.find(ch) != mapInput1.end())
				{
					cntSame++;
				}
			}
			mapInput2[ch] = true;
			mapTotal[ch] = true;
		}

		if (cntSame == 0)
			return 0;

		return MAX_POINT_ALPHA;
	}

	enum POINT
	{
		MAX_POINT_ALPHA = 40,
	};
};
