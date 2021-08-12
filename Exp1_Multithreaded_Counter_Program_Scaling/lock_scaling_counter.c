#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_threads=16;
pthread_mutex_t global_mutex;
long long count;
long long total_count=1600000000;
int batch = 100;

void safe_increment()
{
    //if (num_threads > 1)
    pthread_mutex_lock(&global_mutex);
    int i=0;
    for(i=0; i<batch; i++)
    {
        count = count + 1;
    }
    //if (num_threads > 1)
    pthread_mutex_unlock(&global_mutex);
}

long long
get_count()
{
    long long temp_count;
    pthread_mutex_lock(&global_mutex);
    temp_count = count;
    pthread_mutex_unlock(&global_mutex);
    return (temp_count);
}

void *run(void *arg)
{
    long counter= *(long *)arg;
    long i;
    for(i=0; i<counter;i++)
    {   
        safe_increment();
    }   
}

int main(int argc, char* argv[])
{
    pthread_t *threads;
    void *vp;
    int i;
    long batches_per_thread;

    if (argc >=2)
        num_threads = atoi(argv[1]);
    threads = (pthread_t *) malloc(num_threads * sizeof(pthread_t));
    batches_per_thread = (int)(total_count/(num_threads*batch));

    for(i=0; i< num_threads; i++)
    {
       if (pthread_create(&threads[i], NULL, run, &batches_per_thread) != 0)
       {
           perror("pthread_create");
           exit(-1);
       }
    }
    for(i=0; i< num_threads; i++)
    {
       if(pthread_join(threads[i], &vp) != 0)
       {
           perror("pthread_join");
           exit(-1);
       }
    }
    printf("Count=%lld\n",get_count());
    return 0;
}
