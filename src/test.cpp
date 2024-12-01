// #include "/home/haarish/Desktop/gtest/googletest/include/gtest/gtest.h"
// #include "../includes/main.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
using namespace std;

#define MAXN 100001

// TEST(sample_test, test_is_even) {
//     ASSERT_EQ(true, is_even(10));
// }

// TEST(sample_test, sample_test_is_bipartite) {

// }

class Solution {
public:
    int minAddToMakeValid(string s);
};

int Solution::minAddToMakeValid(string s) {
    stack<char> st;
    int res = 0;
    for (char c: s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty()) {
                res++;
            } else {
                st.pop();
            }
        }
    }
    return res + (int) st.size();
}

int main(int argc, char **argv) {
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    string str;
    cin >> str;
    Solution sol;
    cout << sol.minAddToMakeValid(str) << endl;
}