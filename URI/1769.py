while True:
    try:
        arr = raw_input()
    except EOFError:
        break

    b1 = int(arr[0]) + int(arr[1])*2 + int(arr[2])*3 + int(arr[4])*4 + int(arr[5])*5 + int(arr[6])*6 + int(arr[8])*7 + int(arr[9])*8 + int(arr[10])*9
    b1 = b1%11
    if b1 == 10:
        b1 = 0

    b2 = int(arr[0])*9 + int(arr[1])*8 + int(arr[2])*7 + int(arr[4])*6 + int(arr[5])*5 + int(arr[6])*4 + int(arr[8])*3 + int(arr[9])*2 + int(arr[10])
    b2 = b2%11
    if b2 == 10:
        b2 = 0

    if b1 == int(arr[12]) and b2 == int(arr[13]):
        print 'CPF valido'
    else:
        print 'CPF invalido'
