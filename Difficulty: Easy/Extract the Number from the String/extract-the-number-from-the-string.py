class Solution:
    def ExtractNumber(self,sentence):
        #code here
        sentence_list = sentence.split(" ")
        number_list = []
        
        for i in sentence_list:
            if (i.isdigit()) and ("9" not in i):
                number_list.append(int(i))
                
        if number_list:
            return max(number_list)
        else:
            return "-1"


#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    S = input()
    ob = Solution()
    ans = ob.ExtractNumber(S)
    print(ans)

# } Driver Code Ends