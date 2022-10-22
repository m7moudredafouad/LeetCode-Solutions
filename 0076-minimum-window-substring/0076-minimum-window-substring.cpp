class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        
        vector<int> map(128, 0);
        for(auto ch : t) map[ch]++;
        
        int counter=t.size(), begin=0, end=0, head=0, dist = INT_MAX;
        
        while(end < s.size()){
            if(map[s[end++]]-- > 0) counter--;
            
            while(counter==0){
                if(end - begin < dist)  dist = end - (head = begin);
                if(map[s[begin++]]++ == 0) counter++;
            }  
            
        }
        
        return dist == INT_MAX ? "" : s.substr(head, dist);
    }
};