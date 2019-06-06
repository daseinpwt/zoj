from random import randint

N_TEST_CASE = 1
N_PLAN_PER_CASE = 5 

print(N_TEST_CASE)
for i in range(N_TEST_CASE):
    print(N_PLAN_PER_CASE)
    for j in range(N_PLAN_PER_CASE):
        print("%d %d" % (randint(1,400), randint(1,400)))
