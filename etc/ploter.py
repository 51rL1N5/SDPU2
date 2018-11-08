import numpy as np
import matplotlib.pyplot as plt

dados = open('dados','r').read().split(',')


for i in range(0,len(dados)):
    dados[i] = float(dados[i])

curva = input("Qual tipo da curva(1 ou 2) ?");

if(curva == '1'):
    x = np.linspace(0,30, len(dados))
else:
    x = np.linspace(0,40, len(dados))

y = dados

plt.plot(x,y)
plt.xlabel('t(s)')
plt.ylabel('PWM(%)')
plt.title('Q(t)')

plt.show()
