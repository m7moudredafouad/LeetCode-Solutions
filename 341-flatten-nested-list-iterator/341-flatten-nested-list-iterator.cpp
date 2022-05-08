/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<NestedInteger> myList;
    stack<pair<vector<NestedInteger>*, int>> myQueue;
    int visited = 0;
    int theNext = INT_MIN;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->myList = nestedList;
    }
    
    int next() {
        return theNext;
    }
    
    bool hasNext() { 
        if(visited >= myList.size() && myQueue.empty()) return false;
        
        while(!myQueue.empty()) {
            pair<vector<NestedInteger>*, int> *tmp = &(myQueue.top());
            
            // If we are currently processing the last member
            if(tmp->second + 1 >= (*tmp->first).size()) {
                myQueue.pop();
                
                if((*tmp->first).size() == 0) {
                    return this->hasNext();
                }
            }
            
            if((*tmp->first)[tmp->second].isInteger()) {
                theNext = (*tmp->first)[tmp->second++].getInteger();
                return true;
            } 

            myQueue.push(make_pair(&((*tmp->first)[tmp->second++].getList()), 0));

            return this->hasNext();
        }
        
        // handle the overall array
        if(myList[visited].isInteger()) {
            theNext = myList[visited++].getInteger();
            return true;
        } else {
            myQueue.push(make_pair(&(myList[visited++].getList()), 0));
            return this->hasNext();

        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */