//
// Created by 卢京宇 on 25/5/2024.
//
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class _1255_Maximum_Score_Words_Formed_by_Letters {
public:
    int res;
    std::vector<std::string> words;
    std::vector<int> score;

    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters, std::vector<int>& score) {
        res = 0;
        this->words = words;
        this->score = score;
        std::unordered_map<char, int> hashMap;

        for (char letter : letters) {
            hashMap[letter]++;
        }

        backtracking(0, 0, hashMap);

        return res;
    }

    void backtracking(int i, int currScore, std::unordered_map<char, int>& hashMap) {
        if (i == words.size()) {
            res = std::max(res, currScore);
            return;
        }

        backtracking(i + 1, currScore, hashMap);

        if (canForm(words[i], hashMap)) {
            currScore += countScore(words[i], hashMap);
            backtracking(i + 1, currScore, hashMap);
            recover(words[i], hashMap);
        }
    }

    bool canForm(const std::string& word, std::unordered_map<char, int> hashMap) {
        for (char c : word) {
            if (hashMap[c] <= 0) {
                return false;
            }
            hashMap[c]--;
        }
        return true;
    }

    int countScore(const std::string& word, std::unordered_map<char, int>& hashMap) {
        int s = 0;
        for (char c : word) {
            s += score[c - 'a'];
            hashMap[c]--;
        }
        return s;
    }

    void recover(const std::string& word, std::unordered_map<char, int>& hashMap) {
        for (char c : word) {
            hashMap[c]++;
        }
    }
};