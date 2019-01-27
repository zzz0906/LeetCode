class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        dict = {}
        for i in candies:
            if i in dict:
                dict[i] = dict[i] + 1
            else:
                dict[i] = 1
        if (len(dict) > int(len(candies)/2)):
            return int(len(candies)/2)
        else:
            return len(dict)
