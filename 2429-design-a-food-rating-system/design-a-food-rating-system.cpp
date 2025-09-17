class FoodRatings {
public:
    unordered_map<string, map<int, set<string>, greater<int>>> cuisinRt;
    unordered_map<string, pair<int, string>> foodmp;
    int n;

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        n = foods.size();

        for (int i = 0; i < n; i++) {
            cuisinRt[cuisines[i]][ratings[i]].insert(foods[i]);
            foodmp[foods[i]] = {ratings[i], cuisines[i]};
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodmp[food].second;
        int oldRt = foodmp[food].first;

        cuisinRt[cuisine][oldRt].erase(food);
        if (cuisinRt[cuisine][oldRt].empty())
            cuisinRt[cuisine].erase(oldRt);

        cuisinRt[cuisine][newRating].insert(food);
         foodmp[food].first = newRating;
    }

    string highestRated(string cuisine) {
        return *cuisinRt[cuisine].begin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */