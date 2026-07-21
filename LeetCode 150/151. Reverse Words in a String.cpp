/*
    Company Tags                 : Amazon (With variations), Microsoft, MentorGraphics, MakeMyTrip, Accolite, Adobe, Cisco, Goldman Sachs,Paytm, 
                                   Samsung, SAP Labs
    Leetcode Link                : https://leetcode.com/problems/reverse-words-in-a-string/
*/

//Approach-1: My initial approach
class Solution {
public:
    string reverseWords(string s) {
        int sz = s.size();

        string temp;
        string ans;
        for(int i=sz-1; i>=0; i--){
            // cout<<"i:"<<i<<" s:"<<s[i]<<endl;

            while(i>=0 && s[i] == ' '){
                if(temp != ""){
                    reverse(begin(temp), end(temp));
                    // cout<<"temp:"<<temp<<"#"<<endl;

                    ans += temp + ' ';
                    temp = "";
                }

                i--;
            }

            if(i>=0) temp += s[i];
        }        

        int n = temp.size();
        // cout<<"ans:"<<ans<<"#tt:"<<temp<<"n:"<<n<<endl;

        if(n > 0){
            reverse(begin(temp), end(temp));
            ans += temp;
        } 
        else{
            n = ans.size();
            ans.erase(n-1, 1);
        }

        return ans;
    }
};
