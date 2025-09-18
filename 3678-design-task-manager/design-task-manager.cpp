class TaskManager {
public:
    set<pair<int, int>> taskTop;
    unordered_map<int, pair<int, int>> taskMp;

    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int>& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMp[taskId] = {userId, priority};
        taskTop.insert({-priority, -taskId});
    }

    void edit(int taskId, int newPriority) {
        int oldP = taskMp[taskId].second;
        taskTop.erase({-oldP, -taskId});
        taskTop.insert({-newPriority, -taskId});
        taskMp[taskId].second = newPriority;
    }

    void rmv(int taskId) {
        int oldP = taskMp[taskId].second;
        taskTop.erase({-oldP, -taskId});
        taskMp.erase(taskId);
    }

    int execTop() {
        if (taskTop.empty())
            return -1;

        auto top_ele = *taskTop.begin();

        int taskId = -1 * top_ele.second;
        int userId = taskMp[taskId].first;

        rmv(taskId);

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */