# You Spin Me Round Robin

This program is a basic implementation of a Round Robin scheduler with the use of the C language. The program does not take any processes but instead takes values from file input such as processes.txt

## Building

Running make will compile and make the file rr (exectutable file) and rr.o 
```shell
make
```

## Running

cmd for running the program 

```shell
make
./rr <FILENAME> <QUANTUM_LENGTH>
Example:
./rr processes.txt 3
```

Results

```shell
./rr processes.txt 3
Average waiting time: 7.00
Average response time: 2.75

```

## Cleaning up

The command below will clean up all executables, outputs, and pycache files.

```shell
make clean 
```
