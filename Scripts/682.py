class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        listvalue = []
        last1 = 0
        last2 = 0
        sum = 0
        for i in range(len(ops)):
            if (ops[i] == '+'):
                sum = listvalue[len(listvalue)-1] + listvalue[len(listvalue)-2] + sum
                listvalue.append(listvalue[len(listvalue)-1] + listvalue[len(listvalue)-2])
            else:
                if (ops[i] == 'C'):
                    sum = sum - listvalue[len(listvalue)-1]
                    listvalue.pop()
                else:
                    if (ops[i] == 'D'):
                        sum = 2 * listvalue[len(listvalue)-1] + sum
                        listvalue.append(listvalue[len(listvalue)-1]*2)
                    else:
                        sum = sum + int(ops[i])
                        listvalue.append(int(ops[i]))
        return sum
