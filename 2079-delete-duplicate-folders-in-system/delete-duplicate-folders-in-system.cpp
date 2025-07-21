class Solution {
public:
    struct Node {
        string val;
        string sub;
        unordered_map<string, Node*> child;
    };

    Node* getNode(string val) {
        Node* temp = new Node();
        temp->val = val;
        temp->sub = "";

        return temp;
    }

    void insert(Node* root, vector<string>& path) {
        for (auto& folder : path) {
            if (!root->child.count(folder))
                root->child[folder] = getNode(folder);

            root = root->child[folder];
        }
    }

    string populatesNode(Node* root, unordered_map<string, int>& subMap) {
        vector<pair<string, string>> subFloderPath;
        for (auto& [childName, children] : root->child) {
            string subFloderRes = populatesNode(children, subMap);
            subFloderPath.push_back({childName, subFloderRes});
        }

        sort(subFloderPath.begin(), subFloderPath.end());

        string completePath = "";

        for (auto& [childName, childPath] : subFloderPath) {
            completePath += "(" + childName + childPath + ")";
        }
        root->sub = completePath;
        if (!completePath.empty())
            subMap[completePath]++;
        
        return completePath;
    }

    void removeDuplicates(Node* root, unordered_map<string, int>& subMap) {
        for (auto it = root->child.begin(); it != root->child.end();) {
            Node* children = it->second;
            string childName = it->first;

            if (!children->sub.empty() && subMap[children->sub] > 1)
                it = root->child.erase(it);
            else {
                removeDuplicates(children, subMap);
                it++;
            }
        }
    }

    void constructResult(Node* root, vector<string>& path,
                         vector<vector<string>>& res) {
        for (auto& [name, children] : root->child) {
            path.push_back(name);
            res.push_back(path);
            constructResult(children, path, res);
            path.pop_back();
        }
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = getNode("/");

        for (auto& path : paths) {
            insert(root, path);
        }

        unordered_map<string, int> subMap;
        populatesNode(root, subMap);

        removeDuplicates(root, subMap);

        vector<vector<string>> res;
        vector<string> path;

        constructResult(root, path, res);

        return res;
    }
};