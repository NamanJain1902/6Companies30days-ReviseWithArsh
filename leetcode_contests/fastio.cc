static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();


/*
The very last pair of parentheses before the semicolon on the last line makes this a call to this lambda function.

* On program startup,

    1. There's a global variable named _____ whose value needs to be assigned.
    2. The programmer wants _____ to be set equal to the value returned by _____
    3. _____ a call to an "anonymous" function that takes no arguments, reconfigures program I/O to run Really Fast, and then returns the (unused and meaningless) value 0 after it's finished,
    4. Which gets called, successfully reconfiguring the cout and cin streams before int main() can even start running.
*/