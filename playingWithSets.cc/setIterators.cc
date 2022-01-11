/*
Set Iterators:

Set iterators offer less features than vector interators.

auto it = s.begin(); // it is the iterator to the first element
it++, it--, ++it, --it -> these are all valid and work in O(logN) time
                                                         -------------

Note: (it + 3) or it+=2 etc are INVALID. To advance multiple steps do
it++ multple times.

Fuctions realated to set iterators:

1. s.find(x): returns iterator to element with value x. Returns s.end() if x not found. O(logN)
2. s.lower_bound(x): returns iterator to the first element which is >= x. Returns x.end() if x not found. O(logN)
3. s.upper_bound(x): returns iterator to the first element which is > x. Returns s.end() is x not found.
4. s.erase(it): erases the element with iteraotr it. O(logN)
5. s.cound(x): returns 1 if x in set else returns 0.


*/
