#include <bits/stdc++.h>
using namespace std ;

int main(){
    printf("HELLO ACM!!!\n") ;
    printf("WELCOME TO THE MULTITHREADED SERVER PROJECT!!!\n") ;
    return 0 ;
}
/*
The multithreading paradigm has become more popular as efforts to further exploit instruction-level parallelism have stalled since the late 1990s. This allowed the concept of throughput computing to re-emerge from the more specialized field of transaction processing. Even though it is very difficult to further speed up a single thread or single program, most computer systems are actually multitasking among multiple threads or programs. Thus, techniques that improve the throughput of all tasks result in overall performance gains.

Two major techniques for throughput computing are multithreading and multiprocessing.

Advantages
If a thread gets a lot of cache misses, the other threads can continue taking advantage of the unused computing resources, which may lead to faster overall execution, as these resources would have been idle if only a single thread were executed. Also, if a thread cannot use all the computing resources of the CPU (because instructions depend on each other's result), running another thread may prevent those resources from becoming idle.

Disadvantages
Multiple threads can interfere with each other when sharing hardware resources such as caches or translation lookaside buffers (TLBs). As a result, execution times of a single thread are not improved and can be degraded, even when only one thread is executing, due to lower frequencies or additional pipeline stages that are necessary to accommodate thread-switching hardware.

Overall efficiency varies; Intel claims up to 30% improvement with its Hyper-Threading Technology,[1] while a synthetic program just performing a loop of non-optimized dependent floating-point operations actually gains a 100% speed improvement when run in parallel. On the other hand, hand-tuned assembly language programs using MMX or AltiVec extensions and performing data prefetches (as a good video encoder might) do not suffer from cache misses or idle computing resources. Such programs therefore do not benefit from hardware multithreading and can indeed see degraded performance due to contention for shared resources.

From the software standpoint, hardware support for multithreading is more visible to software, requiring more changes to both application programs and operating systems than multiprocessing. Hardware techniques used to support multithreading often parallel the software techniques used for computer multitasking. Thread scheduling is also a major problem in multithreading*/

#include <bits/stdc++.h>
#include <sys/socket.h>
#include <limits.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
// #include "myQueue.h"


#define SERVERPORT 8989
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100
#define THREAD_POOL_SIZE 20

pthread_t thread_pool[THREAD_POOL_SIZE] ;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER ;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER ;

typedef struct sockaddr_in SA_IN ;
typedef struct sockaddr SA ;

void * handle_connection(void * p_clinet_soccket) ;
int check(int exp , const char *msg) ;
void * thread_function(void * args) ;

int main(int argc , char **argv){
    int server_socket , client_socket, addr_size ;
    SA_IN server_addr , client_addr ;

    // for(int i =0 ; i < THREAD_POOL_SIZE ; i ++){
    //     pthread_create(&thread_pool[i] , NULL , thread_function , NULL) ;
    // }

    check((server_socket = socket(AF_INET , SOCK_STREAM , 0)),
            "Failed to create socket") ;
    
    server_addr.sin_family = AF_INET ;
    server_addr.sin_addr.s_addr = INADDR_ANY ;
    server_addr.sin_port = htons(SERVERPORT) ;

    check((bind(server_socket, (SA*)&server_addr , sizeof(server_addr))),
            "Bind Failed!") ;
    check(listen(server_socket, SERVER_BACKLOG),
            "Listen Failed!") ;
    
    while(true){
        printf("Waiting for connection...\n") ;
        addr_size = sizeof(SA_IN) ;
        check(client_socket = accept(server_socket , (SA*)&client_addr, (socklen_t*)&addr_size),
                "accept failed!!") ;
        printf("Connected\n") ;
    
        // pthread_t t ;
        int *pclient = (int *)malloc(sizeof(int)) ;
        *pclient = client_socket ;
        handle_connection(pclient) ;
        // this enqueue is causing the race condition.
        // pthread_mutex_lock(&lock) ;
        // enqueue(pclient) ;
        // pthread_mutex_unlock(&lock) ;
        // pthread_create(&t , NULL , handle_connection , (void *) pclient) ;
        

    }

    return 0 ;

}

int check(int exp, const char *msg) {
    if(exp == SOCKETERROR){
        perror(msg) ;
        exit(1) ;
    }
    return exp ;
}

// void * thread_function(void * args) {
//     while(true){
//         //this dequeue can also cause race condition.(queue is the shared data structure.)
//         pthread_mutex_lock(&lock) ;
//         int *pclient = dequeue() ;
//         pthread_mutex_unlock(&lock) ;

//         if(pclient != NULL){
//             handle_connection(pclient) ;
//         }
//         // else{
//         //     sleep(1) ;
//         // }
//         // This might cause a delay coz if a connection comes just after the thread sleeps it has to wait for 1 sec.
//     }
// }


