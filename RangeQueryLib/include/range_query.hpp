#pragma once

#include "common.hpp"

class range_query {
public:
    virtual int query(int low, int high) = 0;
    virtual void update_at(int index, int value) = 0;
    virtual void update_range(int low, int high, int value) = 0;
};