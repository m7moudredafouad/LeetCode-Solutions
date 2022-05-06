class Solution {
public:
    int minTimeToType(string word) {
        char lastPointedChar = 'a';
        int i = 0, dist = 0, score = 0,
        sLen = word.length(),
        fullWay = ('z' - 'a' + 1),
        halfWay = fullWay / 2;

        while(i < sLen) {
            dist = abs(word[i] - lastPointedChar);
            if(dist > halfWay) {
                dist = abs(dist - fullWay);
            }
            
            score += dist;
            lastPointedChar = word[i];
            i++;
        }
        
        return score + sLen;
    }
};