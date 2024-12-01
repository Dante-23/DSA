#pragma once

#include "common.hpp"
#include "range_query.hpp"
#include <math.h>

template <typename T> class sqrt_decomposition : public range_query {
private:
    vector<T> m_arr;
    vector<T> m_brr;
    int index;
    void build();
    long long calc(int low, int high);
public:
    sqrt_decomposition(vector<T> &arr);
    virtual int query(int low, int high);
    virtual void update_at(int index, int value);
    virtual void update_range(int low, int high, int value);
};