#input number then print out column of '#'
hght = input('Height: ')
while int(hght) < 1 and int(hght) > 8:
    hght = input('Height: ')

temp = []
sq = "#"

for i in range(int(hght)):
    temp.append(sq * (i + 1))

print(temp)
j = 0
space = 1
while j < int(hght):
#for i in range(hght):
    if int(hght) == 1 or j  == int(hght) - 1:
        print(temp[j] + " " + temp[j])
        
    else:
        print((" " * (int(hght) - j - 1) + temp[j] + " " + temp[j]))
        
    
    j += 1


    '''if j == 0:
        print(temp[j] + " " + temp[j])
    else:
        print(" " * z + temp[j] + " " + temp[j])
        z += 1
    j += 1'''
    


