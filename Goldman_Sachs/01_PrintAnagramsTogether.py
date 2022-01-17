from collections import defaultdict

class Solution:
    def Anagrams(self, s, n):
        d = defaultdict(list)

        for idx, string in enumerate(s):
            string = str(sorted(string))
            d[string].append(s[i])
        
        res = []
        for string in d.values():
            res.append(string)

        return res

