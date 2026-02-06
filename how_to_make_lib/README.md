# how to make a library

## compile to an object file.

```sh
cc -c mymath.c -o mymath.o
```


## create static library file.

```sh
ar rcs libmymath.a mymath.o
```

## compile a program with library.

```sh
cc -I. -L. -lmymath -o main main.c
```
