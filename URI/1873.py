n = input()
r = 'rajesh'
s = 'sheldon'
e = 'empate'

for kasd in range(n):
    arr = raw_input()
    raj,she = map(str, arr.split())

    if raj.upper() == 'tesoura'.upper():
        if she.upper() == 'papel'.upper() or she.upper() == 'lagarto'.upper():
            print r
        elif she.upper() == 'spock'.upper() or she.upper() == 'pedra'.upper():
            print s
        else:
            print e
    elif raj.upper() == 'papel'.upper():
        if she.upper() == 'pedra'.upper() or she.upper() == 'spock'.upper():
            print r
        elif she.upper() == 'tesoura'.upper() or she.upper() == 'lagarto'.upper():
            print s
        else:
            print e
    elif raj.upper() == 'pedra'.upper():
        if she.upper() == 'tesoura'.upper() or she.upper() == 'lagarto'.upper():
            print r
        elif she.upper() == 'papel'.upper() or she.upper() == 'spock'.upper():
            print s
        else:
            print e
    elif raj.upper() == 'lagarto'.upper():
        if she.upper() == 'spock'.upper() or she.upper() == 'papel'.upper():
            print r
        elif she.upper() == 'tesoura'.upper() or she.upper() == 'pedra'.upper():
            print s
        else:
            print e
    elif raj.upper() == 'spock'.upper():
        if she.upper() == 'tesoura'.upper() or she.upper() == 'pedra'.upper():
            print r
        elif she.upper() == 'lagarto'.upper() or she.upper() == 'papel'.upper():
            print s
        else:
            print e
