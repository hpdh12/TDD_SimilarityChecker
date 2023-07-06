#include <string>
#include <map>

using namespace std;

class SimilarityChecker
{
public:
	int getAlphaPoint(string input1, string input2)
	{
		map<char, bool> mapInput1, mapTotal;
		for (auto ch : input1)
		{
			mapInput1[ch] = true;
			mapTotal[ch] = true;
		}
		int cntSame = 0;
		map<char, bool> mapInput2;
		for (auto ch : input2)
		{
			if(!isAlpahbetNotCounted(mapInput2, ch))
				continue;

			if (isAlphabetSameUsed(mapInput1, ch))
			{
				cntSame++;
			}
			mapInput2[ch] = true;
			mapTotal[ch] = true;
		}

		if (cntSame == 0)
			return MIN_POINT_ALPHA;

		int cntTotal = mapTotal.size();

		return (int)(MAX_POINT_ALPHA * ((double)cntSame / cntTotal));
	}

	enum POINT
	{
		MAX_POINT_ALPHA = 40,
		MIN_POINT_ALPHA = 0,
	};
private:
	bool isAlpahbetNotCounted(map<char, bool> map, char ch)
	{
		return map.find(ch) == map.end();
	}

	bool isAlphabetSameUsed(map<char, bool> map, char ch)
	{
		return map.find(ch) != map.end();
	}
};
