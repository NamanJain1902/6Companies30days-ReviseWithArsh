class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ret;
        string tmp;
        int i;
        ret.clear();
        for (i=0;i<s.length();i+=k)
        {
            tmp=s.substr(i,k);
            while (tmp.length() < k) tmp.push_back(fill);
            ret.push_back(tmp);
        }
        return ret;
    }
};


class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {
		vector <string> a;
		for(int i = 0; i < s.size(); i++) {
			if(i % k == 0) {
				a.push_back("");
			}
			a.back() += s[i];
		}
		while(a.back().size() < k) a.back() += fill;
		return a;
	}
};

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> vs;
        if(s.length() < k){
            string ss;
        
            for(int i=0; i<s.length(); ++i){
                ss.push_back(s[i]);            
                k--;
            }
            while(k){
                ss.push_back(fill);
                k--;
            }
            vs.push_back(ss);
            return vs;
        }
        
        int t = 0;
        for(int i=0; i<s.length()-k;  i+=k){
            string ss;
            t = i;
             ss = s.substr(i, k);
            t += k;
            vs.push_back(ss);
        }
        int xc = s.length() - k;
        string ss;
        
        for(int i=t; i<s.length(); ++i){
            ss.push_back(s[i]);            
            k--;
        }
        while(k){
            ss.push_back(fill);
            k--;
        }
        vs.push_back(ss);

        
        return vs;
    }
};