double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code e
    sort(arr, arr + n, [&](Item a, Item b){
        return (1.0*a.value/a.weight > 1.0*b.value/b.weight);
    });
    
    double profit = 0;
    for(int i = 0; (i < n) && (W > 0) ; ++i) {
        if(W - arr[i].weight >= 0) {
            profit += arr[i].value;
            W -= arr[i].weight;
        } else {
            double percentageToBeConsidered = (1.0*W / arr[i].weight);
            profit += (1.0* arr[i].value * percentageToBeConsidered);
            W = 0;        
        }
    }
    return profit;
}