void * handle_connection(void * p_clinet_soccket) {
    int clinet_soccket = *((int *) p_clinet_soccket) ;
    free(p_clinet_soccket) ;
    char buffer[BUFSIZE] ;
    size_t bytes_read ;
    int msgsize = 0 ;
    char actualpath[PATH_MAX + 1] ;

    while((bytes_read = read(clinet_soccket , buffer + msgsize , sizeof(buffer) - msgsize - 1)) > 0){
        msgsize += bytes_read ;
        if(msgsize > BUFSIZE - 1 || buffer[msgsize-1] == '\n') break ;
    }
    check(bytes_read , "recv error") ;
    buffer[msgsize - 1] = 0 ;

    printf("REQUEST: %s\n" , buffer) ;
    fflush(stdout) ;

    if(realpath(buffer , actualpath) == NULL){
        printf("ERROR(bad path): %s\n" , buffer) ;
        close(clinet_soccket) ;
        return NULL;
    }
    FILE *fp = fopen(actualpath , "r") ;

    if(fp == NULL){
        printf("ERROR(open): %s\n" , buffer) ;
        close(clinet_soccket) ;
        return NULL;
    }

    while((bytes_read = fread(buffer , 1 , BUFSIZE , fp)) > 0){
        printf("sending %zu bytes\n" , bytes_read) ;
        write(clinet_soccket , buffer , bytes_read) ;
    }
    close(clinet_soccket) ;
    fclose(fp) ;
    printf("CLosing connection\n") ;
    return NULL ;
}
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <limits.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
// #include "myQueue.h"


#define SERVERPORT 8989
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100
#define THREAD_POOL_SIZE 20

pthread_t thread_pool[THREAD_POOL_SIZE] ;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER ;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER ;

typedef struct sockaddr_in SA_IN ;
typedef struct sockaddr SA ;

void * handle_connection(void * p_clinet_soccket) ;
int check(int exp , const char *msg) ;
void * thread_function(void * args) ;

int main(int argc , char **argv){
    int server_socket , client_socket, addr_size ;
    SA_IN server_addr , client_addr ;

    // for(int i =0 ; i < THREAD_POOL_SIZE ; i ++){
    //     pthread_create(&thread_pool[i] , NULL , thread_function , NULL) ;
    // }

    check((server_socket = socket(AF_INET , SOCK_STREAM , 0)),
            "Failed to create socket") ;
    
    server_addr.sin_family = AF_INET ;
    server_addr.sin_addr.s_addr = INADDR_ANY ;
    server_addr.sin_port = htons(SERVERPORT) ;

    check((bind(server_socket, (SA*)&server_addr , sizeof(server_addr))),
            "Bind Failed!") ;
    check(listen(server_socket, SERVER_BACKLOG),
            "Listen Failed!") ;
    
    while(true){
        printf("Waiting for connection...\n") ;
        addr_size = sizeof(SA_IN) ;
        check(client_socket = accept(server_socket , (SA*)&client_addr, (socklen_t*)&addr_size),
                "accept failed!!") ;
        printf("Connected\n") ;
    
        // pthread_t t ;
        int *pclient = (int *)malloc(sizeof(int)) ;
        *pclient = client_socket ;
        handle_connection(pclient) ;
        // this enqueue is causing the race condition.
        // pthread_mutex_lock(&lock) ;
        // enqueue(pclient) ;
        // pthread_mutex_unlock(&lock) ;
        // pthread_create(&t , NULL , handle_connection , (void *) pclient) ;
        

    }

    return 0 ;

}

int check(int exp, const char *msg) {
    if(exp == SOCKETERROR){
        perror(msg) ;
        exit(1) ;
    }
    return exp ;
}

// void * thread_function(void * args) {
//     while(true){
//         //this dequeue can also cause race condition.(queue is the shared data structure.)
//         pthread_mutex_lock(&lock) ;
//         int *pclient = dequeue() ;
//         pthread_mutex_unlock(&lock) ;

//         if(pclient != NULL){
//             handle_connection(pclient) ;
//         }
//         // else{
//         //     sleep(1) ;
//         // }
//         // This might cause a delay coz if a connection comes just after the thread sleeps it has to wait for 1 sec.
//     }
// }


void * handle_connection(void * p_clinet_soccket) {
    int clinet_soccket = *((int *) p_clinet_soccket) ;
    free(p_clinet_soccket) ;
    char buffer[BUFSIZE] ;
    size_t bytes_read ;
    int msgsize = 0 ;
    char actualpath[PATH_MAX + 1] ;

    while((bytes_read = read(clinet_soccket , buffer + msgsize , sizeof(buffer) - msgsize - 1)) > 0){
        msgsize += bytes_read ;
        if(msgsize > BUFSIZE - 1 || buffer[msgsize-1] == '\n') break ;
    }
    check(bytes_read , "recv error") ;
    buffer[msgsize - 1] = 0 ;

    printf("REQUEST: %s\n" , buffer) ;
    fflush(stdout) ;

    if(realpath(buffer , actualpath) == NULL){
        printf("ERROR(bad path): %s\n" , buffer) ;
        close(clinet_soccket) ;
        return NULL;
    }
    FILE *fp = fopen(actualpath , "r") ;

    if(fp == NULL){
        printf("ERROR(open): %s\n" , buffer) ;
        close(clinet_soccket) ;
        return NULL;
    }

    while((bytes_read = fread(buffer , 1 , BUFSIZE , fp)) > 0){
        printf("sending %zu bytes\n" , bytes_read) ;
        write(clinet_soccket , buffer , bytes_read) ;
    }
    close(clinet_soccket) ;
    fclose(fp) ;
    printf("CLosing connection\n") ;
    return NULL ;
}
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <limits.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
// #include "myQueue.h"


