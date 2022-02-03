/*
@link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
*/



string encode(string src)
{     
  //Your code here 
  src += "#";
  string res;
  int cnt = 1;
  for(int i=1; i<src.length(); ++i){
      if(src[i] != src[i-1]){
          res.push_back(src[i-1]);
          res += to_string(cnt);
          cnt = 1;
      } else{
          cnt++;
      }
      
  }
  
  return res;
}     
 
