// Generates an array with a given seed, then spawns TOTAL_THREADS threads to sum
// together the contents of the array.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TOTAL_THREADS 5
#define ARRAY_SIZE 100
#define SEED 4562

struct get_sum_array_args {
    int *array;
    int length;
    int thread_total;
    int thread_num;
};

void fill_array_random(int array[], int length, uint32_t seed);
void *get_sum_array(void *data);
int find_sum_sequential(int array[], int length);

int main(void) {

    // Fill the array with random numbers
    int rand_array[ARRAY_SIZE];
    fill_array_random(rand_array, ARRAY_SIZE, SEED);

    // Spawn threads to go through the array + sum it all up!
    pthread_t thread_ids[TOTAL_THREADS];
    struct get_sum_array_args func_args[TOTAL_THREADS];

    for (int i = 0; i < TOTAL_THREADS; i++) {
        // Set up the arguments!
        func_args[i].array = rand_array;
        func_args[i].length = ARRAY_SIZE;
        func_args[i].thread_total = TOTAL_THREADS;
        func_args[i].thread_num = i;

        pthread_create(&thread_ids[i], NULL, get_sum_array, &func_args[i]);
    }
    
    // Collect the threads + get back the total sum!
    int sum = 0;

    for (int i = 0; i < TOTAL_THREADS; i++) {
        // Set up returning location - we're expecting an
        // int pointer!
        int *curr_sum_ptr;

        // Typecasting only necessary to quiet a warning - works
        // fine without it!!
        pthread_join(thread_ids[i], (void **)&curr_sum_ptr);

        sum += *curr_sum_ptr;
        free(curr_sum_ptr);
    }

    printf("Sum of array found with multithreading: %d\n", sum);
    printf("Sum of array found normally: %d\n", find_sum_sequential(rand_array, ARRAY_SIZE));
}

// Given an array, fills it with random numbers from 1 to
// 100. Returns nothing.
void fill_array_random(int array[], int length, uint32_t seed) {
    srand(seed);

    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 100) + 1;
    }

    return;
}

// Takes in a given array, and calculates the sum of every nth
// element
void *get_sum_array(void *data) {
    struct get_sum_array_args *args = data;

    int *sum = malloc(sizeof(int));
    *sum = 0;

    // Iterate through array - e.g if there are 3 threads and the
    // current thread is thread 1, we want to get array[1] + array[4] + array[7]...
    for (int i = args->thread_num; i < args->length; i += args->thread_total) {
        *sum += (args->array)[i];
    }

    return sum;
}

// Finds sum of an array normally!
int find_sum_sequential(int array[], int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    return sum;
}