# Hash Hash Hash
This code implements a thread-safe hash table where each bucket is protected by its own mutex, which allows for conccurent access and modification.

## Building
```shell
make
```

## Running
Enter this:
-t flag changes the number of thread to use 
-s flag changes the number of hash table entries to add per thread
```shell
make
./hash-table-tester -t 8 -s 50000
```
Which will then output
```shell
Generation: 67,902 usec
Hash table base: 803,261 usec
  - 0 missing
Hash table v1: 1,344,736 usec
  - 0 missing
Hash table v2: 508,136 usec
  - 0 missing
```

## First Implementation
In the `hash_table_v1_add_entry` function, I added a mutex to ensure thread-safe access to the has table. Each call to the function locks the global mutex, then does all the other operations like checks if it exists, updates, etc, then in unlocks the mutex. This makes it certain that multiple threds can safely add and update entries in order without corrupting the has table. 

### Performance
Running the tester with the constraints of 1 thread and 450000 entries in each thread can be seen as such:
```shell
make
./hash-table-tester -t 1 -s 450000
```
Where the output was as follows
```shell
Generation: 66,293 usec
Hash table base: 940,506 usec
  - 0 missing
Hash table v1: 1,057,195 usec
  - 0 missing
```

Running a second test with 8 threads and 50000 entries per thread
```shell
make
./hash-table-tester -t 8 -s 50000
```
Where the output was as follows
```shell
Generation: 62,573 usec
Hash table base: 702,775 usec
  - 0 missing
Hash table v1: 1,144,486 usec
  - 0 missing
```
Version 1 is a little slower than the base version. As it has overhead from the mutex used which ensures thread safety.


## Second Implementation
In the `hash_table_v2_add_entry` function, I added a seperate mutex for each bucket in the hash table. Which reduces the threads or processes from competing for the same resource as thus, making it significantly faster. 

### Performance
Running the tester with the constraints of 1 thread and 450000 entries in each thread can be seen as such:
```shell
make
./hash-table-tester -t 1 -s 450000
```
Where the output was as follows
```shell
Generation: 66,293 usec
Hash table base: 940,506 usec
  - 0 missing
Hash table v2: 1,269,811 usec
  - 0 missing
```

Running a second test with 8 threads and 50000 entries per thread
```shell
make
./hash-table-tester -t 8 -s 50000
```
Where the output was as follows
```shell
Generation: 62,573 usec
Hash table base: 702,775 usec
  - 0 missing
Hash table v2: 432,440 usec
  - 0 missing
```
As we can see from the test results, v2 takes a lot less time as compared to the base and even v1. This is mainly due to the fact that contention is reduced significantly making for the ability to run multiple threads at the same time more efficient. The first implementation only allowed one thread to access the hash map at a time, but now every bucket has a mutex and therefore more threads can be ran in parallel. 

## Cleaning up
make clean will remove all unwanted binary files.
```shell
make clean
```