class Router {
public:
    int limit;
    set<pair<int, pair<int, int>>> st;  // for uniquness
    queue<pair<int, pair<int, int>>> q; // for fifo
    unordered_map<int, vector<int>> mp; // for destination wise time map

    Router(int memoryLimit) { limit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        if (st.find({source, {destination, timestamp}}) != st.end())
            return 0;

        if (st.size() == limit)
            forwardPacket();

        st.insert({source, {destination, timestamp}});
        q.push({source, {destination, timestamp}});
        mp[destination].push_back(timestamp);

        return 1;
    }

    vector<int> forwardPacket() {
        if (st.empty())
            return {};

        auto it = q.front();

        int source = it.first;
        int destination = it.second.first;
        int timestamp = it.second.second;

        q.pop();
        st.erase({source, {destination, timestamp}});

       mp[destination].erase(mp[destination].begin());

        return {source, destination, timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        int cnt=0;
        auto &vec=mp[destination];

         auto it1=lower_bound(vec.begin(), vec.end(), startTime);
         auto it2=upper_bound(vec.begin(), vec.end(), endTime);

         return (int)(it2-it1);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */