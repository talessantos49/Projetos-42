/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:53:04 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 10:53:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void create_stack(t_stack *stack){
	stack->first = NULL;
    stack->last = NULL;
	stack->tam = 0;
}

// void imprimir_pilha(t_stack *stack, char c){
// 	ft_printf("\n-------------- PILHA - ");
// 	ft_printf("%c",c);
// 	ft_printf(" tam: %d----------------\n", stack->tam);
// 	t_node *aux = stack->first;
// 	while (aux){
// 		ft_printf("%d\t",aux->data);
// 		aux = aux->next;
// 	}
// 	ft_printf("\n-------------- FIM DA PILHA ---------\n");
// }

// void inserir_na_fila(t_stack *stack, int num){
// 	t_node *new = malloc(sizeof(t_node));

// 	if (new){
// 		new->data = num;
// 		new->next = NULL;
// 		if (stack->first == NULL){
// 			stack->first = new;
// 			stack->last = new;
// 		}
// 		else{
// 			stack->last->next = new;
// 			stack->last = new;
// 		}
// 		stack->tam++;
// 	}
// 	else
// 		ft_printf("Erro ao alocar memoria!\n");
// }

// t_node *remover_da_fila(t_stack *stack){
// 	t_node *remover = NULL;
// 	if (stack->first){
// 		remover = stack->first;
// 		stack->first = remover->next;
// 		stack->tam--;
// 	}
// 	else
// 		ft_printf("\tFila Vazia\n");
// 	return remover;
// }


void remover_no_fim(t_stack *stack)
{
    t_node *aux = malloc(sizeof(t_node));

    if(aux){
         //é o primeiro?
        if (stack->first)
		{
	        aux = stack->first;
            while(aux->next)
			{
                aux = aux->next;
				ft_printf("\nO valor retornado é: %d\n", aux->data);
			}
			t_node *remove = aux->next;
			aux->next = remove->next;
		}
        else{
			ft_printf("Pilha Vazia");
        }

        stack->tam--;
    }
    else
        ft_printf("Erro ao alocar memoria!\n");
}

void inserir_no_fim(t_stack *stack, int num)
{
    t_node *new = malloc(sizeof(t_node));
    // t_node *aux = malloc(sizeof(t_node));

    if(new){
        new->data = num;
        new->next = NULL;

        //é o primeiro?
        if (stack->first == NULL){
            stack->first = new;
			stack->last = new;
		}
        else{
			stack->last->next = new;
			stack->last = new;
            // aux = stack->first;
            // while(aux->next)
            //     aux = aux->next;
            // aux->next=new;
        }
        stack->tam++;
    }
    else
        ft_printf("Erro ao alocar memoria!\n");
}

// int	main()
// {
// 	// t_node *remover = NULL;
// 	t_stack stackA;
// 	t_stack stackB;

// 	ft_printf("****************** Criar as Pilhas ******************\n");
// 	create_stack(&stackA);
// 	create_stack(&stackB);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
// 	// // ft_printf("\n****************** stack_up Stack A ******************\n");
// 	// // stack_up(&stackA, 1);
// 	// // stack_up(&stackA, 2);
// 	// // stack_up(&stackA, 3);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // ft_printf("\n****************** stack_up Stack B ******************\n");
// 	// // stack_up(&stackB, 4);
// 	// // stack_up(&stackB, 5);
// 	// // stack_up(&stackB, 6);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
// 	// // ft_printf("\n****************** Push AB ******************\n");
// 	// // push_b(&stackA, &stackB);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
// 	// // ft_printf("\n****************** Push BA ******************\n");
// 	// // push_a(&stackA, &stackB);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
// 	// // ft_printf("\n****************** Swap A ******************\n");
// 	// // swap(&stackA);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // ft_printf("\n****************** Swap B ******************\n");
// 	// // swap(&stackB);
// 	// // imprimir_pilha(&stackB, 'B');
	
// 	// // ft_printf("\n****************** Swap AB ******************\n");
// 	// // swap_ab(&stackA, &stackB);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
	
// 	// // ft_printf("\n****************** Rotate A ******************\n");
// 	// // shift_up(&stackA);
// 	// // imprimir_pilha(&stackA, 'A');

// 	// // ft_printf("\n****************** Rotate A ******************\n");
// 	// // shift_up(&stackA);
// 	// // imprimir_pilha(&stackA, 'A');

