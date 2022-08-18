class Solution:
    def nearestPalindromic(self, n: str) -> str:
        """
        1. The nearest palindrome falls into the boundary of
            [10 ** (maxLen - 1) - 1, 10 ** maxLen + 1].
        2. We should only consider the change on the first half part of n and
            reverse it to the second half of n as this will give us smaller
            results.
        3. Then we we take the first half part of n and add 1, add 0 or add -1
            to it, then reverse it to the second half to create the palindrome
            candidates.
        4. Then we compare all the candidates distance against n. Notice that
            if n is already a palindrome, it should be excluded from the above
            comparison.
        """
        maxLen, N = len(n), int(n)

        # Calculate bounds first.
        low, high = 10 ** (maxLen - 1) - 1, 10 ** maxLen + 1

        # Calculate remaining candidates.
        isOddLen = maxLen & 1
        firstHalf = int(n[:(maxLen >> 1) + isOddLen])
        smaller = int(str(firstHalf - 1) + str(firstHalf - 1)[-1-isOddLen::-1])
        same = int(str(firstHalf) + str(firstHalf)[-1-isOddLen::-1])
        larger = int(str(firstHalf + 1) + str(firstHalf + 1)[-1-isOddLen::-1])

        # Compare all the above results.
        if same == N:  # n is already a palindrome.
            return str(min(
                [low, high, smaller, larger],
                key=lambda x: (abs(x - N), x)))
        else:
            return str(min(
                [low, high, smaller, same, larger],
                key=lambda x: (abs(x - N), x)))