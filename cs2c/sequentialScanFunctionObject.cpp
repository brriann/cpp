// "find max in list" sequential search
// function object, with () operator overload, for isLessThan() syntax

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <string.h>

using std::vector;
using std::string;
using std::less;
using std::cout;
using std::endl;

template<typename Object, typename Comparator>
const Object & findMax(const vector<Object> & arr, Comparator isLessThan)
{
    int maxIndex = 0;

    for (int i = 1; i < arr.size(); ++i)
    {
        if (isLessThan(arr[maxIndex], arr[i]))
        {
            maxIndex = i;
        }
    }
    return arr[maxIndex];
}

// Generic findMax - using default ordering


template<typename Object>
const Object & findMax(const vector<Object> & arr)
{
    return findMax(arr, less<Object>{});
}

class CaseInsensitiveCompare
{
public:
    bool operator()(const string & lhs, const string & rhs) const
    {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

int main()
{
    vector<string> arr = {"ZEBRA", "alligator", "crocodile"};

    cout << findMax(arr, CaseInsensitiveCompare{}) << endl;
    cout << findMax(arr) << endl;

    return 0;
}