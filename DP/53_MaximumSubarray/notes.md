
* Case 1: All numbers are negative so we will choose least negative.
* Case 2: All numbers are positive so we will add all of them.
* Case 3: 
    ```c++
    if sum is positive after adding new element
        add current number to old streak 
    else start a new one
        
    new element has two choices :-> this makes it a DP problem.
    *  join the family 
    *  start it's own
    ```