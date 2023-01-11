# pipex :

**`fork(), wait(), pipe(), dup2(), and execve():`**

1. **`Create a pipe using the pipe() function.`**
2. **`Create a child process using the fork() function.`**
3. **`In the child process:`**
    1. `Close the write end of the pipe.`
    2. `Redirect the standard input of the child process to the read end of the pipe using the dup2() function.`
    3. `Close the read end of the pipe.`
    4. `Execute a new program using the execve() function, passing the standard input of the child process as an argument.`
4. **`In the parent process:`**
    1. `Close the read end of the pipe.`
    2. `Write data to the pipe using the write() function.`
    3. `Close the write end of the pipe.`
    4. `Wait for the child process to finish using the wait() function.`

![zom.png](pipex%20f3f377eedb644f1a805c6f479d7576c0/zom.png)

# pipe | :

`a pipe is a data structure that allows data to be transferred between processes. A pipe is a unidirectional data channel, meaning that data can be transferred in only one direction through the pipe`.

[Process : ](pipex%20f3f377eedb644f1a805c6f479d7576c0/Process%205489eb2fa3234436838be5c8933e078e.md)

[fork()](pipex%20f3f377eedb644f1a805c6f479d7576c0/fork()%20aa6a96924d494ade9ea095fce3c0c07e.md)

- wait()
    
    `The `**`wait():`**`
     function is typically used in conjunction with the `**`fork()`**`
     function, which is used to create child processes. It is an important part of the process management system in Unix-like operating systems.`*
    
    `wait() is that allows a parent process to wait for one of its child processes to terminate. When a parent process calls `**`wait()`**`, it blocks (i.e., stops execution) until one of its child processes exits, at which point `**`wait()`**` returns the child's exit status to the parent process.`
    
- pipe
    
    `pipes can be created using the `**`pipe()`**` function, which is declared in the `**`unistd.h`**`
     header file. The `**`pipe()`**` function creates a pipe and returns a pair of file descriptors that refer to the ends of the pipe. One process writes data to the pipe using the write end of the pipe (which is represented by the first file descriptor in the pair), while the other process reads data from the pipe using the read end of the pipe (which is represented by the second file descriptor in the pair).`
    
    `fd[0] → write`
    
    `fd[1] → read`
    
- dup /dup2
    
    `dup` is a Unix system call that creates a new file descriptor for an existing file. It allows a process to create multiple references to a single file, each with a different file descriptor.*`
    
    `The `**`dup()`**` function takes a file descriptor as an argument, and it returns a new file descriptor that refers to the same file. The new file descriptor has the lowest available file descriptor number that is greater than or equal to 0.`
    
    `dup2 is a Unix system call that creates a new file descriptor for an existing file. It is similar to the `dup() function, but it allows the caller to specify the file descriptor number to be used for the new file descriptor.`
    
    `*The `**`dup2()`**` function takes two arguments: the file descriptor of the existing file, and the file descriptor number to be used for the new file descriptor. It returns the new file descriptor number if successful, and -1 if an error occurs.*`
    
- exit()
    
    `exit() is a function in the C standard library that terminates the calling process and returns an exit status to the operating system. The exit status is an integer value that is typically used to indicate the success or failure of the process, or to provide additional information about the process' termination.*`
    
    `The exit() function takes an integer argument, which specifies the exit status to be returned to the operating system. A value of 0 typically indicates success, while a non-zero value indicates an error or failure. The exact meaning of the exit status depends on the specific implementation and conventions being used.*`
    
- execve()
    
    ``**`*execve() is a function in the C programming language that is used to execute a new program in a process. It replaces the current process image with a new process image, and starts the new program running in the same process.`**`*`
    
    ``**`*The execve() function has the following prototype:`**`*`
    
    ``**`*int execve(const char *path, char *const argv[], char *const envp[]);`**`*`
    
    *`The `**`path`**` argument specifies the path of the program to be executed, and the `**`argv`**` argument is an array of pointers to null-terminated strings that represent the command-line arguments to be passed to the program. The `**`envp`**` argument is an array of pointers to null-terminated strings that represent the environment variables to be passed to the program.`*
    
    *`The `**`execve()`**` function returns -1 if an error occurs, and does not return if the program execution is successful. If the `**`execve()`**` function succeeds, it does not return to the calling process, but rather it replaces the calling process with the new process image.`*
    
    *`The `**`execve()`**` function is often used in combination with the `**`fork()`**` function to create a new process and execute a program in the child process. It can also be used to execute a program in the current process..`*
    
- access
    
    `the access() function is a library function that can be used to check the accessibility of a file. It checks whether the calling process can access a file by checking the file's permissions and the file's accessibility in the file system.`
    
    `The access() function takes a pathname and an integer mode as arguments and returns 0 if the file is accessible and -1 if the file is not accessible. The mode argument specifies the accessibility that the calling process is requesting:`
    
    - `R_OK: Check whether the file is readable`
    - `W_OK: Check whether the file is writable`
    - `X_OK: Check whether the file is executable`
    - `F_OK: Check whether the file exists`
