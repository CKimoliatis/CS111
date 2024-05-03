# A Kernel Seedling
This program (written in C) accesses the kernel on this device and retrieves the number of processes currently running. 

## Building
```shell
make
sudo rmmod proc_count
sudo insmod proc_count.ko
```

## Running
```shell
cat /proc/count
```
This returned 188 processes running.
I reran it and it changed to 189.

## Cleaning Up
```shell
make clean
sudo rmmod proc_count
```

## Testing
```python
python -m unittest
```

```shell
cs111@cs111 Documents/Lab0 » python -m unittest
...
----------------------------------------------------------------------
Ran 3 tests in 2.831s

OK
```

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

```shell
uname -r -s -v
```
Kernel Version is:
Linux 5.14.8-arch1-1

```shell
cs111@cs111 Documents/Lab0 » uname -r -s
-v                                                                                                                      130 ↵
Linux 5.14.8-arch1-1 #1 SMP PREEMPT Sun, 26 Sep 2021 19:36:15 +0000
```