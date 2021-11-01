import re
class Solution:
    def validIPAddress(self, IP: str) -> str:
        ipv4 = re.compile(r'[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+')
        if (bool(ipv4.match(IP)) and ipv4.match(IP)[0] == IP):
            for part in IP.split('.'):
                print(part)
                if int(part) < 0 or int(part) > 255:
                    return "Neither"
                if (len(part) >= 2 and part[0] == '0'):
                    return "Neither"
            return 'IPv4'
        ipv6 = re.compile(r'(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*):(([0-9]|[a-f]|[A-F])*)')
        if (bool(ipv6.match(IP)) and ipv6.match(IP)[0] == IP):
            for part in IP.split(':'):
                if (len(part) < 1 or len(part) > 4):
                    return "Neither"
            return "IPv6"
        
        return "Neither"