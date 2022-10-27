 vector<int> minPartition(int N)
{
    // code here
    vector<int> v;
    vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } ;
    for(int i=coins.size()-1; i>=0; i--) {
        if(N == 0) return v;
        else if(N - coins[i] < 0) continue;
        else {
            while(N - coins[i] >= 0){
                v.push_back(coins[i]);
                N -= coins[i];
            }
        }
    }
    return v;
}