class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0, lastUps = 0, lastDowns = 0, topPrev = 0;
        for(int i = 1; i < ratings.size(); i++) {
            
            if(ratings[i-1] < ratings[i]) {
                lastUps++;
                topPrev = lastUps;
                lastDowns = 0;
                sum += lastUps;
            } else if(ratings[i-1] == ratings[i]) {
                lastUps = lastDowns = topPrev = 0;
            } else {
                lastDowns++;
                sum += lastDowns + (lastDowns <= topPrev ? -1 : 0);
                lastUps = 0;
            }
        }
        
        return sum + ratings.size();
    }
};