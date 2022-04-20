class Solution(object):
    def find(self, a):
        if self.parent[a] == -1:
            return a
        self.parent[a] = self.find(self.parent[a])
        return self.parent[a]
    
    def union(self,a,b):
        parent_a = self.find(a)
        parent_b = self.find(b)
        if parent_a == parent_b:
            return True
        self.parent[parent_b] = parent_a
        return False

    def minCostToSupplyWater(self, n, well, pipes):
        self.parent = [-1 for i in range(n+1)]
        counter = 0
        for i in range(len(well)):
            pipes.append([0,i+1,well[i]])
            counter+=1
        pipes = sorted(pipes,key=lambda v:v[2])
        cost  = 0
        for i in pipes:
            #print(i)
            source = i[0]
            destination = i[1]
            temp = i[2]
            if not self.union(source,destination):
                cost+=temp
        return cost

ob = Solution()
print(ob.minCostToSupplyWater(3, [1,2,2], [[1,2,1],[2,3,1]]))