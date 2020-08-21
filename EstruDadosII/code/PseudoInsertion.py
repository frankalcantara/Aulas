def ordene(A):
    for i = 1 até n-1
    inserte(A, i, A[i])


def inserte(A, posição, valor):
    i = posição - 1
    while (i >= 0 E A[i] > valor) do
    A[i+1] = A[i]
    i = i-1
