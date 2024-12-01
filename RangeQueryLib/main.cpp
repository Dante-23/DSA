#include <iostream>
#include <vector>
#include <math.h>
#include "include/sqrt_decomposition.hpp"
using namespace std;

#define MAXN 200001

int n, index;
long long arr[MAXN];
long long brr[MAXN];

void _build() {
    int sq = (int)(sqrt((double)n));
    for (int i = 0; i < n; i++) {
        brr[i / sq] += arr[i];
    }
    index = (n - 1) / sq + 1;
}

long long _calc(int low, int high) {
    long long sum = 0;
    for (; low <= high; low++) {
        sum += arr[low];
    }
    return sum;
}

long long _query(int low, int high) {
    int sq = (int)(sqrt((double)n));
    int low_block = low / sq, high_block = high / sq;
    long long sum = 0;
    if (low_block == high_block) {
        sum = _calc(low, high);
    } else {
        for (int i = low_block + 1; i < high_block; i++) {
            sum += brr[i];
        }
        sum += _calc(low, (low_block + 1) * sq - 1)
                + _calc(high_block * sq, high);
    }
    return sum;
}

int main() {
    cin >> n;
    vector<long long> inp(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }
    cout << "1" << endl;
    sqrt_decomposition<long long> sqrt_dec(inp);
    cout << "2" << endl;
    while (1) {
        int u, v;
        cin >> u >> v;
        cout << sqrt_dec.query(u, v) << endl;
        // int pos, vl;
        // cin >> pos >> vl;
        // sqrt_dec.update_at(pos, vl);
    }
}