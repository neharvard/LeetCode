/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/design-a-food-rating-system/
*/

/**************************************** C++ ****************************************/
//Using maps/set as requirement
/*T.C -
FoodRatings - O(n)
changeRating - log(n) due to erase function used in ordered_set
highestRated - O(1)
S.C - O(n) in all maps
*/
class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>>cuisine_ratings_food;
    unordered_map<string, int>food_ratings;
    unordered_map<string, string>food_cuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int sz = foods.size();

        for(int i=0; i<sz; i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            cuisine_ratings_food[cuisine].insert({-rating, food});
            food_ratings[food] = rating;
            food_cuisine[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating = food_ratings[food];

        cuisine_ratings_food[cuisine].erase({-oldRating, food});
        cuisine_ratings_food[cuisine].insert({-newRating, food});
        food_ratings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
