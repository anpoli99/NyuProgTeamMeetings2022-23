#include<bits/stdc++.h>
using namespace std;

int main(){
    // An unordered_set is a set that stores elements in no particular order.
    // It has O(1) time complexity for insertion, deletion, and search.

    unordered_set<int> s = {1, 2, 3, 4, 5};
    cout << s.count(3) << '\n'; // 1
    cout << s.count(6) << '\n'; // 0

    s.insert(6);
    s.erase(3);
    cout << s.count(3) << '\n'; // 0
    cout << s.count(6) << '\n'; // 1

    // An unordered_map let's you associate a value with a key.
    // It has O(1) time complexity for insertion, deletion, and search.
    unordered_map<string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
    cout << m["one"] << '\n'; // 1
    cout << m.count("four") << '\n'; // 0
    cout << m["four"] << '\n'; // 0 
    m["four"] = 4;
    cout << m.count("four") << '\n'; // 1
    cout << m["four"] << '\n'; // 4

    // A set is a data structure that stores elements in sorted order.
    // It has O(log n) time complexity for insertion, deletion, and search.
    // It also allows lower_bound/upper_bound operations in O(log n) time.
    // lower_bound is inclusive, upper_bound is exclusive.
    set<int> s2 = {1, 5, 7, 9, 11};
    cout << s2.count(7) << '\n'; // 1
    cout << s2.count(8) << '\n'; // 0
    
    auto it = s2.lower_bound(7); //Note about stl; iterators are like pointers
                                // We need to dereference them to get the value
    int lb = *it;
    cout << lb << '\n'; // 7
    it = s2.upper_bound(7);
    int ub = *it;
    cout << ub << '\n'; // 9

    it = s2.lower_bound(8);
    lb = *it;
    cout << lb << '\n'; // 9 -> always goes up

    auto it = prev(s2.lower_bound(8)); // Get value before with prev(lower_bound) 
                                        // Make sure it != s2.begin() first if it's not guaranteed
    lb = *it;
    cout << lb << '\n'; // 7 -> always goes down

    auto it = s2.lower_bound(12);
    cout << (it == s2.end()) << '\n'; // 1 -> if lower_bound is out of bounds, it returns end()

    s.insert(1);
    s.erase(1);
    cout << s.count(1) << '\n'; // 0! sets are unique

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.erase(ms.find(1));
    cout << ms.count(1) << '\n'; // 2
    ms.erase(1);
    cout << ms.count(1) << '\n'; // 0!
    
}