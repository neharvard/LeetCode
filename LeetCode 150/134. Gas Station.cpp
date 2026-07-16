/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/gas-station/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (BruteForce, it gives TLE)
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();

        for(int i=0; i<sz; i++){
            int tank = gas[i];
            bool ok = true;
            for(int j=i; j<sz; j++){
                if(tank < cost[j]){
                    ok = false;
                    break;
                }

                if(j == sz-1){
                    tank = tank - cost[j] + gas[0];
                    continue;
                }

                tank = tank - cost[j] + gas[j+1];
            }
            // cout<<"t1: "<<tank<<endl;

            if(ok){
                for(int j=0; j<=i; j++){
                    if(tank < cost[j]){
                        ok = false;
                        break;
                    }

                    if(j == sz-1){
                        tank = tank - cost[j] + gas[0];
                        continue;
                    }

                    tank = tank - cost[j] + gas[j+1];
                }

                // cout<<"t2: "<<tank<<" ok: "<<ok<<endl;
            }

            if(ok) return i;
        }

        return -1;
    }
};


//Approach-2 (Using Observation)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();

        int totalGas = 0, totalCost = 0;
        for(int i=0; i<sz; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        // cout<<"gas: "<<totalGas<<" cost: "<<totalCost<<endl;
        if(totalGas < totalCost) return -1;

        int start = 0, currGas = 0;
        for(int i=0; i<sz; i++){
            currGas += gas[i] - cost[i]; 
            // cout<<"I: "<<i<<" cur:"<<currGas<<endl;

            if(currGas < 0){
                start = i+1, currGas = 0;
            }
        }

        return start;
    }
};


//Approach-3 (More Optimized code writting, Using Observation)
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sz = gas.size();

        int totalGas = 0, totalCost = 0;
        int start = 0, currGas = 0;
      
        for(int i=0; i<sz; i++){
            totalGas += gas[i];
            totalCost += cost[i];

            currGas += gas[i] - cost[i]; 
            // cout<<"I: "<<i<<" cur:"<<currGas<<endl;

            if(currGas < 0){
                start = i+1, currGas = 0;
            }
        }
        if(totalGas < totalCost) return -1;

        return start;
    }
};
