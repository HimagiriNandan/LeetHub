class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        total = 0
        for i in patterns:
            if(i in word):
                total+=1
        return total