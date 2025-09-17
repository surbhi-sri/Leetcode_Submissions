class FoodRatings {
public:
    unordered_map < string, set<pair<int, string>>> cuisinRt;
    unordered_map<string, pair<int, string>> foodmp;
    int n;

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        n = foods.size();

        for (int i = 0; i < n; i++) {
            cuisinRt[cuisines[i]].insert({-1*ratings[i], foods[i]});
            foodmp[foods[i]] = {ratings[i], cuisines[i]};
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodmp[food].second;
        int oldRt = foodmp[food].first;

        cuisinRt[cuisine].erase({-1*oldRt, food});

        cuisinRt[cuisine].insert({-1*newRating, food});
        foodmp[food].first = newRating;
    }

    string highestRated(string cuisine) {
        return cuisinRt[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */