class Solution {
uint64_t div = pow(10, 9) + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        uint64_t maxVal = 0, hori_diff = 0;
        
        for(int i = 1; i < horizontalCuts.size(); i++) {
            uint64_t tmp = horizontalCuts[i] - horizontalCuts[i-1];
            
            if(hori_diff > tmp) continue;
            hori_diff = tmp;
            
            for(int j = 1; j < verticalCuts.size(); j++) {
                tmp = hori_diff * (verticalCuts[j] - verticalCuts[j-1]);
                maxVal = maxVal > tmp ? maxVal : tmp;
            }
        }
        return maxVal % div;
    }
};