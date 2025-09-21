class MovieRentingSystem {
public:
    // Maps movie ID to sorted set of (price, shop) pairs
    // This helps quickly find the cheapest available copies of a movie
    unordered_map<int, set<pair<int, int>>> available;
    
    // Maps movie ID to set of (shop, price) pairs
    // Helps find the price of a movie at a specific shop during rent/drop operations
    unordered_map<int, set<pair<int, int>>> movieShop;
    
    // Sorted set of currently rented movies as (price, shop, movie) tuples
    // Automatically maintains rented movies in sorted order for reporting
    set<tuple<int, int, int>> rented;

    // Constructor: Initializes the system with n shops and movie entries
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            
            // Add to available movies
            available[movie].insert({price, shop});
            // Store shop-price mapping for this movie
            movieShop[movie].insert({shop, price});
        }
    }

    // Search for the cheapest available copies of a movie
    vector<int> search(int movie) {
        vector<int> ans;
        // Check if the movie exists in available inventory
        if (available.count(movie)) {
            int cnt = 0;
            // Iterate through sorted available copies (cheapest first)
            for (auto& [price, shop] : available[movie]) {
                ans.push_back(shop);
                cnt++;
                // Return only the top 5 cheapest shops
                if (cnt == 5) break;
            }
        }
        return ans;
    }

    // Rent a movie from a specific shop
    void rent(int shop, int movie) {
        // Find the price information for this movie at the given shop
        auto it = movieShop[movie].lower_bound({shop, INT_MIN});
        int price = it->second;
        
        // Remove from available inventory
        available[movie].erase({price, shop});
        // Add to rented movies
        rented.insert({price, shop, movie});
    }

    // Return a rented movie to a shop
    void drop(int shop, int movie) {
        // Find the price information for this movie at the given shop
        auto it = movieShop[movie].lower_bound({shop, INT_MIN});
        int price = it->second;
        
        // Add back to available inventory
        available[movie].insert({price, shop});
        // Remove from rented movies
        rented.erase({price, shop, movie});
    }

    // Generate report of cheapest currently rented movies
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        // Iterate through sorted rented movies (cheapest first)
        for (auto& [price, shop, movie] : rented) {
            ans.push_back({shop, movie});
            cnt++;
            // Return only the top 5 cheapest rented movies
            if (cnt == 5) break;
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