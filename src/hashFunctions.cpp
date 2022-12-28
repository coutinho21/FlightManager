#include "Airport.h"


struct eAF {
    bool operator() (const Airport& a1, const Airport& a2) const {
        return a1.getCode() == a2.getCode();
    }
};

struct hAF {
    int operator() (const Airport& a) const {
        string s1 = a.getCode();
        int v = 0;
        for (char i : s1)
            v = 37*v + i;
        return v;
    }
};
