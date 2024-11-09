/*
    Leetcode Link               : https://leetcode.com/problems/minimum-array-end/description/
*/

/******************************************************** C++ ********************************************************/
//Approach-1: BruteForce [ which got TLE ]
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
#define ll long long
#define pb push_back

    long long minEnd(int n, int x) {
        ll cnt = 1, temp = x, ans;
        if (n == 1) return x;

        vector<ll> v;
        for (ll bitPos = 0; bitPos < 32; bitPos++) {
            ll bit = (temp & (1 << bitPos));
            if (bit != 0) v.pb(bitPos);
        }

        while (temp++) {
            // cout << "t:" << temp << endl;
            ll bit, ok = 0;

            for (ll i = 0; i < v.size(); i++) {
                bit = (temp & (1 << v[i]));
                // cout<<"bit:"<<bit<<endl;
                if (bit == 0) {
                    ok = 1;
                    break;
                }
            }

            if (!ok) cnt++;

            // cout << "cnt:" << cnt << endl;
            if (cnt == n) {
                ans = temp;
                break;
            }
        }
        return ans;
    }
};


//Approach-2: Simple using AND and OR
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
#define ll long long
#define pb push_back
  
     long long minEnd(int n, int x) {
         ll num = x;

         for(int i=1; i<n; i++){
             num = (num + 1) | x; //cout<<"n:"<<num<<endl;
         }
         return num;
     }
};


//Approach-3: working on each Bit [ Most Effective ]
//T.C : O(64)
//S.C : O(64)
class Solution {
public:
#define ll long long
#define pb push_back

        long long minEnd(int n, int x) {
           n--;
           vector<ll>xBit(64), nBit(64);

           for(int i=0; i<32; i++){
               xBit[i] = 1 & (x >> i);
               nBit[i] = 1 & (n >> i);
           }

           // for(auto &el : xBit) cout<<el<<" "; cout<<endl;
           // for(auto &el : nBit) cout<<el<<" "; cout<<endl;

           ll i = 0, j = 0, ans = 0;
           while(i < 64){
               if(xBit[i] != 1){
                   xBit[i] = nBit[j];
                   j++;
               }
               i++;
           }

           // for(auto &el : xBit) cout<<el<<" "; cout<<endl;

           for(i=0; i<64; i++){  //cout<<xBit[i]<<" "<<(1ll << i)<<endl;
               ans += (xBit[i] * (1ll << i));
           }
           return ans;
       }
};
