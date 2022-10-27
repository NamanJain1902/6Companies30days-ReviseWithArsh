long long int  atmostK(string &s,int k){
    int i=-1,j=-1;
    int n=s.length();
    long long int count=0,cnt=0;
    vector<int>map1(26,0);
    while(true){
        while(i<n-1){
            i++;
            if(map1[s[i]-'a']==0){
                cnt++;
            }
            map1[s[i]-'a']++;
            if(cnt<=k){
                count+=i-j;
            }
            else{
                break;
            }
        }
        if(i==n-1 and cnt<=k){
            break;
        }
        while(j<i){
            j++;
            map1[s[j]-'a']--;
            if(map1[s[j]-'a']==0){
                cnt--;
            }
            if(cnt<=k){
                count+=i-j;
                break;
            }
        }

    }
    return count;
}
long long int substrCount (string s, int k) {
    //code here.

    return atmostK(s,k)-atmostK(s,k-1);
}
