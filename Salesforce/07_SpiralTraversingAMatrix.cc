int* spirallyTraverse(int r, int c, int matrix[][c])
{   
    int st = r*c;
    // static int *arr[st];// = new int[r*c];
    int *arr = malloc(sizeof(int) * (r * c));
    int i=0, j=0;
    int k =0;
    int cnt=0;
    int mx = r *c;
    while(i<r && j<c){
        
        int row=i, col=j;
        
        for(; col<c && cnt < mx; col++) {
            arr[k++] = matrix[row][col];
            cnt++;
        }
        row++, col=c-1;
        
        for(; row<r && cnt < mx; row++) {
            arr[k++] = matrix[row][col];
            cnt++;
        }
        row=r-1, col--;
        
        for(; col>= j && cnt < mx; col--){
            arr[k++] = matrix[row][col];cnt++;
        }
        row--, col=j;
        
        for(; row>i && cnt < mx; row--){
            arr[k++] = matrix[row][col];
            cnt++;
        }   
        
        i++, j++;
        r--,c--;
    }
    return arr;
}
