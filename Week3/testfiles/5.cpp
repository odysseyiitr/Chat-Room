#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define ull unsigned long long int
const int M=1e9+7;
// #define pb push_back;
#define F(a,b,i) for(ll i=a;i<b;i++)
#define FN(a,b,i) for(ll i=a-1;i>=b;i--)

// binary exponentiation a^b //
long long bexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//          //          //          //

// binary exponentiation a^b modulo M //
ll bexpM(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}
//          //          //          //

// to check if the number is prime //
bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
//      //      //      //      // 

// finding the next prime number greater than the given number
ll nextPrime(ll N)
{
 
    // Base case
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;
 
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
 
        if (isPrime(prime))
            found = true;
    }
 
    return prime;
}  
//          //          //          //          //   


// storing of unique prime factors of a number //
void UniquePrimeStorage(ll n,vector<ll>&v){
   ll i;
   if(n % 2 == 0){
      v.push_back(2);
      n = n/2;
   }
   while(n % 2 == 0){//skip next 2s
      n = n/2;
   }
   for(i = 3; i <= sqrt(n); i=i+2){ //i will increase by 2, to get only odd numbers
      if(n % i == 0){
         v.push_back(i);
         n = n/i;
      }
      while(n % i == 0){ //skip next i's
         n = n/i;
      }
   }
   if(n > 2){
      v.push_back(n);
   }
}
//      //      //      //      //      //      //      //

//to check if a number is of the form 2^n or not ??
bool isPowerOfTwo(ll n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

//      //      //      //      //      //      //

//XOR of elements from 1 to n :-
ll computeXOR(ll n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}

// to check if a number can be represented as a power of another number //
// eg. to check 5^2 ,5^3 etc.
bool isPower(ll x, ll y)
{
    // logarithm function to calculate value
    ll res1 = log(y) / log(x);
    double res2 = log(y) / log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}
//          //          //          //          //          //


//  to sort the vector of pair in descending order wrt the second element
bool sortbysecdesc(const pair<ll,ll> &a,
                   const pair<ll,ll> &b){
       if(a.first==b.first){
           return a.second<b.second;
       }   
       else         
       return a.first>b.first;
}
//          //          //          //          //          //

//  to count the length of the longest incresing subsequence of same numbers
/*
ll count(vector<ll>v)
{
    ll ans = 1, temp = 1;
    for (ll i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) {
            ++temp;
        }
        else {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    ans = max(ans, temp);
    return ans;
}
*/

// decimal to binary conversion
/*
string decimalToBinary(ll N)
{
 
    // To store the binary number
    ull B_Number = 0;
    ll cnt = 0;
    while (N != 0) {
        ll rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
 
        // Count used to store exponent value
        cnt++;
    }
    string s=to_string(B_Number);
    return s;
}
*/

// longest increasing subsequence using dp //
/*
ll lis(ll i){
    if(dp[i]!=-1) return dp[i];
    ll ans=1;
    for(ll j=0;j<i;j++){
        if(a[i]>a[j]){
            ans = max(ans,lis(j)+1);
        }
    }
    return dp[i] =ans;
}
*/


//          //          //          //          //          //

//       //     //       //
// IN-BUILT USEFUL FUNCTIONS //

/* (1) to count the number of set bits in a given number-
    function - __builtin_popcountll(n) 
*/
    
/* (2) to check if a vector if sorted or not-
    function - is_sorted(v.begin(),v.end())
*/
/* (3) to check the power of 2 in the prime factorization of any number
or to find the index of the last set bit
     function - log2(n & -n)
*/

//      //      //      //
// const int N=1e5+10;
// vector<vector<ll>g(N);
// bool vis[N];
// void dfs(ll vertex){
//     vis[vertex]=true;
//     for(ll child:g[vertex]){
//         if(vis[child]){
//             continue;
//         }
//         dfs(child;)
//     }
// }

// bool a[110][110]={true};
//  ll findlcm(vector<ll>v, ll x)
// {
//     // Initialize result
//     ll ans = v[0];
 
//     // ans contains LCM of arr[0], ..arr[i]
//     // after i'th iteration,
//     if(x>=1){
//     for (int i = 1; i < x+1; i++){
//         ans = (((v[i] * ans)) /
//                 (gcd(v[i], ans)));
//     }
 
//     }
//     return ans;
// }
void primeFactors(map<ll,ll>&m,ll n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
}
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}
// void dfs(vector<vector<ll>>&adj,vector<ll>height,ll v,ll parent){
//     for(auto child:adj[v]){
//         if(child==parent)continue;
//         height[child]+=1;
//         dfs(adj,height,child,v);
//     }
// }
// const int 1e5+10;
// vector<vector<ll>>adj(N);

  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
            ll n,k;
            cin>>n>>k;
            vector<ll>v(n);
            ll total(0);
            vector<ll>costr;
            for(ll i=0;i<n;i++){
                cin>>v[i];
                total+=v[i];
                costr.push_back(v[i]-(n-i-1));
            }
            sort(costr.begin(),costr.end());
            reverse(costr.begin(),costr.end());
            ll remove(0);
            for(ll i=0;i<k;i++){
                remove+=costr[i];
            }
            cout<<total-remove-((k*(k-1))/2)<<endl;
    }
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

#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define ull unsigned long long int
const int M=1e9+7;
// #define pb push_back;
#define F(a,b,i) for(ll i=a;i<b;i++)
#define FN(a,b,i) for(ll i=a-1;i>=b;i--)

// binary exponentiation a^b //
long long bexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//          //          //          //

// binary exponentiation a^b modulo M //
ll bexpM(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}
//          //          //          //

// to check if the number is prime //
bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
//      //      //      //      // 

// finding the next prime number greater than the given number
ll nextPrime(ll N)
{
 
    // Base case
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;
 
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
 
        if (isPrime(prime))
            found = true;
    }
 
    return prime;
}  
//          //          //          //          //   


// storing of unique prime factors of a number //
void UniquePrimeStorage(ll n,vector<ll>&v){
   ll i;
   if(n % 2 == 0){
      v.push_back(2);
      n = n/2;
   }
   while(n % 2 == 0){//skip next 2s
      n = n/2;
   }
   for(i = 3; i <= sqrt(n); i=i+2){ //i will increase by 2, to get only odd numbers
      if(n % i == 0){
         v.push_back(i);
         n = n/i;
      }
      while(n % i == 0){ //skip next i's
         n = n/i;
      }
   }
   if(n > 2){
      v.push_back(n);
   }
}
//      //      //      //      //      //      //      //

