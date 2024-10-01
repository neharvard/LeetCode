/*
    Company Tags  : LinkedIn
    Leetcode Link : https://leetcode.com/problems/design-a-stack-with-increment-operation/
*/


/***************************************************************** C++ *****************************************************************/
//Approach-1 (Using Vector as a Stacke) [More Optimized one]
//T.C : push : O(1), pop : O(1), increment : O(1)
//S.C : O(maxSize)

class CustomStack {
public:
    int mxSz;
    vector<int> v;
    CustomStack(int maxSize) { mxSz = maxSize; }

    void push(int x) {
        if (v.size() < mxSz) {
            v.push_back(x);
        }
    }

    int pop() {
        if (v.empty())
            return -1;

        int num = v[v.size() - 1];
        v.pop_back();
        return num;
    }

    void increment(int k, int val) {
        for (int i = 0; i < v.size(); i++) {
            if (k > 0) {
                v[i] += val;
            } else
                break;
            k--;
        }
    }
};


//Approach-2 (Using Stack + vector)
//T.C : push : O(1), pop : O(1), increment : O(1)
//S.C : O(maxSize)
class CustomStack {
public:
int mxSz;
stack<int>st;
    CustomStack(int maxSize) {
        mxSz = maxSize;
    }
    
    void push(int x) {
        if(st.size() < mxSz){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int num = st.top();
        st.pop();
        return num;
    }
    
    void increment(int k, int val) {
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        for(int i=v.size()-1; i>=0; i--){
            if(k>0){
                st.push(v[i]+val);
            }
            else st.push(v[i]);
            k--;
        }
    }
};
