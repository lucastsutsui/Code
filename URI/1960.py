n = input()

romanos = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"]
arabicos = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
i = 12
resp = ""

while n:
    if n >= arabicos[i]:
        resp += romanos[i]
        n -= arabicos[i]
    else:
        i-=1

print resp
