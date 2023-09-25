// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   treahd.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/09/25 15:48:51 by tasantos          #+#    #+#             */
// /*   Updated: 2023/09/25 15:48:57 by tasantos         ###   ########.fr       */
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
//         pthread_mutex_lock(&mutex);

//         contador++;

//         // Libera o mutex após terminar de acessar a variável compartilhada
//         pthread_mutex_unlock(&mutex);
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

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define NUM 1000000
#define NUM2 10000000

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void loopFunc(size_t num)
{
    int tmp = 0;
    for (unsigned long int i = 0; i < num; ++i) {
        tmp += 1;
    }
}

int main() {
    struct timeval start;
    struct timeval end;

    gettimeofday(&start, NULL);
    loopFunc(NUM);
    gettimeofday(&end, NULL);

    printf("loopFunc(%d)  time spent: %0.8f sec\n",
           NUM, time_diff(&start, &end));


    gettimeofday(&start, NULL);
    loopFunc(NUM2);
    gettimeofday(&end, NULL);

    printf("loopFunc(%d) time spent: %0.8f sec\n",
           NUM2, time_diff(&start, &end));

    exit(EXIT_SUCCESS);
}