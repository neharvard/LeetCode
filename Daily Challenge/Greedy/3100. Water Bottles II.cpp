class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles, drink = numBottles;
        numBottles = 0;

        while((numBottles+empty) >= numExchange){
            while(empty >= numExchange){
                numBottles++;
                empty -= numExchange;
                numExchange++;
            }
            // cout<<"bottle: "<<numBottles<<" empty:"<<empty<<" ex:"<<numExchange<<" drink:"<<drink<<endl;
            
            drink += numBottles;
            empty += numBottles;
            numBottles = 0;
        }

        return drink;
    }
};
