class Solution:
    def nearestPalindromic(self, n: str) -> str:
        even = ['00', '11', '22', '33', '44', '55', '66', '77', '88', '99']
        odd = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        single = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        for i in range(3, len(n) + 1):
            if i % 2 == 0:
                tmp = []
                for value in single:
                    for seq in even:
                        tmp.append(value + seq + value)
                even = tmp
            else:
                tmp = []
                for value in single:
                    for seq in odd:
                        tmp.append(value + seq + value)
                odd = tmp
        if (len(n) % 2 == 0):
            print(even)
            for i in range(len(even)):
                if even[i] >= n:
                    return even[i - 1]
        else:
            for i in range(len(odd)):
                if odd[i] >= n:
                    return odd[i - 1]
s = Solution()
print(s.nearestPalindromic('1213'))