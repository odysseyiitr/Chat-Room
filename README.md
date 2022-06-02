# Multithreaded-Server

A client-server model which processes the request one by one does not seem good to the user as the time delay for each request to be processed will be large.
So what can we do… ?

Let’s create a Multithread Server.

## GOAL
Multiple users(clients) may want to access some information from the server. All of them may simultaneously request the resources from the server. For better user experience the server needs to be more responsive that is it should be able to process as many requests as possible.Multithreading is the concept of using multiple threads to execute concurrently. In order to make the server more responsive we would assign the requests to different threads, so that the maximum number of requests can be processed concurrently. Using many threads would lead to a situation where two threads are accessing the same code or the same shared variable and there is a possibility of wrong output. To tackle this situation we use mutex locks to allow only one thread to access the shared code and do the necessary changes and synchronize all the threads. Using too many threads may also slow down. In order to tackle this problem, we would be using a thread pool having a definite number of threads and with the use of mutex we would be assigning each request to a thread. This would speed up the response time and would aim for more user satisfaction.

## Timeline

### Week 1 : `May 25, 2022 - May 31, 2022`
- Brief Description of the need for threads in programming.
- Introduction to pthreads.
- How to pass and receive arguments using pthreads.
- Use of mutex with threads.
- Resources: [Thread functions in C/C++ - GeeksforGeeks](https://www.geeksforgeeks.org/thread-functions-in-c-c/), [Mutex lock for Linux Thread Synchronization - GeeksforGeeks](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)

### Week 2 : `Jun 1, 2022 - Jun 7, 2022`
- Understand the working of a simple server.
- Implement a simple server using the socket library. The server would read a file and display the number of bytes in the file.
- Understand how the client makes a connection to the server and asks it to perform the job by passing required instructions.
- Implement the client using a Ruby script and understand the working.
- Resources: [Socket Programming](https://www.geeksforgeeks.org/socket-programming-cc/)

### Week 3 : `Jun 8, 2022 - Jun 14, 2022`
- Understanding multithreaded servers and their advantages over simple servers.
- Implementing threads in our servers to make it more efficient
- Discussing all the problems involved with implementing threads on the server
- Understanding the various solutions to the issues discussed.
- Resources: https://www.geeksforgeeks.org/handling-multiple-clients-on-server-with-multithreading-using-socket-programming-in-c-cpp/

## Additionals
- Customize your server: (Make it a web server or a tic-tac-toe server or anything else of your choice)
- Make a Proper Documentation of Project
- Add necessary comments in the code
