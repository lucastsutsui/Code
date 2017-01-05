while True:
    try:
        arr = raw_input()
        mes,dia = map(int,arr.split())

        v = [31,29,31,30,31,30,31,31,30,31,30,31]

        dias = dia

        for i in range(mes-1):
            dias += v[i]

        if mes == 12 and dia == 24:
            print 'E vespera de natal!'
        elif mes == 12 and dia == 25:
            print 'E natal!'
        elif mes == 12 and dia > 25:
            print 'Ja passou!'
        else:
            print 'Faltam', 360-dias, 'dias para o natal!'
    except EOFError:
        break
