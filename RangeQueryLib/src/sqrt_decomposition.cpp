#include "../include/sqrt_decomposition.h"


void sqrt_decomposition::build() {
    int n = (int) m_arr.size();
    int sq = (int)(sqrt((double)n));
    for (int i = 0; i < n; i++) {
        m_brr[i / sq] += m_arr[i];
    }
    index = (n - 1) / sq + 1;
}

long long sqrt_decomposition::calc(int low, int high) {
    long long sum = 0;
    for (; low <= high; low++) {
        sum += m_arr[low];
    }
    return sum;
}

sqrt_decomposition::sqrt_decomposition(vector<long long> &inp) {
    m_arr = inp;
    m_brr.resize(m_arr.size());
    index = 0;
    build();
}

int sqrt_decomposition::query(int low, int high) {
    int n = (int) m_arr.size();
    int sq = (int)(sqrt((double)n));
    int low_block = low / sq, high_block = high / sq;
    long long sum = 0;
    if (low_block == high_block) {
        sum = calc(low, high);
    } else {
        for (int i = low_block + 1; i < high_block; i++) {
            sum += m_brr[i];
        }
        sum += calc(low, (low_block + 1) * sq - 1)
                + calc(high_block * sq, high);
    }
    return sum;
}

void sqrt_decomposition::update_at(int pos, int vl) {
    int n = (int) m_arr.size();
    int sq = (int)(sqrt((double)n));
    m_arr[pos] = vl;
    long long sum = 0;
    for (int i = (pos / sq) * sq; ; i++) {
        if ((i / sq) > (pos / sq) || i >= (int) m_arr.size()) {
            break;
        }
        sum += m_arr[i];
    }
    m_brr[pos / sq] = sum;
}

void sqrt_decomposition::update_range(int low, int high, int vl) {
}