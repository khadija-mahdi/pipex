# fork()

`fork() : is a system call in the Unix and Unix-like operating systems that creates a new process ( the child process) from a parent process,.***`

`After a new child process is created, both processes will execute the next instruction following the fork() system call. A child process uses the same pc(program counter), same CPU registers, same open files which use in the parent process.***`

`( Generally fork () tries to make an exact  copy of the calling process)`

```
 It does not take any parameter, it returns
 integer values. It may return negative,
 positive or zero integer values

negative : if if an error occurred .
zero : if it's the child process.
positive : if the child process created .
```

- `The child thread returns executing at the exact same point that its parent called fork().`
    
    <aside>
    💡 `With one exception: fork() returns **twice**, the PID of child to the parent and 0 to the child.`
    
    </aside>
    
- `All contents of memory in the parent and child are identical.`
- `Both child and parent have the same files open at the same position.*
    - **`But, since they are sharing file handles changes to the file offset made by the parent/child will be reflected in the child/parent!`**
    
    `If the call to fork() is executed successfully, Unix will`
    
    - `make two identical copies of address spaces, one for the parent and the other for the child.`
    - `Both processes will start their execution at the next statement following the fork() call. In this case, both processes will start their execution at the assignment statement as shown below:`
    
    `When you call fork() twice, you create three child processes in total.`
    
    `The fork() function creates a new process by duplicating the calling process. The new process is called the child process, and the original process is called the parent process. When you call fork() twice, the first call creates a child process, and the second call creates a grandchild process. The grandchild process is the child of the child process, which is itself the child of the parent process.`
    
    ![Page 1.png](fork()%20aa6a96924d494ade9ea095fce3c0c07e/Page_1.png)
    
    ***`x = fork() ⇒ two process`*** 
    
    ***`return value of the child0 process ⇒ x = 0`***
    
    ***`return value of the main process ⇒ x = 600 (for example)`***
    
    ***`x = fork() ⇒ two process  &&  y = fork() ⇒ two process`***
    
    ***`return value of the child0 process ⇒ x = 0 , y = 200 ;`***
    
    ***`return value of the main process ⇒ x = 600  , y = 300 ;`***
    
    ***`return value of the child1 process ⇒ y = 0 , x = 600;`***
    
    ***`return value of The grandchild process ⇒ x = 0 , y = 0;`***
    
    > *`It is possible to call the fork()
     function multiple times in a program to create multiple child processes.`*
    > 
    
    ![fork2.png](fork()%20aa6a96924d494ade9ea095fce3c0c07e/fork2.png)