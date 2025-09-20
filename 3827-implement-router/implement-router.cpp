class Router {
public:
    int limit;
    queue<pair<int, pair<int, int>>> que;
    unordered_map<int, vector<pair<int, int>>> mp; 
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        
        if(mp.find(destination) != mp.end()) {
            for(auto it : mp[destination]) {
                if(it.first == source && it.second == timestamp) return false;
            }
        }
        if(que.size() >= limit) {
            auto it = que.front();
            int ts = it.first;
            int src = it.second.first;
            int dst = it.second.second;
            mp[dst].erase(mp[dst].begin());
            que.pop();
        }
        que.push({timestamp, {source, destination}});
        mp[destination].push_back({source, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if(que.empty()) return {};
        auto it = que.front();
        que.pop();
        int timeStamp = it.first;
        int src = it.second.first;
        int dst = it.second.second;
        mp[dst].erase(mp[dst].begin());

        return {src, dst, timeStamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (mp.find(destination) == mp.end()) {
            return 0;
        }

        auto& events = mp[destination];

        auto lower = lower_bound(events.begin(), events.end(), startTime, 
            [](const pair<int, int>& p, int val) {
                return p.second < val;
            });

        auto upper = std::upper_bound(events.begin(), events.end(), endTime,
            [](int val, const std::pair<int, int>& p) {
                return val < p.second;
            });

        return upper-lower;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */