n = input()
trad = dict()
for i in range(n):
    lin = raw_input()
    msg = raw_input()
    trad[lin] = msg
m = input()
for i in range(m):
    nome = raw_input()
    ling = raw_input()
    print nome
    print trad[ling]
    print
