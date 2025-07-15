# SPL01_Utilities

This repository contains basic Linux utilities written in C. These utilities include:

- **echo**: Prints the input text entered in the terminal to standard output.
- **mv**: Moves the source file to a destination path. If the destination file doesn't exist, it is created.
- **cp**: Copies a source file to a destination path. If the destination file doesn't exist, it is created.
- **pwd**: Prints the absolute path of the current directory.

## How to use these utilities

Before using any utility, compile the corresponding C source file using `gcc`:

```
gcc source_file.c -o <name_of_executable>
```

### echo utility

To compile the echo utility:

```
gcc echo.c -o myecho
```

To run the command, execute it in the same directory as the compiled binary:

```
./myecho "input_text"
```

For example, to print "Hello world":

```
./myecho Hello world
```

Output:

```
Hello world
```

<img width="578" height="42" alt="image" src="https://github.com/user-attachments/assets/b4244996-359d-4a99-95c4-ceef7bf59d68" />

### mv utility

After compiling the `mv` utility, use it as follows:

```
./mymv <source_path> <destination_path>
```

<img width="1238" height="323" alt="image" src="https://github.com/user-attachments/assets/9d2ecde0-4441-4eba-8ebc-05ce22ee05dd" />

- The first command gives an error: `Could not move the source file, error 2` — which refers to `ENOENT` (No such file or directory) from `errno.h`.
- The fourth command results in `error 20` (`ENOTDIR`), meaning the destination should be a file, not a directory.
- The remaining commands show successful movement of `myecho.c` to `Documents/copy_myecho.c`.

<img width="575" height="48" alt="image" src="https://github.com/user-attachments/assets/b5d81061-de6e-467a-93ba-4b7a25d151a7" />

As shown above, if only one argument is provided (e.g., source path), the command prompts for the missing destination argument.

### cp utility

To compile and use the `cp` utility:

```
gcc cp.c -o mycp
./mycp <source_path> <destination_path>
```

<img width="1123" height="648" alt="image" src="https://github.com/user-attachments/assets/4d9329be-19da-4d3e-a942-a0cfcf7319dc" />

- The first command fails because the specified source file does not exist (`error 2`).
- The second command fails because the destination is a directory, but a file path is expected.
- The remaining commands demonstrate successful copying of the file to the destination.

**source file:**

<img width="867" height="907" alt="image" src="https://github.com/user-attachments/assets/04258e05-0f9a-4dd8-aba6-d4bf11c70306" />

**copied file:**

<img width="864" height="932" alt="image" src="https://github.com/user-attachments/assets/5f507672-5a4c-441f-b9ab-9228c179aad9" />

### pwd utility

To compile and use the `pwd` utility:

```
gcc pwd.c -o mypwd
./mypwd
```

This will print the absolute path of the current working directory.

<img width="683" height="242" alt="image" src="https://github.com/user-attachments/assets/5547b8f9-4b2b-420c-9582-27b9e4b7c9fa" />
