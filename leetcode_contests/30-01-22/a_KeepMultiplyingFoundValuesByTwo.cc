// 	sylxjtu  code
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> m(nums.begin(), nums.end());
        
        while(m.count(original)) {
            original *= 2;
        }
        return original;
    }
};


// my code
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool found = true;
        while(found){
            
            if(find(nums.begin(), nums.end(), original) != nums.end()){
                original *= 2;
            } else{
                found=false;
                return original;
            }
        }
        return original;
    }
};

