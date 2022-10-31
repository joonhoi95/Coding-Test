def solution(ingredient):
    s = ''.join(map(str, ingredient))
    answer = 0
    while s.find('1231') != -1:
        length1 = len(s)
        s = s[:s.find('1231')] + s[s.find('1231')+4:]
        print(s)
        answer += 1

    print(int(answer))

inm = [2, 1, 1, 2, 3, 1, 2, 3, 1]
solution(inm)


s = ''.join(map(str, inm))
print(s)

while s.find('1231') != -1:
    s = s[(s.find('1231')) + 4:]
    print(s[(s.find('1231')) + 4:])



print('finish:',s)


