class LongestMountainArray {
public static void main(String[] args)
{
    int []a = new int[args.length];
    for(int i=0; i<args.length; ++i) {    
        a[i] = Integer.parseInt(args[i]);
    }
    System.out.println(longestMountain(a));
}
    public static int longestMountain(int[] A) {
        int N   = A.length;
        int ans = 0, base = 0;
        
        while (base < N) {
            int end = base;
            
            // if base is a left-boundary
            if (end + 1 < N && A[end] < A[end + 1]) {
            
                // set end to the peak of this potential mountain
                while (end + 1 < N && A[end] < A[end + 1]) end++;

                // if end is really a peak..
                if (end + 1 < N && A[end] > A[end + 1]) {
                
                    // set end to the right-boundary of mountain
                    while (end + 1 < N && A[end] > A[end + 1]) end++;
                    
                    // record candidate answer
                    ans = Math.max(ans, end - base + 1);
                }
            }

            base = Math.max(end, base + 1);
        }

        return ans;
    }
}

