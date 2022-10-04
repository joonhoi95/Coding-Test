n, k = map(int, input().split())

array=[[0,0]]

for _ in range(1, n+1):
    array.append(list(map(int, input().split())))

# Pedding은 정말 위대한 거군요!
backpack = [[0 for _ in range(k+1)] for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1, k+1):
        w = array[i][0]
        v = array[i][1]

        if(j < w):
            backpack[i][j] = backpack[i-1][j]
        else:
            #2가지 값이 있음
            #1. 현재 물건의 가치 + 남은 무게의 최대 가치
            #2. 지금까지 계산한 것중에 최대 가치
            num1 = v + backpack[i-1][j-w]
            num2 = backpack[i-1][j]
            backpack[i][j] = max(num1, num2)

print(backpack[i][j])

