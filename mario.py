#input number then print out column of '#'

s = False

while s == False:
    try :
        hght = input('Height: ')
        hght.isnumeric()
        while int(hght) < 1 or int(hght) > 8:
            hght = input('Height: ')
        s = True
    except ValueError:
        print('is this working?')
        hght = input('Height: ')



    
#stores '#' in a list for later use
temp = []
sq = "#"

for i in range(int(hght)):
    temp.append(sq * (i + 1))


j = 0

while j < int(hght):
    #base case and last row
    if int(hght) == 1 or j  == int(hght) - 1:
        print(temp[j] + "  " + temp[j])
    #prints any other line except base case/last line
    else:
        print((" " * (int(hght) - j - 1) + temp[j] + "  " + temp[j]))
        
    
    j += 1


   


