n = int(input())
for asnoda in range(n):
    s1 = raw_input()
    s2 = raw_input()
    
    if s1 == 'pedra':
        if s2 == 'ataque':
            print 'Jogador 2 venceu'
        elif s2 == 'papel':
            print 'Jogador 1 venceu'
        else:
            print 'Sem ganhador'
    elif s1 == 'ataque':
        if s2 == 'pedra':
            print 'Jogador 1 venceu'
        elif s2 == 'papel':
            print 'Jogador 1 venceu'
        else:
            print 'Aniquilacao mutua'
    else: # papel
        if s2 == 'pedra':
            print 'Jogador 2 venceu'
        elif s2 == 'papel':
            print 'Ambos venceram'
        else:
            print 'Jogador 2 venceu'
