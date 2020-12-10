import subprocess
import filecmp
import time
import pandas as pd
import matplotlib.pyplot as plt
import random
s = ""
N = []
T = []
for i in range(100):
    if i + 1 < 10:
        filename = "input00" + str(i + 1) +".txt"
        filename1 = "output00" + str(i + 1) +".txt"
    elif i + 1 < 100:
        filename = "input0" + str(i + 1) + ".txt"
        filename1 = "output0" + str(i + 1) + ".txt"
    else:
        filename = "input" + str(i + 1) + ".txt"
        filename1 = "output" + str(i + 1) + ".txt"
    f = open("input.txt", "w")
    k = random.randint(1, 10000)
    N.append(k)
    f.write(str(k) + "\n")
    for i in range(k):
        m = random.randint(-1000000, 10000000)
        s += str(m) + " "
    f.write(s)
    f = open(filename, "w")
    f.write(str(k) + "\n" + s)
    s = ""
    subprocess.call("ConsoleApplication29.exe")
    f = open('output.txt', 'r')
    f1 = open(filename1, "w")
    F = f.readlines()
    T.append(int(F[2]))
    for i in range(len(F)):
        f1.write(F[i])
T = sorted(T)
N = sorted(N)
df = pd.DataFrame({'Size': N, 'Time': T})
df['Size'] = pd.to_numeric(df['Size'])
df[['Size','Time']].plot(kind = 'line', x = 'Size', y = 'Time', figsize = (8,6))
plt.show()