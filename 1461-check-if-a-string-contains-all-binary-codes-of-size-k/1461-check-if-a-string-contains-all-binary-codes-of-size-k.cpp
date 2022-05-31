class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int needed_len = 1 << k;
        unordered_map<string, bool> map;
        
        for(int i = 0; i <= (int32_t) s.length()-k; i++) {
            map[s.substr(i, k)] = true;
            if(map.size() == needed_len) return true;
        }
                
        return false;
    }
};