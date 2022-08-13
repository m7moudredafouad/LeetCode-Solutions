class Solution {

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.length(), wordLen = words[0].length(), wordsLen = words.size();
        vector<int> foundIndex;
        
        unordered_map<string, int> map;
        for(auto word : words) map[word] = (map.count(word) ? map[word] : 0) + 1;
        
        for(int i = 0; i < sLen - wordLen * wordsLen +1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            
            while(j < wordsLen) {
                string tmp = s.substr(i + j * wordLen,wordLen);

                if(map.count(tmp) > 0) {
                    seen[tmp] =  (seen.count(tmp) ? seen[tmp] : 0) + 1;
                    if(seen[tmp] > map[tmp]) break;
                    
                } else {
                    break;
                }
                
                j++;
            }
            
            if (j == wordsLen) foundIndex.push_back(i);

        }

        return foundIndex;
    }
};