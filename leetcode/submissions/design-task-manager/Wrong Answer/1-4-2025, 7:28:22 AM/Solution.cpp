// https://leetcode.com/problems/design-task-manager

class TaskManager {
public:
    // {priority, taskId} -> userId
    map<pair<int, int>, int> usrd;
    // {priority, taskId} sorted
    set<pair<int, int>> s;
    // marks taskId as destroyed in map
    map<int, bool> destr;
    // taskId -> priority
    map<int, int> ed;
    TaskManager(vector<vector<int>>& tasks) {

        for (auto t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        usrd[{priority, taskId}] = userId;
        s.insert({-priority, taskId});
        ed[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        auto it = s.find({-ed[taskId], taskId});
        s.erase(it);
        ed[taskId] = newPriority;
        s.insert({-ed[taskId], taskId});
    }
    
    void rmv(int taskId) {
        destr[taskId] = true;
    }
    
    int execTop() {
        auto it = s.begin();
        while (destr[it->second]) {
            s.erase(it);
            destr[it->second] = false;
            it = s.begin();
        }
        int ans = usrd[{-it->first, it->second}];
        s.erase(it);
        return ans;
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