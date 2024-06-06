# Hey! I'm Filing Here

In this lab, I successfully implemented the following, a 1 MiB ext2 file system with 2 directories, 1 symbolic link, and 1 regular file

## Building

To Build the program run:
```shell
make
```

## Running

```shell
./ext2-create 
```
To mount, run: 
```shell
mkdir mnt 
sudo mount -o loop cs111-base.img mnt
```
With this you would:
```shell
cd mnt
ls -ain
```
This will then give me output of:
```shell
total 7
      2 drwxr-xr-x 3    0    0 1024 Jun  5 23:22 .
1087406 drwxr-xr-x 3 1000 1000 4096 Jun  5 23:23 ..
     13 lrw-r--r-- 1 1000 1000   11 Jun  5 23:22 hello -> hello-world
     12 -rw-r--r-- 1 1000 1000   12 Jun  5 23:22 hello-world
     11 drwxr-xr-x 2    0    0 1024 Jun  5 23:22 lost+found
```

## Cleaning up
To unmount:
```shell
sudo umount mnt 
```
To remove mount directory, run: 
```shell
rmdir mnt 
```
To clean up, run: 
```shell
make clean
```