//to check if a number is of the form 2^n or not ??
bool isPowerOfTwo(ll n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

//      //      //      //      //      //      //

//XOR of elements from 1 to n :-
ll computeXOR(ll n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}

// to check if a number can be represented as a power of another number //
// eg. to check 5^2 ,5^3 etc.
bool isPower(ll x, ll y)
{
    // logarithm function to calculate value
    ll res1 = log(y) / log(x);
    double res2 = log(y) / log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}
//          //          //          //          //          //


//  to sort the vector of pair in descending order wrt the second element
bool sortbysecdesc(const pair<ll,ll> &a,
                   const pair<ll,ll> &b){
       if(a.first==b.first){
           return a.second<b.second;
       }   
       else         
       return a.first>b.first;
}
//          //          //          //          //          //

//  to count the length of the longest incresing subsequence of same numbers
/*
ll count(vector<ll>v)
{
    ll ans = 1, temp = 1;
    for (ll i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) {
            ++temp;
        }
        else {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    ans = max(ans, temp);
    return ans;
}
*/

// decimal to binary conversion
/*
string decimalToBinary(ll N)
{
 
    // To store the binary number
    ull B_Number = 0;
    ll cnt = 0;
    while (N != 0) {
        ll rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
 
        // Count used to store exponent value
        cnt++;
    }
    string s=to_string(B_Number);
    return s;
}
*/

// longest increasing subsequence using dp //
/*
ll lis(ll i){
    if(dp[i]!=-1) return dp[i];
    ll ans=1;
    for(ll j=0;j<i;j++){
        if(a[i]>a[j]){
            ans = max(ans,lis(j)+1);
        }
    }
    return dp[i] =ans;
}
*/


//          //          //          //          //          //

//       //     //       //
// IN-BUILT USEFUL FUNCTIONS //

/* (1) to count the number of set bits in a given number-
    function - __builtin_popcountll(n) 
*/
    
/* (2) to check if a vector if sorted or not-
    function - is_sorted(v.begin(),v.end())
*/
/* (3) to check the power of 2 in the prime factorization of any number
or to find the index of the last set bit
     function - log2(n & -n)
*/

//      //      //      //
// const int N=1e5+10;
// vector<vector<ll>g(N);
// bool vis[N];
// void dfs(ll vertex){
//     vis[vertex]=true;
//     for(ll child:g[vertex]){
//         if(vis[child]){
//             continue;
//         }
//         dfs(child;)
//     }
// }

// bool a[110][110]={true};
//  ll findlcm(vector<ll>v, ll x)
// {
//     // Initialize result
//     ll ans = v[0];
 
//     // ans contains LCM of arr[0], ..arr[i]
//     // after i'th iteration,
//     if(x>=1){
//     for (int i = 1; i < x+1; i++){
//         ans = (((v[i] * ans)) /
//                 (gcd(v[i], ans)));
//     }
 
//     }
//     return ans;
// }
void primeFactors(map<ll,ll>&m,ll n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
}
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}
// void dfs(vector<vector<ll>>&adj,vector<ll>height,ll v,ll parent){
//     for(auto child:adj[v]){
//         if(child==parent)continue;
//         height[child]+=1;
//         dfs(adj,height,child,v);
//     }
// }
// const int 1e5+10;
// vector<vector<ll>>adj(N);

  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
            ll n,k;
            cin>>n>>k;
            vector<ll>v(n);
            ll total(0);
            vector<ll>costr;
            for(ll i=0;i<n;i++){
                cin>>v[i];
                total+=v[i];
                costr.push_back(v[i]-(n-i-1));
            }
            sort(costr.begin(),costr.end());
            reverse(costr.begin(),costr.end());
            ll remove(0);
            for(ll i=0;i<k;i++){
                remove+=costr[i];
            }
            cout<<total-remove-((k*(k-1))/2)<<endl;
    }
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

#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define ull unsigned long long int
const int M=1e9+7;
// #define pb push_back;
#define F(a,b,i) for(ll i=a;i<b;i++)
#define FN(a,b,i) for(ll i=a-1;i>=b;i--)

// binary exponentiation a^b //
long long bexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//          //          //          //

// binary exponentiation a^b modulo M //
ll bexpM(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}
//          //          //          //

// to check if the number is prime //
bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
//      //      //      //      // 

// finding the next prime number greater than the given number
ll nextPrime(ll N)
{
 
    // Base case
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;
 
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
 
        if (isPrime(prime))
            found = true;
    }
 
    return prime;
}  
//          //          //          //          //   


// storing of unique prime factors of a number //
void UniquePrimeStorage(ll n,vector<ll>&v){
   ll i;
   if(n % 2 == 0){
      v.push_back(2);
      n = n/2;
   }
   while(n % 2 == 0){//skip next 2s
      n = n/2;
   }
   for(i = 3; i <= sqrt(n); i=i+2){ //i will increase by 2, to get only odd numbers
      if(n % i == 0){
         v.push_back(i);
         n = n/i;
      }
      while(n % i == 0){ //skip next i's
         n = n/i;
      }
   }
   if(n > 2){
      v.push_back(n);
   }
}
//      //      //      //      //      //      //      //

//to check if a number is of the form 2^n or not ??
bool isPowerOfTwo(ll n)
{
   if(n==0)
   return false;
 
   return (ceil(log2(n)) == floor(log2(n)));
}

//      //      //      //      //      //      //

//XOR of elements from 1 to n :-
ll computeXOR(ll n)
{
  if (n % 4 == 0)
    return n;
  if (n % 4 == 1)
    return 1;
  if (n % 4 == 2)
    return n + 1;
  return 0;
}

