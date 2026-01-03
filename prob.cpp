/*
Today's homework is only writing homework, so no code :)
1. An efficient way to simulate the walk in a Markov chain is to
use dynamic programming. The idea is to maintain the probability
distribution, and at each step go through all the possibilities
how we can move. Using this method, we can simulate a walk of m
steps in O(n^2 m) time. - Why does that have to be the time
complexity?

to do this we basically have to repeat a vector-matrix multiplication
m times. we are simulating m total steps, and at each step we calc the
probability for n states. for each calculation we have to look back at
all n previous states. so m * n * n => O(n^2 m) time :)

2. What are Monte Carlo and Las Vegas algorithms?
a. Monte Carlo:
    solving by gambling -> does stuff in a fixed time, but the answer
    MIGHT be wrong :O

    "i'll look for ur keys for just five min. if i cant find them i
    guess they're in the car"
b. Las Vegas:
    solving by speed gambling -> does stuff right, but in random time. 
    so speed might change :O

    "i'll look for ur keys and it might take me 10 sec or 2 hr but i 
    wont stop till i find dem"
*/