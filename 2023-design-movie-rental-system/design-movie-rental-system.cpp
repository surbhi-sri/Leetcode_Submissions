class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> available;   // movie->{price, shop}
    unordered_map<int, set<pair<int, int>>> movieToShop; // movie->{shop, price}
    set<tuple<int, int, int>> rented;                    // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& it : entries) {
            int shop = it[0];
            int movie = it[1];
            int price = it[2];

            available[movie].insert({price, shop});
            movieToShop[movie].insert({shop, price});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        int cnt = 0;

        if (available.count(movie)) {
            for (auto& [_, shop] : available[movie]) {
                ans.push_back(shop);
                cnt++;
                if (cnt == 5)
                    break;
            }
        }

        return ans;
    }

    void rent(int shop, int movie) {
        auto it = movieToShop[movie].lower_bound({shop, 0});
        int price = it->second;

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        auto it = movieToShop[movie].lower_bound({shop, 0});
        int price = it->second;

         available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        int cnt = 0;
        vector<vector<int>> ans;

        for (auto& [price, shop, movie] : rented){
            ans.push_back({shop, movie});
            cnt++;

            if(cnt>=5) break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */