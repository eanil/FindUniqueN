This is a sample solution to a process that retuns the largest N ids from a stream of id, value pairs.

# Problem
1426828011 9\
1426828028 350\
1426828037 25\
1426828056 231\
1426828058 109

The app takes in id, value pairs in the format above and returns N ids with largest values from the stream.
You can assume that the entire stream has to be processed to return the values. No querying as you go.
In case of repeating values, it should return the repeating values.

# Code
The structure of the project:
----
    |--README
    |--src
    |   - FindUniqueMax.h       
    |   - FindUniqueMax.cpp
    |-tests
    |   - Tests.cpp
    |-tools
        - FindUniqueMaxN.cpp

The 'src' folder has the algorithms for processing the stream. 
There are two solutions implemented which kind of do the same thing.
The first solution is using a priority_queue to keep a sorted list of items as it goes.
This solution has O(N) memory and O(logN) time complexity.

The second solution is using two stacks to do the same. 
This solution has O(N) memory and O(N^2) at worst O(N) at best.

Both solutions assume the id,value pair will be delimited by a space, tab, or a comma.

The 'tests' folder contains the unit tests I put together for the two algorithms above.

The 'tools' folder contains a executable tool that can be used to process a stream as such:

$> FindUniqueMaxN --n 2 --inputFile testdata.txt

OR

$> ./tools/FindUniqueMaxN --n 2 < ../tests/testdata.txt

Run 'FindUniqueMax --help' to see the options.

# Limitations

There are a couple of ways the solution can be improved. 

1- It would be nice to separate the function doing the actual data processing from the IO handling.

2- Both the stream processor and the data sorting algorithm can be abstracted to work 
with any kind of data. Currently they are written to work strictly with a "string,int" pair.
One can templatize the types and by expect the caller to provide a custom comparator. 

3- Currently, the stream processing is not robust to delays, drops, incomplete data etc.

4- Adding values while continuously querying for values is not supported. One has to wait until the end to 
retrieve the results.

# Building 
This sample was built with cmake (3.16), Boost (1.71), Google test (1.10) installed on the system.

From within your build directory, run cmake and point to this directory:
e.g.,
$> cmake ..

and run 'make' to built all targets or 'make target_name' to build whichever target you need.