arr = raw_input()
n = float(arr)
if arr[0] == '-':
    print "%.4E" % n
else:
    print "+%.4E" % n
