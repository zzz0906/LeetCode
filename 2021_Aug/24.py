class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        x1 = int(re.match("-*[0-9]+\+",num1)[0][:-1])
        y1 = int(re.search("-*[0-9]+i",num1)[0][:-1])
        x2 = int(re.match("-*[0-9]+\+",num2)[0][:-1])
        y2 = int(re.search("-*[0-9]+i",num2)[0][:-1])
        print(x1,y1,x2,y2)
        return "{}+{}i".format(x1*x2 - y1*y2, x1*y2 + y1*x2)