import math
class Solution:
    def fractionAddition(self, expression: str) -> str:
        # find minimum common multiple for denominator
        def lcm(a, b):
            return a * b // math.gcd(a, b)
        # find greatest common divisor for numerator and denominator
        def gcd(a, b):
            return math.gcd(a, b)
        # convert string to integer
        def toInt(expression):
            return int(expression)
        # split expressions
        def split(expression):
            return expression.split('/')
        if expression[0] != '-':
            expression = '+' + expression
        numerators = []
        denominators = []
        for i in range(len(expression)):
            next = expression.find('+', i + 1)
            if next == -1:
                next = expression.find('-', i + 1)
            else:
                if expression.find('-', i + 1) != -1:
                    next = min(next, expression.find('-', i + 1))
                    
            if next == -1:
                next = len(expression)
            if expression[i] == '+':
                numerators.append(toInt(split(expression[i + 1:next])[0]))
                denominators.append(toInt(split(expression[i + 1:next])[1]))
            elif expression[i] == '-':
                numerators.append(-1*toInt(split(expression[i + 1:next])[0]))
                denominators.append(toInt(split(expression[i + 1:next])[1]))
        # find lcm
        lcm_denominator = 1
        for i in range(len(denominators)):
            lcm_denominator = lcm(lcm_denominator, denominators[i])
        # sum up numerators
        numerator = 0
        for i in range(len(numerators)):
            numerator += numerators[i] * (lcm_denominator // denominators[i])
        # find gcd
        gcd_numerator = gcd(numerator, lcm_denominator)
        # return result
        return str(numerator // gcd_numerator) + '/' + str(lcm_denominator // gcd_numerator)