#define SERVERPORT 8989
#define BUFSIZE 4096
#define SOCKETERROR (-1)
#define SERVER_BACKLOG 100
#define THREAD_POOL_SIZE 20

pthread_t thread_pool[THREAD_POOL_SIZE] ;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER ;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER ;

typedef struct sockaddr_in SA_IN ;
typedef struct sockaddr SA ;

void * handle_connection(void * p_clinet_soccket) ;
int check(int exp , const char *msg) ;
void * thread_function(void * args) ;

int main(int argc , char **argv){
    int server_socket , client_socket, addr_size ;
    SA_IN server_addr , client_addr ;

    // for(int i =0 ; i < THREAD_POOL_SIZE ; i ++){
    //     pthread_create(&thread_pool[i] , NULL , thread_function , NULL) ;
    // }

    check((server_socket = socket(AF_INET , SOCK_STREAM , 0)),
            "Failed to create socket") ;
    
    server_addr.sin_family = AF_INET ;
    server_addr.sin_addr.s_addr = INADDR_ANY ;
    server_addr.sin_port = htons(SERVERPORT) ;

    check((bind(server_socket, (SA*)&server_addr , sizeof(server_addr))),
            "Bind Failed!") ;
    check(listen(server_socket, SERVER_BACKLOG),
            "Listen Failed!") ;
    
    while(true){
        printf("Waiting for connection...\n") ;
        addr_size = sizeof(SA_IN) ;
        check(client_socket = accept(server_socket , (SA*)&client_addr, (socklen_t*)&addr_size),
                "accept failed!!") ;
        printf("Connected\n") ;
    
        // pthread_t t ;
        int *pclient = (int *)malloc(sizeof(int)) ;
        *pclient = client_socket ;
        handle_connection(pclient) ;
        // this enqueue is causing the race condition.
        // pthread_mutex_lock(&lock) ;
        // enqueue(pclient) ;
        // pthread_mutex_unlock(&lock) ;
        // pthread_create(&t , NULL , handle_connection , (void *) pclient) ;
        

    }

    return 0 ;

}

int check(int exp, const char *msg) {
    if(exp == SOCKETERROR){
        perror(msg) ;
        exit(1) ;
    }
    return exp ;
}

// void * thread_function(void * args) {
//     while(true){
//         //this dequeue can also cause race condition.(queue is the shared data structure.)
//         pthread_mutex_lock(&lock) ;
//         int *pclient = dequeue() ;
//         pthread_mutex_unlock(&lock) ;

//         if(pclient != NULL){
//             handle_connection(pclient) ;
//         }
//         // else{
//         //     sleep(1) ;
//         // }
//         // This might cause a delay coz if a connection comes just after the thread sleeps it has to wait for 1 sec.
//     }
// }


void * handle_connection(void * p_clinet_soccket) {
    int clinet_soccket = *((int *) p_clinet_soccket) ;
    free(p_clinet_soccket) ;
    char buffer[BUFSIZE] ;
    size_t bytes_read ;
    int msgsize = 0 ;
    char actualpath[PATH_MAX + 1] ;

    while((bytes_read = read(clinet_soccket , buffer + msgsize , sizeof(buffer) - msgsize - 1)) > 0){
        msgsize += bytes_read ;
        if(msgsize > BUFSIZE - 1 || buffer[msgsize-1] == '\n') break ;
    }
    check(bytes_read , "recv error") ;
    buffer[msgsize - 1] = 0 ;

    printf("REQUEST: %s\n" , buffer) ;
    fflush(stdout) ;

    if(realpath(buffer , actualpath) == NULL){
        printf("ERROR(bad path): %s\n" , buffer) ;
        close(clinet_soccket) ;
        return NULL;
    }
    FILE *fp = fopen(actualpath , "r") ;

    if(fp == NULL){
        printf("ERROR(open): %s\n" , buffer) ;
        close(clinet_soccket) ;
        return NULL;
    }

    while((bytes_read = fread(buffer , 1 , BUFSIZE , fp)) > 0){
        printf("sending %zu bytes\n" , bytes_read) ;
        write(clinet_soccket , buffer , bytes_read) ;
    }
    close(clinet_soccket) ;
    fclose(fp) ;
    printf("CLosing connection\n") ;
    return NULL ;
}