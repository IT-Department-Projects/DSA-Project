# Test Cases 

## Introduction

The following set of instructions can be used to run the Test Cases:

Go to the project directory and in the file where the project directory is try the following commands. 

## Testing commands

Use the following test commands to check for the differences between the expected output and the output that we get. 
If the `cmp` command doesn't give an output that means that is the result that we want. 

Use the `cmp` command to test with the files test241.txt, test242.txt, test243.txt and test244.txt

```
$ cd DSA-Project 
$ cd q24
$ gcc q24.c
$ ./a.out > test1.txt 
$ cmp test1.txt test241.txt
```
Use the `cmp` command to test with the files test361.txt, test362.txt, test363.txt and test364.txt

```
$ cd q36
$ gcc q36.c
$ ./a.out > test1.txt
$ cmp test1.txt test361.txt
```
