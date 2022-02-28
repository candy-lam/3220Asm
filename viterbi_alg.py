"""
CSCI3220 2021-22 First Term Assignment 3
I declare that the assignment here submitted is original except for source
material explicitly acknowledged, and that the same or closely related material
has not been previously submitted for another course. I also acknowledge that I
am aware of University policy and regulations on honesty in academic work, and
of the disciplinary guidelines and procedures applicable to breaches of such
policy and regulations, as contained in the following websites.
University Guideline on Academic Honesty:
http://www.cuhk.edu.hk/policy/academichonesty/
Student Name: Lam Hiu Ching
Student ID : 1155129247
"""

def dcmp(a, b):
    EPS = 1e-14
    temp = a-b
    if temp > EPS:
        return 1
    elif temp < -EPS:
        return -1
    else:
        return 0

#input data
#print("numOfState")
numOfState = int(input())
init_P = []
#print("init_P")
for i in range(numOfState):
    temp = float(input())
    init_P.append(temp)

#print(init_P)

#print("trans_P")
trans_P = []
for i in range(numOfState):
    trans_P.append([])
    for j in range(numOfState):
        temp = float(input())
        trans_P[i].append(temp)

#print(trans_P)

#print("numOfEsymbol")
numOfEsymbol = int(input())
#print("b")
b = []
for i in range(numOfEsymbol):
    temp = input()
    b.append(temp)

#print(b)

#print("emi_P")
emi_P = []
for i in range(numOfState):
    emi_P.append([])
    for j in range(numOfEsymbol):
        temp = float(input())
        emi_P[i].append(temp)

#print(emi_P)

#print("obeser_seq")
obeser_seq = input()
#print(obeser_seq)

#initialize (δ(1,i) = pi_i * e_i(o_1))
table = []
maximum = 0
k = 0
while (obeser_seq[0] != b[k]):
    k += 1
    if k == len(b): break

table.append([])
for i in range(numOfState):
    temp = init_P[i] * emi_P[i][k]
    #print("%.4f * %.4f = %.4f" % (init_P[i] , emi_P[i][k], temp))
    #print(temp)
    table[0].append(temp)
    if (dcmp(temp, maximum) == 1):
        maximum = temp
        s = i
#print(table)

#(δ(t,i) = max_1<=j<=N(δ(t-1,j) * p_ji * e_i(o_t))
for t in range(1, len(obeser_seq)):
    table.append([])
    #reset array and variable
    k = 0 
    #find (b_k)
    while (obeser_seq[t] != b[k]):
        k += 1
        if k == len(b): break
    #print("b[%d]: %s" % (k, b[k]))

    for i in range(numOfState):
        maximum = 0     #reset variable for looping
        #print("i = %d" % i)
        for j in range(numOfState):
            temp = table[t-1][j] * trans_P[j][i] * emi_P[i][k] #δ(t-1,j) * p_ji * e_i(o_t)
            #print("j = %d: %.4f * %.4f * %.4f = %.4f" % (j, table[t-1][j], trans_P[j][i], emi_P[i][k], temp))
            if (dcmp(temp, maximum) == 1): #find max
                maximum = temp
        table[t].append(maximum)
        #print(table)

#produce output by backtracing the table
output = []
for i in reversed(range(0, len(obeser_seq))):
    temp = max(table[i])
    for j in range(numOfState):
        if (dcmp(table[i][j], temp) == 0):
            output.insert(0, "s" + str(j+1))

for i in range(len(output)):
    print(output[i], end =" "),