class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool in1 = (rec2[0] < rec1[2]) && (rec2[2] > rec1[0]);
        
        bool in2 = (rec2[1] < rec1[3]) && (rec2[3] > rec1[1]);
        
        return in1 && in2;
    }
};