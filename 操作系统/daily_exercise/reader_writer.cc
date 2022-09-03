// 题目：
// 假定在生产者和消费者之间的公用缓冲池中，具有n个缓冲区，
// 这时可利用互斥信号量mutex实现诸进程对缓冲池的互斥使用；
// 利用信号量empty和full分别表示缓冲池中空缓冲区和满缓冲区的数量。
// 又假定这些生产者和消费者相互等效，只要缓冲池未满，生产者便可将消息送入缓冲池；
// 只要缓冲池未空，消费者便可从缓冲池中取走一个消息。
// 在Linux系统中，实现生产者和消费者进程。这两个进程使用记录型信号量进行资源共享和同步。
// 可以用共享内存的方法实现公用缓冲池。

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t mutex;
sem_t full;
sem_t empty;
void in(){
    // Swait(full,0,1;mutex,0,1);
    
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    //shop
    pthread_mutex_unlock(&mutex);
    // Ssignal(mutex,1;empty,1);
    sem_wait(&empty);
}

void out(){
    // Swait(empty,0,1;mutex,0,1);
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    //out
    pthread_mutex_unlock(&mutex);
    // Ssignal(mutex,1;full,1);
    sem_wait(&full);
}



int main(){
    sem_init(&full, 0, 1024);
    sem_init(&empty, 0, 0);
    pthread_mutex_init(&mutex,nullptr);
    in();
    out();

    sem_destroy(&full);
    sem_destroy(&empty);
    pthread_mutex_destroy(&mutex);
}