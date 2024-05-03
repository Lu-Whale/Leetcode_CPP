#include <string>
#include <vector>
#include <iostream>
using namespace std;

class _165_Compare_Version_Numbers {
public:
    int compareVersion(string version1, string version2) {
        const int n1 = version1.size(), n2 = version2.size();

        for(int i = 0, j = 0; i < n1 || j < n2; i++, j++) {
            int x1 = 0, x2 = 0;
            while (i < n1 && version1[i] != '.') {
                x1 = 10 * x1 + (version1[i++] - '0');
            }
            while (j < n2 && version2[j] != '.') {
                x2 = 10 * x2 + (version2[j++] - '0');
            }
            if(x1 < x2) return -1;
            if(x1 > x2) return 1;
        }

        return 0;
    }
};