// 	// // ft_printf("\n****************** Rotate A ******************\n");
// 	// // shift_up(&stackA);
// 	// // imprimir_pilha(&stackA, 'A');

// 	// // // ft_printf("\n****************** shift_up_RR ******************\n");
// 	// // // imprimir_pilha(&stackA, 'A');
// 	// // // imprimir_pilha(&stackB, 'B');
// 	// // // shift_up_rr(&stackA, &stackB);
// 	// // // imprimir_pilha(&stackA, 'A');
// 	// // // imprimir_pilha(&stackB, 'B');
//     // // ft_printf("\n****************** shift_down_RRR ******************\n");
//     // // shift_down(&stackA);
//     // // shift_down(&stackB);
// 	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
//     // // ft_printf("\n****************** inserir no outset ******************\n");
//     // // insert_up(&stackA, 25);
//     // // insert_up(&stackB, 1235);
//    	// // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
//     // // ft_printf("\n****************** inserir no fim ******************\n");
//     // // inserir_no_fim(&stackA, 690);
//     // // inserir_no_fim(&stackB, 18);
//     // // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
//     // // ft_printf("\n****************** desempulhar ******************\n");
//     // // unstack(&stackA);
//     // // unstack(&stackB);
//     // // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
//     // // ft_printf("\n****************** Remover no fim ******************\n");
//     // // remover_no_fim(&stackA);
//     // // remover_no_fim(&stackB);
//     // // imprimir_pilha(&stackA, 'A');
// 	// // imprimir_pilha(&stackB, 'B');
// 	// ft_printf("\n***********************FILA ************************\n");
// 	// imprimir_fila(&stackA);
// 	// imprimir_fila(&stackB);
// 	// inserir_na_fila(&stackA, 1);
// 	// inserir_na_fila(&stackB, 1);
// 	// inserir_na_fila(&stackA, 2);
// 	// inserir_na_fila(&stackB, 2);
// 	// inserir_na_fila(&stackA, 3);
// 	// inserir_na_fila(&stackB, 3);
// 	// // imprimir_fila(&stackA);
// 	// // imprimir_fila(&stackB);
// 	// // remove_list(&stackA, stackA.last->data);
// 	// // remove_list(&stackB, stackB.last->data);
// 	// imprimir_fila(&stackA);
// 	// imprimir_fila(&stackB);
// 	// ft_printf("\n******************************SHIFT DOWN*********************\n");
// 	// shift_down(&stackA);
// 	// shift_down(&stackB);
// 	// imprimir_fila(&stackA);
// 	// imprimir_fila(&stackB);
// 	// shift_down(&stackA);
// 	// shift_down(&stackB);
// 	// imprimir_fila(&stackA);
// 	// imprimir_fila(&stackB);
// 	// ft_printf("\n******************************SHIFT DOWN*********************\n");
// 	// shift_down_rr(&stackA, &stackB);
// 	// imprimir_fila(&stackA);
// 	// imprimir_fila(&stackB);
// }
/*----------------------------------------------------------------------------*/

void remove_list(t_stack *stack, int valor){
	t_node *outset = stack->first;
	t_node *node_remove = NULL;

	if (outset != NULL && stack->first->data == valor){
		node_remove = stack->first;
		stack->first = node_remove->next;
		if(stack->first == NULL)
			stack->last = NULL;
	}
	else {
		while (outset != NULL && outset->next != NULL && outset->next->data != valor){
			outset = outset->next;
		}
		if (outset != NULL && outset->next != NULL){
			node_remove = outset->next;
			outset->next = node_remove->next;
			if (outset->next == NULL)
				stack->last = outset;
		}
	}
	if (node_remove){
		free(node_remove);
		stack->tam--;
	}
}

void stack_up(t_stack *stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	if(new){
		new->data = value;
		new->next = stack->first;
		stack->first = new;
		stack->tam++;
	}
	else
		write(1, "Error\n", 7);
}

void insert_up(t_stack *stack, int num)
{
    t_node *new = malloc(sizeof(t_node));

    if(new){
        new->data = num;
		if (stack->first == NULL){
			new->next = NULL;
			stack->first = new;
			stack->last = new;
		}
		else {
			new->next = stack->first;
			stack->first = new;
		}
        stack->tam++;
    }
    else
		write(1, "Error\n", 7);
}

t_node *unstack(t_stack *stack){
	if (stack->first){
		t_node *remove = stack->first;
		stack->first = remove->next;
		stack->tam--;
		return remove;
	}
	return NULL;
}
