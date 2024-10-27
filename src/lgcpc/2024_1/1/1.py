n, p = map(int, input().split())
st = input()


def parse(s):
    i = 0
    res = []
    while i < len(s):
        if s[i] == '(':
            j = i
            lv = 1
            while lv != 0:
                j += 1
                if s[j] == '(':
                    lv += 1
                if s[j] == ')':
                    lv -= 1
            res.append(parse(s[i + 1:j]))
            i = j + 1
        elif s[i] == '+' or s[i] == '*':
            res.append(s[i])
            i += 1
        else:
            j = i
            while j < len(s) and s[j].isdigit():
                j += 1
            res.append(s[i:j])
            i = j

    return res


def process(s):
    i = 0
    res = []
    while i < len(s):
        if s[i] == '*':
            res.append([res.pop(), s[i], s[i + 1]])
            i += 2
        else:
            if isinstance(s[i], list):
                res.append(process(s[i]))
            else:
                res.append(s[i])
            i += 1
    return res


def to_string(s):
    if isinstance(s, str) or isinstance(s, int):
        return str(s)
    if isinstance(s, list):
        if len(s) == 1:
            return '(' + to_string(s[0]) + ')'
        res = '(' * (len(s) // 2)
        for i in range(len(s)):
            if i % 2 == 0 and i > 0:
                res += to_string(s[i]) + ')'
            else:
                res += to_string(s[i])
        return res


tree = parse(st)
tree = process(tree)
st = to_string(tree)[1:-1]
print(len(st))
print(st)
