Exercise 1. Write an openMP program to initialize an array array of size 32 to all zeros in parallel using 8 threads, using one parallel construct and/or parallel for.

Exercise 2. In addition to what Problem 1 asks, create another parallel construct that adds i to array[i].

Exercise 3. In addition to what Problem 1 and Problem 2 ask, create another parallel construct that calculates the number of even values in array as follows: it distributes the iterations to each thread using cyclic distribution, each thread computes the number of even values from its iterations and master thread collects and adds the number of even values. Master thread then displays the result.
