//
// Created by 卢京宇 on 25/5/2024.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
using namespace std;

class _140_Word_Break_II {
public:
    string s;
    unordered_set<string> set;
    vector<string> res;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        set.insert(wordDict.begin(), wordDict.end());

        vector<string> path;
        backtracking(0, path);

        return res;
    }

    void backtracking(int start, vector<string>& path) {
        if (start == s.size()) {
            string sentence;
            for (string& word : path) {
                sentence += word + " ";
            }
            sentence.pop_back();  // 去掉最后一个空格
            res.push_back(sentence);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            string word = s.substr(start, end - start + 1);
            if (set.find(word) != set.end()) {
                path.push_back(word);
                backtracking(end + 1, path);
                path.pop_back();  // 回溯
            }
        }
    }
};
