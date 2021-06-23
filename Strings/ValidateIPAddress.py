

#A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses but "192.168.01.1", while "192.168.1.00" and "192.168@1.1" are invalid IPv4 addresses.

#A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

#1 <= xi.length <= 4 xi is a hexadecimal string which may contain digits, lower-case English letter ('a' to 'f') and upper-case English letters ('A' to 'F'). Leading zeros are allowed in xi.
# reference : https://leetcode.com/problems/validate-ip-address/

 def validIPAddress(self, IP: str) -> str:
        if len(IP.split(".")) > 1:
            ipV4 = IP.split(".")
            if len(ipV4) != 4 or ipV4[0][0] == '0':
                return "Neither"
              
            for ele in ipV4:
                if ele.isnumeric() == False or len(ele) > 3:
                    return "Neither"
                if len(ele) > 1 and ele[0] == '0':
                    return "Neither"
                num = int(ele)
                if num > 255 or num < 0:
                    return "Neither"
            return "IPv4"
        
        if len(IP.split(":")) > 1:
            pattern = re.compile("[A-F|a-f|0-9]+")
            ipv6 = IP.split(":")
            if len(ipv6) != 8:
                return "Neither"
            for ele in ipv6:
                if len(ele) > 4 or ele.isalnum() == False:
                    return "Neither"
                if pattern.fullmatch(ele) is None:
                    return "Neither"
            return "IPv6"
        return "Neither"
