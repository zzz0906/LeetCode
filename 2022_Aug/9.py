class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        total_nums = len(arr)
        moduler = 1000000007
        count_product_dict = {num: 1 for num in arr}
        arr.sort()

        for i in range(1, total_nums):
            for j in range(i):
                quotient = arr[i] // arr[j]
                if quotient < 2:
                    break
                if arr[i] % arr[j] == 0 and quotient in count_product_dict:
                    count_product_dict[arr[i]] += count_product_dict[arr[j]] * count_product_dict[quotient]
                    count_product_dict[arr[i]] %= moduler
        print(count_product_dict)
        return sum(count_product_dict.values()) % moduler