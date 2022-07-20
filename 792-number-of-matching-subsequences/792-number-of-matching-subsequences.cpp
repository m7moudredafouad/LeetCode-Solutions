class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha (26);
        int count = 0;
		for (int i = 0; i < s.length(); ++i) 
            alpha[s[i] - 'a'].push_back(i);

		for (const auto& word : words) {
			int x = -1;
			bool found = true;

			for (char c : word) {
				auto it = upper_bound(alpha[c-'a'].begin(), alpha[c-'a'].end(), x);
				if (it == alpha[c-'a'].end()) {
                    found = false;
                    break;
                }
                x = *it;
			}

			if (found) count++;
		}

		return count;
    }
};