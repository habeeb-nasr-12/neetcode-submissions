class Solution
{
public:
	bool isAnagram(string s, string t)
	{
        if(s.size()!= t.size())
        return false;
		unordered_map<char, int> anagramSetS;
		unordered_map<char, int> anagramSetT;
		for (int i = 0; i < s.size(); i++)
		{
			anagramSetS[s[i]]++;
		}
        // 	for (int i = 0; i < t.size(); i++)
		// {
		// 	anagramSetT[t[i]]++;
		// }


		for (int i = 0; i < t.size(); i++)
		{
			if (!anagramSetS.count(t[i]) || anagramSetS[t[i]] == 0)
				return false;
			anagramSetS[t[i]]--;
		}

        // 	for (int i = 0; i < s.size(); i++)
		// {
		// 	if (!anagramSetT.count(s[i]) || anagramSetT[s[i]] == 0)
		// 		return false;
		// 	anagramSetT[s[i]]--;
		// }

		return true;
	}
};
