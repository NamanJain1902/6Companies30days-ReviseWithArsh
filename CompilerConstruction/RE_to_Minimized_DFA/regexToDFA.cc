/**
* @author NamanJain1902
* @link https://www.linkedin.com/in/naman-jain1902/
*/

#include<bits/stdc++.h>
#include "reg_c.h"
#include "reg_c.cc"
using namespace std;

/*
TODO: Convert given regular expression to minimized DFA.

Steps:

1. Convert R.E. to NFA using Thomson Construction method.
2. Convert obtained NFA to DFA using subset construction.
3. Minimize this DFA.

Detailed Explanation:

Step1 (R.E. to NFA):

    a. Add '.' symbol to show concatenation in string.
*/

int main() {
    string regexp;
    cout << "Enter a regular expression: ";
    cin >> regexp;

    REG_C re(regexp);

    // Step 1: R.E to NFA

    /*
        1. Adding some additional information to given regexp.
           to know where to concatenate.
    */    
    re.preprocess();
    string preprocessed_regexp = re.get_preprocessed_re();

    cout << "Preprocessed R.E. is ";
    cout << preprocessed_regexp << endl;
    
    
    // string posfix_regexp = toPostfix(preprocessed_regexp);
}