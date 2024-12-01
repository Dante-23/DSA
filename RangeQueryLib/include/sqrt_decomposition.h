#pragma once

#include "common.h"
#include "range_query.h"
#include <math.h>

class sqrt_decomposition : public range_query {
private:
    vector<long long> m_arr;
    vector<long long> m_brr;
    int index;
    void build();
    long long calc(int low, int high);
public:
    sqrt_decomposition(vector<long long> &arr);
    virtual int query(int low, int high);
    virtual void update_at(int index, int value);
    virtual void update_range(int low, int high, int value);
};