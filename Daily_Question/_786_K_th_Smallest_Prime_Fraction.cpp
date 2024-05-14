// //
// // Created by 卢京宇 on 10/5/2024.
// //
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
//
// struct Fraction {
//     int numerator;
//     int denominator;
//
//     Fraction(int num, int den) : numerator(num), denominator(den) {
//         reduce();
//     }
//
//     void reduce() {
//         int d = gcd(numerator, denominator);
//         numerator /= d;
//         denominator /= d;
//     }
//
//     int gcd(int a, int b) {
//         while (b != 0) {
//             int t = b;
//             b = a % b;
//             a = t;
//         }
//         return a;
//     }
//     // 欧几里得算法的工作原理
//     // 1. 初始化：输入两个非负整数a和b，并假设 a ≥ b 如果不是，算法会在第一次迭代中交换它们）。
//     // 2. 迭代计算：计算a除以b的余数。
//     // 3. 交换数值：将a的值设置为b的值，将b的值设置为步骤2中计算出的余数。
//     // 4. 重复：重复步骤2和3，直到b的值为0。
//     // 5. 结果：此时a的值即为两个数的最大公约数。
// };
//
// class Solution{
// public:
//     int compare(Fraction a,  Fraction b) {
//         long long num1 = static_cast<long long> (a.numerator * b.denominator);
//         long long num2 = static_cast<long long> (b.numerator * a.denominator);
//         return num1 < num2;
//     }
//
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         int n = arr.size();
//         priority_queue<Fraction> pq;
//
//         for(int i = 0; i < n - 1; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 Fraction fraction(arr[i], arr[j]);
//                 if(pq.size() < k) {
//                     pq.push(fraction);
//                 }else if(compare(fraction, pq.top())) {
//                     pq.push(fraction);
//                     pq.pop();
//                 }
//             }
//         }
//         return {pq.top().numerator, pq.top().denominator};
//     }
// };

#include <vector>
using namespace std;

class _786_K_th_Smallest_Prime_Fraction {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }

                total += n - j;

                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }

            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return res;
    }
};


