class Solution {
public:
    string operation(string& str) {
        string temp = str;

        for (int i = 0; i < temp.size(); i++)
            temp[i] = ((temp[i] - 'a' + 1) % 26) + 'a';

        return (str + temp);
    }

    char kthCharacter(int k) {
        string word="a";

        for (int i = 0; i < k; i++) {
            word = operation(word);
            if (word.size() >= k)
                break;
        }

        return word[k - 1];
    }
};