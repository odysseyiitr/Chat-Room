#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
void mychance()
{
    while(1)
    {
        sleep(1);
        printf(" It is my Chance! \n");
    }
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
    mychance();
    yourchance();
}