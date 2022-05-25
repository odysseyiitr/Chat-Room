#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void* mychance(void *arg)
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr =5;
    for(int i=0;i<8;i++)
    {
        sleep(1);
        printf("It is my chance! %d %d\n",i,(*ptr));
        (*ptr)++;
    }
    return ptr;
}
void yourchance()
{
    for(int i=0;i<5;i++)
    {
        sleep(2);
        printf("It is your chance! %d\n",i);
    }
}
int main()
{
    int *result;
    pthread_t newthread;
    pthread_create(&newthread, NULL, mychance, NULL);
    yourchance();
    pthread_join(newthread,(void **)&result);
    printf("Threads done: *result =%d\n",*result);
}