#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
 
#define NUM 5
int queue[NUM];
 
sem_t blank_number, product_number;
 
void *producer(void *arg)
{
    int p = 0;
    while(1){
        sem_wait(&blank_number);
        queue[p] = rand() % 1000 + 1;
        printf("produce %d\n", queue[p]);
        p = (p + 1) % NUM;
        sem_post(&product_number);
        sleep(1);
        //sleep(rand()%5);
    }    
}
 
void *consumer(void *arg)
{
    int c = 0, i;
    while(1) {
        sem_wait(&product_number);
        for(i=0; i < NUM; i++) {
            printf("%d ", queue[i]);
        }
        putchar('\n');
 
        printf("consume %d\n", queue[c]);
        queue[c] = 0;
        sem_post(&blank_number);
        c = (c+1)%NUM;   
        sleep(3);
        //sleep(rand()%5);
    }
}
 
int main()
{
    pthread_t pid, cid;
    
    // 可用资源数为 NUM = 5
    sem_init(&blank_number, 0, NUM);
    sem_init(&product_number, 0, 0);
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    sem_destroy(&blank_number);
    sem_destroy(&product_number);
    return 0;
}