// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   treahd.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/25 15:48:51 by tasantos          #+#    #+#             */
// /*   Updated: 2023/09/25 19:50:20 by tasantos         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <pthread.h>

// #define NUM_THREADS 2

// // Variável compartilhada entre as threads
// int contador = 0;

// // Mutex para controlar o acesso à variável compartilhada
// pthread_mutex_t mutex;

// // Função que será executada por cada thread
// void *funcao_da_thread(void *arg) {
//     for (int i = 0; i < 100000; i++) {
//         // Bloqueia o mutex para acessar a variável compartilhada
//         // pthread_mutex_lock(&mutex);

//         contador++;

//         // Libera o mutex após terminar de acessar a variável compartilhada
//         // pthread_mutex_unlock(&mutex);
//     }
//     return NULL;
// }

// int main() {
//     pthread_t threads[NUM_THREADS];

//     // Inicializa o mutex
//     pthread_mutex_init(&mutex, NULL);

//     // Cria as threads
//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_create(&threads[i], NULL, funcao_da_thread, NULL);
//     }

//     // Espera que todas as threads terminem
//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     // Destroi o mutex
//     pthread_mutex_destroy(&mutex);

//     printf("Valor final do contador: %d\n", contador);

//     return 0;
// }

// // #include <stdlib.h>
// // #include <stdio.h>
// // #include <sys/time.h>
// // #include <time.h>

// // #define NUM 1000000
// // #define NUM2 10000000

// // float time_diff(struct timeval *start, struct timeval *end)
// // {
// //     return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
// // }

// // void loopFunc(size_t num)
// // {
// //     int tmp = 0;
// //     for (unsigned long int i = 0; i < num; ++i) {
// //         tmp += 1;
// //     }
// // }

// // int main() {
// //     struct timeval start;
// //     struct timeval end;

// //     gettimeofday(&start, NULL);
// //     loopFunc(NUM);
// //     gettimeofday(&end, NULL);

// //     printf("loopFunc(%d)  time spent: %0.8f sec\n",
// //            NUM, time_diff(&start, &end));


// //     gettimeofday(&start, NULL);
// //     loopFunc(NUM2);
// //     gettimeofday(&end, NULL);

// //     printf("loopFunc(%d) time spent: %0.8f sec\n",
// //            NUM2, time_diff(&start, &end));

// //     exit(EXIT_SUCCESS);
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define ARRAY_SIZE 30
// #define NUM_THREADS 3

// int array[ARRAY_SIZE];
// long long partial_sums[NUM_THREADS] = {0};

// // Função que cada thread executará
// void* calcularSoma(void* thread_id) {
//     int id = *((int*)thread_id);
//     int elementos_por_thread = ARRAY_SIZE / NUM_THREADS;
//     int inicio = id * elementos_por_thread;
//     int fim = (id + 1) * elementos_por_thread;

//     long long soma_local = 0;
//     for (int i = inicio; i < fim; i++) {
//         soma_local += array[i];
//     }

//     partial_sums[id] = soma_local;
//     pthread_exit(NULL);
// }

// int main() {
//     // Inicialize o array com valores
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         array[i] = i + 1;
//     }

//     pthread_t threads[NUM_THREADS];
//     int thread_ids[NUM_THREADS] = {0, 1};

//     // Crie as threads
//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_create(&threads[i], NULL, calcularSoma, (void*)&thread_ids[i]);
//     }

//     // Aguarde até que as threads terminem
//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     // Calcule a soma total a partir das somas parciais
//     long long soma_total = 0;
//     for (int i = 0; i < NUM_THREADS; i++) {
//         soma_total += partial_sums[i];
//     }

//     printf("A soma total é: %lld\n", soma_total);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// #define MAX_NUM 20
// #define NUM_THREADS 4

// int current_number = 1;
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// // Função que cada thread executará
// void* imprimirNumeros(void* thread_id) {
//     int id = *((int*)thread_id);
//     while (1) {
//         pthread_mutex_lock(&mutex);
//         if (current_number > MAX_NUM) {
//             pthread_mutex_unlock(&mutex);
//             break;
//         }
//         if (current_number % 2 == id) {
//             printf("Thread %d: %d - %d\n", id, current_number, (current_number % 2));
//             current_number++;
//         }
//         pthread_mutex_unlock(&mutex);
//     }
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t threads[NUM_THREADS];
//     int thread_ids[NUM_THREADS] = {0, 1, 2, 3};

//     // Crie as threads
//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_create(&threads[i], NULL, imprimirNumeros, (void*)&thread_ids[i]);
//     }

//     // Aguarde até que as threads terminem
//     for (int i = 0; i < NUM_THREADS; i++) {
//         pthread_join(threads[i], NULL);
//     }

//     return 0;
// }
// gcc -g -pthread treahd.c -o main

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine()
{
    x++;
    sleep(2);
    printf("Value of x: %d\n", x);
    // printf("Test from threads\n");
    // sleep(3);
    // printf("Ending thread\n");
}

void *routine2()
{
    sleep(2);
    printf("Value of x: %d\n", x);
    // printf("Test from threads\n");
    // sleep(3);
    // printf("Ending thread\n");
}

int main(int argc, char **argv)
{
    pthread_t t1, t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0){
        return (1);
    }
    if (pthread_create(&t2, NULL, &routine2, NULL) != 0){
        return (2);
    }
    if (pthread_join(t1, NULL) != 0)
    {
        return (3);
    }
    if (pthread_join(t2, NULL) != 0)
    {
        return (4);
    }
    return (0);
}