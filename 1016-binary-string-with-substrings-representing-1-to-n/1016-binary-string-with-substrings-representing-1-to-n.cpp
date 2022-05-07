class Solution {
    unordered_map<int, bool> mymap;
    unordered_map<int, bool> mytrack;

    int min(int a, int b) {return a > b ? b : a;}
    
    void search(string &s, int start, int end, int n) {
        if(start >= end || end > s.length() || mymap.size() == n) return;
        
        unsigned long long curr = stoll(s.substr(start, end - start), nullptr, 2);
        
        while(curr >= 1 && mytrack[curr]==false) {
            if(curr <= n){
                mymap[curr] = true;
            }
            mytrack[curr] = true;
            curr /= 2;
        }
        
        if(s.length() < 30) {
            search(s, start + 1, end, n);
        } else {
            search(s, start + 1, end + 1, n);
        }
    }
    
public:
    bool queryString(string s, int n) {
        search(s, 0, min(s.length(), 30), n);
        cout << mymap.size() << " " << n << endl;
        if(mymap.size() == n) return true;
        return false;
    }
};