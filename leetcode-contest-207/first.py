

class Solution:
    def reorderSpaces(self, text: str) -> str:
        sc = text.count(" ")  # space count
        wl = text.split()  # word list
        wc = len(wl)  # word count
        
        if wc == 1:
            return wl[0] + " " * sc

        rs = sc  # remain space
        es = sc // (wc - 1)  # equal space
        ret = ""
        for word in wl[:-1]:
            ret = ret + word + " " * es
            rs = rs - es
        ret = ret + wl[-1] + " " * rs

        return ret
