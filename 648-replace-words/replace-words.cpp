class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;

        int n = dictionary.size();

        for (int i = 0; i < n; i++)
            st.insert(dictionary[i]);

        stringstream ss(sentence);
        string word;
        string res;

        while (getline(ss, word, ' ')) {
            string str;
            int found = 0;
            for (char ch : word) {
                str += ch;
                if (st.find(str) != st.end()) {
                    found = 1;
                    res += str + " ";
                    break;
                }
            }
            if (found)
                continue;
            else
                res += word + " ";
        }

        res.pop_back();

        return res;
    }
};