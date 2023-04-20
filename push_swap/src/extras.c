/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:41:44 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 15:52:17 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

// void imprimir_pilha(t_stack *stacka)
// {
// 	t_node *aux;
	
// 	aux = stacka->first;
//     while(aux)
// 	{
// 		ft_printf("[%d]->", aux->data);
// 		aux = aux->next;
// 	}
//     ft_printf("\n-----------------------------\n");
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     int data;
//     struct node *next;
// } Node;

// void print_list(Node *head) {
//     Node *curr = head;
//     while (curr != NULL) {
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }
//     printf("\n");
// }

// Node *partition(Node *head, Node *tail, Node **new_head, Node **new_tail) {
//     Node *pivot = tail;
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *end = tail;

//     while (curr != pivot) {
//         if (curr->data < pivot->data) {
//             if (*new_head == NULL) {
//                 *new_head = curr;
//             }
//             prev = curr;
//             curr = curr->next;
//         } else {
//             if (prev) {
//                 prev->next = curr->next;
//             }
//             Node *tmp = curr->next;
//             curr->next = NULL;
//             end->next = curr;
//             end = curr;
//             curr = tmp;
//         }
//     }

//     if (*new_head == NULL) {
//         *new_head = pivot;
//     }

//     *new_tail = end;

//     return pivot;
// }

// Node *quick_sort(Node *head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     Node *tail = head;
//     while (tail->next != NULL) {
//         tail = tail->next;
//     }

//     Node *new_head = NULL;
//     Node *new_tail = NULL;
//     Node *pivot = partition(head, tail, &new_head, &new_tail);

//     if (new_head != pivot) {
//         Node *tmp = new_head;
//         while (tmp->next != pivot) {
//             tmp = tmp->next;
//         }
//         tmp->next = NULL;
//         new_head = quick_sort(new_head);
//         tmp = new_head;
//         while (tmp->next != NULL) {
//             tmp = tmp->next;
//         }
//         tmp->next = pivot;
//     }

//     pivot->next = quick_sort(pivot->next);

//     return new_head;
// }

// int main() {
//     Node *head = malloc(sizeof(Node));
//     head->data = 3;
//     head->next = malloc(sizeof(Node));
//     head->next->data = 1;
//     head->next->next = malloc(sizeof(Node));
//     head->next->next->data = 4;
//     head->next->next->next = malloc(sizeof(Node));
//     head->next->next->next->data = 2;
//     head->next->next->next->next = NULL;

//     printf("Before sorting: ");
//     print_list(head);

//     head = quick_sort(head);

//     printf("After sorting:	");
// 	print_list(head);
// }