// to check if a number can be represented as a power of another number //
// eg. to check 5^2 ,5^3 etc.
bool isPower(ll x, ll y)
{
    // logarithm function to calculate value
    ll res1 = log(y) / log(x);
    double res2 = log(y) / log(x); // Note : this is double
 
    // compare to the result1 or result2 both are equal
    return (res1 == res2);
}
//          //          //          //          //          //


//  to sort the vector of pair in descending order wrt the second element
bool sortbysecdesc(const pair<ll,ll> &a,
                   const pair<ll,ll> &b){
       if(a.first==b.first){
           return a.second<b.second;
       }   
       else         
       return a.first>b.first;
}
//          //          //          //          //          //

//  to count the length of the longest incresing subsequence of same numbers
/*
ll count(vector<ll>v)
{
    ll ans = 1, temp = 1;
    for (ll i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1]) {
            ++temp;
        }
        else {
            ans = max(ans, temp);
            temp = 1;
        }
    }
    ans = max(ans, temp);
    return ans;
}
*/

// decimal to binary conversion
/*
string decimalToBinary(ll N)
{
 
    // To store the binary number
    ull B_Number = 0;
    ll cnt = 0;
    while (N != 0) {
        ll rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
 
        // Count used to store exponent value
        cnt++;
    }
    string s=to_string(B_Number);
    return s;
}
*/

// longest increasing subsequence using dp //
/*
ll lis(ll i){
    if(dp[i]!=-1) return dp[i];
    ll ans=1;
    for(ll j=0;j<i;j++){
        if(a[i]>a[j]){
            ans = max(ans,lis(j)+1);
        }
    }
    return dp[i] =ans;
}
*/


//          //          //          //          //          //

//       //     //       //
// IN-BUILT USEFUL FUNCTIONS //

/* (1) to count the number of set bits in a given number-
    function - __builtin_popcountll(n) 
*/
    
/* (2) to check if a vector if sorted or not-
    function - is_sorted(v.begin(),v.end())
*/
/* (3) to check the power of 2 in the prime factorization of any number
or to find the index of the last set bit
     function - log2(n & -n)
*/

//      //      //      //
// const int N=1e5+10;
// vector<vector<ll>g(N);
// bool vis[N];
// void dfs(ll vertex){
//     vis[vertex]=true;
//     for(ll child:g[vertex]){
//         if(vis[child]){
//             continue;
//         }
//         dfs(child;)
//     }
// }

// bool a[110][110]={true};
//  ll findlcm(vector<ll>v, ll x)
// {
//     // Initialize result
//     ll ans = v[0];
 
//     // ans contains LCM of arr[0], ..arr[i]
//     // after i'th iteration,
//     if(x>=1){
//     for (int i = 1; i < x+1; i++){
//         ans = (((v[i] * ans)) /
//                 (gcd(v[i], ans)));
//     }
 
//     }
//     return ans;
// }
void primeFactors(map<ll,ll>&m,ll n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        m[2]++;
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            m[i]++;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        m[n]++;
}
ll factorial(ll n){
    if(n==0){
        return 1;
    }
    return factorial(n-1)*n;
}
// void dfs(vector<vector<ll>>&adj,vector<ll>height,ll v,ll parent){
//     for(auto child:adj[v]){
//         if(child==parent)continue;
//         height[child]+=1;
//         dfs(adj,height,child,v);
//     }
// }
// const int 1e5+10;
// vector<vector<ll>>adj(N);

  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
            ll n,k;
            cin>>n>>k;
            vector<ll>v(n);
            ll total(0);
            vector<ll>costr;
            for(ll i=0;i<n;i++){
                cin>>v[i];
                total+=v[i];
                costr.push_back(v[i]-(n-i-1));
            }
            sort(costr.begin(),costr.end());
            reverse(costr.begin(),costr.end());
            ll remove(0);
            for(ll i=0;i<k;i++){
                remove+=costr[i];
            }
            cout<<total-remove-((k*(k-1))/2)<<endl;
    }
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