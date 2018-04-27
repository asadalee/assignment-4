#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];

void* sum(void* ind)
{
int thread_sum=0;
int c= *(int*) ind;
for(int j=c; j<c+100; j++)
{
thread_sum+=arr[j];
}

return ( (void*) thread_sum);

}

int main()
{
pthread_t thread[10];

for(int j=0; j<1000; j++)
{
arr[j]=j;
}

for(int j=0; j<10; j++)
{
int index=j*100;
pthread_create (&thread[j], NULL,  sum, (void*) index);
}

int total=0;
void* ans[10];
for(int j=0; j<10; j++)
{
pthread_join (thread[j], ans[j]);
total+= *(int*) ans[j];
}

printf("%d", total);
}

