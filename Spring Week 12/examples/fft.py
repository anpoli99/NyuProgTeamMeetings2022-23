"""
This FFT implementation is taken from KACTL; it is very fast and easy to use.
(although a bit hard to read if you ask me)
I've adapated it to Python but mostly left it as-is.
I've given an example of using it to multiply two polynomials.
"""

import math
import cmath
import sys

def fft(a):
    n = len(a)
    L = n.bit_length() - 1
    R = [1+0j] * 2 + [0+0j] * (n-2)
    rt = [1+0j] * 2 + [0+0j] * (n-2)
    k = 2
    while k < n:
        x = cmath.rect(1, math.pi/k)
        for i in range(k, 2*k):
            R[i] = R[i//2] * x if (i & 1) else R[i//2]
            rt[i] = R[i]
        k *= 2
    rev = [0]*n
    for i in range(n):
        rev[i] = (rev[i//2] | (i&1) << L) // 2
    for i in range(n):
        if i < rev[i]:
            a[i], a[rev[i]] = a[rev[i]], a[i]
    k = 1
    while k < n:
        for i in range(0, n, 2*k):
            for j in range(k):
                z = rt[j+k] * a[i+j+k]
                a[i+j+k] = a[i+j] - z
                a[i+j] += z
        k *= 2

    return a

def conv(a, b):
    if len(a) == 0 or len(b) == 0:
        return []
    res = [0]*(len(a)+len(b)-1)
    L = (len(res)).bit_length() 
    n = 1 << L
    in_ = [0+0j]*n
    out = [0+0j]*n
    for i in range(len(a)):
        in_[i] = a[i]
    for i in range(len(b)):
        in_[i] += b[i]*1j
    in_ = fft(in_)
    for i in range(n):
        in_[i] *= in_[i]
    for i in range(n):
        out[i] = in_[-i & (n-1)] - in_[i].conjugate()
    out = fft(out)
    for i in range(len(res)):
        res[i] = out[i].imag / (4*n)
    return res


# Input: First line should have n and m
# Second line: an n degree polynomial of the form: a_0 + a_1x + a_2x^2 + ... + a_nx^n
# Third line: an m degree polynomial of the form: b_0 + b_1x + b_2x^2 + ... + b_mx^m
n, m = map(int, input().split())
a = list(map(float, input().split()))
b = list(map(float, input().split()))
c = conv(a, b)
print(*c)
