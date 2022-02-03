class Solution:
    def calculate(self, s: str) -> int:
        s = s.replace(' ','')
        stack = []
        for c in s:
            if (c != ')'):
                stack.append(c)
            else:
                tmp = 0
                cur = stack.pop()
                last = 0
                while (cur != '('):
                    if (cur >= '0' and cur <= '9'):
                        tmp_s = cur
                        cur = stack.pop()
                        while (cur >= '0' and cur <= '9'):
                            tmp_s = cur + tmp_s
                            cur = stack.pop()
                        last = int(tmp_s)
                    else:
                        if (cur == '-'):
                            tmp -= last
                        else:
                            tmp += last
                        cur = stack.pop()
                # (4 + ...)
                tmp += last
                if (tmp < 0):
                    if (len(stack) > 0):
                        tmp_c = stack.pop()
                        if (tmp_c == '+'):
                            stack.append('-')
                        else:
                            stack.append('+')
                    if (len(stack) == 0):
                        stack.append('-')
                    for c in str(tmp):
                        if (c == '-'):
                            continue
                        stack.append(c)
                if (tmp == 0):
                    stack.pop()
                if (tmp > 0):
                    for c in str(tmp):
                        stack.append(c)
        if (len(stack) == 0):
            return 0
        #print(stack)
        tmp = 0
        cur = stack.pop()
        last = 0
        if (len(stack) == 0):
            return int(cur)
        flag = False
        last_op = ""
        while (True):
            if (cur >= '0' and cur <= '9'):
                tmp_s = cur
                if (len(stack) == 0):
                    last_op = 'num'
                    last = int(tmp_s)
                    break
                cur = stack.pop()
                while (cur >= '0' and cur <= '9'):
                    tmp_s = cur + tmp_s
                    print(tmp_s)
                    if (len(stack) == 0):
                        last_op = 'num'
                        flag = True
                        break
                    cur = stack.pop()
                last = int(tmp_s)
                last_op = 'num'
            else:
                if (cur == '-'):
                    tmp -= last
                else:
                    tmp += last
                last_op = 'sym'
                if (len(stack) == 0):
                    break
                cur = stack.pop()
            if (flag):
                break
        if (last_op != 'sym'):
            tmp += last
        return tmp
                    