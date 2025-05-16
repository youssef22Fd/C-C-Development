/*
 * Producer-Consumer Problem Using Pthreads
 *
 * This program demonstrates the classic Producer-Consumer synchronization problem
 * using POSIX threads (pthreads), mutexes, and condition variables.
 *
 * A fixed-size buffer is shared between a producer thread and a consumer thread.
 * The producer generates data items and places them in the buffer, while the
 * consumer removes and processes these items. Synchronization is used to ensure
 * safe concurrent access and avoid buffer overflows or underflows.
 *
 * Features:
 *  Implements a bounded buffer of fixed size (BUFFER_SIZE)
 *  One producer and one consumer thread operate on the buffer
 *  Uses mutexes to prevent race conditions
 *  Uses condition variables to manage buffer full and empty states
 *  Simulates production and consumption delays using `usleep()`
 *
 * Constants:
 *  BUFFER_SIZE: Maximum number of items the buffer can hold
 *  NUM_ITEMS  : Total number of items to be produced and consumed
 *
 * Functions:
 *  producer(): Produces NUM_ITEMS integers and places them into the buffer
 *  consumer(): Consumes NUM_ITEMS integers from the buffer
 *
 * Synchronization Primitives:
 *  pthread_mutex_t mutex      : Ensures mutual exclusion during buffer access
 *  pthread_cond_t not_full    : Signals when buffer is not full (producer can add)
 *  pthread_cond_t not_empty   : Signals when buffer is not empty (consumer can read)
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 20

int buffer[BUFFER_SIZE];
int count = 0; 
int in = 0;   
int out = 0; 

pthread_mutex_t mutex;
pthread_cond_t not_empty;
pthread_cond_t not_full;

void* producer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
  
        int item = rand() % 100;
        pthread_mutex_lock(&mutex);


        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);
        }


        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        count++;

     
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);


        usleep(rand() % 100000);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        pthread_mutex_lock(&mutex);


        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }

  
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;

     
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

  
        usleep(rand() % 100000);
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;


    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);

   
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    return 0;
}
