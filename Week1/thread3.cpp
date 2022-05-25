#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void* mychance(void *arg)
{
    int *ptr = (int *)arg;
    for(int i=0;i<8;i++)
    {
        sleep(1);
        printf("It is my chance! %d %d\n",i,(*ptr));
        (*ptr)++;
    }
    return NULL;
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
    int x=5;
    pthread_t newthread;
    pthread_create(&newthread, NULL, mychance, &x);
    yourchance();
    pthread_join(newthread,NULL);
    printf("Threads done: x=%d\n",x);
}