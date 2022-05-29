class Solution {
    int max(int a, int b) {return a > b ? a : b;}
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size());
        int theMax = 0;
        for(int i = 0; i < words.size(); i++) {
            for(auto c : words[i]){
                bits[i] |= 1 << (c - 'a');
            }
            
            for(int j = 0; j < i; j++) {
                if(!(bits[i] & bits[j]))
                    theMax = max(theMax, words[i].length() * words[j].length());
            }
        }
        
        return theMax;
    }
};