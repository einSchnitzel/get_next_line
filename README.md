# get_next_line
## 42 Main course project

### A function returning the next line (delimited by a newline) without losing track on the position of the input string, even when using different file descriptors. Without reading any character twice through a variable BUFFER_SIZE.
### Through a static character array the remaining characters after the new line are passed onto the next function call, unless there is no newline found within the input string.

### Passed with all bonuses:

### 1. usage of one static variable only
### 2. usage of multiple file descriptors without losing track.

## My takeaways:

### Main lesson:  How to avoid segfaults, properly free and allocate memory.

### Learned also: VS Code Debugger, manual debugging and basic use of containers with Docker.
### Improved:     Usage of structs. Basic use of Valgrind.
