arr = raw_input()
a,b,c = map(int,arr.split())

if (a > b and b <= c) or (a < b and b < c and c-b >= b-a) or (a > b and b > c and b-c < a-b) or (a == b and c > b):
    print ':)'
else:
    print ':('
