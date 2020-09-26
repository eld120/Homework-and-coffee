'''Luhn’s Algorithm
So what’s the secret formula? Well, most cards use an algorithm invented 
by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine 
if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last 
digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 
10 is congruent to 0), the number is valid!'''

credit = input('Please input a valid credit card number: ')

validnum = int(credit)

cardlength = int(len(credit)) - 2
card2 = int(len(credit)) - 1
sum = 0
#multiply every other digit by 2
while cardlength >= 0:
    temp1 = credit[cardlength]
    temp =  int(temp1) * 2
    zing = str(temp)
    for i in range(len(zing)):
        sum = sum + int(zing[i])
    cardlength -= 2

#sum the remainder of the digits in the card number
sum2 = 0
while card2 >= 0:
    temp2 = credit[card2]
    sum2 =  sum2 + int(temp2)
    card2 -= 2

#total of sum and sum2
sum = sum + sum2

if sum % 10 == 0 and int(credit[0:2]) > 50 and int(credit[0:2]) < 56:
    print('MASTERCARD') 
elif sum % 10 == 0 and int(credit[0]) == 4:
    print('VISA')
elif sum % 10 == 0 and int(credit[0:2]) == 37 or int(credit[0:2]) == 34:
    print('AMEX')
else:
    print('INVALID')