#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
void* mychance(void *arg)
{
    while(1)
    {
        sleep(1);
        printf("It is my Chance! \n");
    }
    return NULL;
}
void yourchance()
{
    while(1)
    {
        sleep(2);
        printf("It is your Chance! \n");
    }
}
int main()
{
    pthread_t newthread;
    pthread_create(&newthread, NULL, mychance, NULL);
    yourchance();
}