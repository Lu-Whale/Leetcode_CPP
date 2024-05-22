//
// Created by 卢京宇 on 23/5/2024.
//
#include <vector>
#include <functional>
using namespace std;


class _131_Palindrome_Partitioning {
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if(s.at(left++) != s.at(right--)) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        int n = s.length();

        // start 表示当前这段回文子串的开始位置
        function<void(int, int)> dfs = [&](int i, int start) {
            if(i == n) {
                res.emplace_back(path);
                return;
            }
            // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
            if(i < n-1) {
                dfs(i+1, start);
            }
            // 选 i 和 i+1 之间的逗号（把 s[i] 作为子串的最后一个字符）
            if(isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1);
                path.pop_back(); //backtracking
            }
        };

        dfs(0, 0);
        return res;
    }
};