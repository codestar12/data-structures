import math


def increasingOrder(n):

    lastDigit = n % 10
    n = math.floor(n/10)

    if n == 0:
        return True

    elif n % 10 < lastDigit:
        lastDigit = n % 10
        if increasingOrder(n):
            return True
    else:
        return False


def reverseOrder(n, reverse=0):

    if(n <= 0):
        return reverse

    reverse = reverse * 10 + n % 10
    return reverseOrder(math.floor(n/10), reverse)


def sumDigits(n):

    mySum = 0
    if n > 0:
        mySum = n % 10 + sumDigits(math.floor(n / 10))
    return mySum


def distVert(n):

    if n > 0:
        distVert(math.floor(n / 10))
        print(n % 10)

print("the numer seq is 4321")
if increasingOrder(4321):
    print("the number seq is in order")
else:
    print("the number sequ is not in order")

print("The reverseOrder order is ", end="")
print(reverseOrder(4321))
print("the sume of digits is ", end="")
print(sumDigits(4321))
print("displaied vertically")
distVert(4321)
