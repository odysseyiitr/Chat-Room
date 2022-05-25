#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
void* mychance(void *arg)
{
    for(int i=0;i<8;i++)
    {
        sleep(1);
        printf("It is my chance! %d\n",i);
    }
    return NULL;
}
void yourchance()
{
    for(int i=0;i<3;i++)
    {
        sleep(2);
        printf("It is your chance! %d\n",i);
    }
}
int main()
{
    pthread_t newthread;
    pthread_create(&newthread, NULL, mychance, NULL);
    yourchance();
    //pthread_join(newthread,NULL);
}