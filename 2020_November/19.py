def decodeString(s: str) -> str:
        ans = ''
        for c in s:
            ans += c
            if (c == ']'):
                index = len(ans)-1
                while (ans[index] != '['):
                    index -= 1
                need_repeat = ans[index:][1:-1]
                ans = ans[:index]
                index -= 1
                while (index >= 0 and '0' <= ans[index] <= '9'):
                    index -= 1
                k = int(ans[index+1:])
                ans = ans[:index+1]
                ans += k*need_repeat
        return ans
print(decodeString('3a4[3[b]]'))