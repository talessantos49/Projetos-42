#include "../includes/push_swap.h"
#include <stdio.h>

typedef struct s_node{
	int data;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_stack{
	t_node *topo;
	int tam;
} t_stack;

void criar_pilha(t_stack *stackA){
	stackA->topo = NULL;
	stackA->tam = 0;
}

void empilhar(t_stack *stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	if(new){
		new->data = value;
		new->next = stack->topo;
		stack->topo = new;
		stack->tam++;
	}
	else
		ft_printf("\nErro ao alocar memoria...\n");
}

t_node *desempilhar(t_stack *stack){
	if (stack->topo){
		t_node *remove = stack->topo;
		stack->topo = remove->next;
		stack->tam--;
		return remove;
	}
	else
		ft_printf("\nPilha Vazia!\n");
	return NULL;
}


// t_node *empilhar(t_node *stack, int value)
// {
// 	t_node *new = malloc(sizeof(t_node));
// 	if(new){
// 		new->data = value;
// 		new->next = stack;
// 		return new;
// 	}
// 	else
// 		ft_printf("\nErro ao alocar memoria...\n");
// 	return NULL;
// }

// t_node *desempilhar(t_node **stack){
// 	if (*stack != NULL){
// 		t_node *remove = *stack;
// 		*stack = remove->next;
// 		return remove;
// 	}
// 	else
// 		ft_printf("\nPilha Vazia!\n");
// 	return NULL;
// }
// void imprimir_pilha(t_node *stack, char c){
// 	ft_printf("\n-------------- PILHA - ");
// 	ft_printf("%c",c);
// 	ft_printf(" ----------------\n");
// 	while (stack){
// 		ft_printf("%d\t",stack->data);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n-------------- FIM DA PILHA ---------\n");
// }

void shift_up(t_stack *stack)
{
	t_node *aux = malloc(sizeof(t_node));
	t_node *new = malloc(sizeof(t_node));

	if (new){
		new->data = stack->topo->data;
		new->next = NULL;
		desempilhar(stack);
		//é o primeiro?
		if (stack->topo == NULL)
			stack->topo = new;
		else{
			aux = stack->topo;
			while (aux->next)
				aux = aux->next;
			aux->next = new;
		}
		stack->tam++;
	}
	else
		ft_printf("Erro ao alocar Memoria!\n");
}

void rotate_all(t_stack *stackA, t_stack *stackB)
{
	shift_up(stackA);
	shift_up(stackB);
}

void imprimir_pilha(t_stack *stack, char c){
	ft_printf("\n-------------- PILHA - ");
	ft_printf("%c",c);
	ft_printf(" tam: %d----------------\n", stack->tam);
	t_node *aux = stack->topo;
	while (aux){
		ft_printf("%d\t",aux->data);
		aux = aux->next;
	}
	ft_printf("\n-------------- FIM DA PILHA ---------\n");
}

// void inserir_no_fim(t_node **stack, int value)
// {
// 	t_node *new = malloc(sizeof(t_node));
// 	t_node *aux = malloc(sizeof(t_node));
	
// 	if (new){
// 		new->data = value;
// 		new->next = NULL;
		
// 		//é o primeiro?
// 		if (*list == NULL)
// 			*list = new;
// 		else {
// 			aux = *list;
// 			while(aux->next)
// 				aux = aux->next;
// 			aux->next = new;
// 		}
// 	}
// 	else
// 		ft_printf("Erro ao alocar memoria!\n");
// }

// t_node *swap_ab(t_node *stackA, t_node *stackB)
// {
// 	// t_node *remover = NULL;

// 	stackB = empilhar(stackB, stackA->data);
// 	ft_printf("\n--------------------------------------------------\n");
// 	return(stackB);
// }

void push_b(t_stack *stackA, t_stack *stackB){
	t_node *remover = NULL;

	empilhar(stackB, stackA->topo->data);
	remover = desempilhar(stackA);
	ft_printf("\n--------------------------------------------------\n");
}

void push_a(t_stack *stackA, t_stack *stackB){
	t_node *remover = NULL;

	empilhar(stackA, stackB->topo->data);
	remover = desempilhar(stackB);
	ft_printf("\n--------------------------------------------------\n");
}

void swap(t_stack *stackA){
	t_node *aux1 = NULL;
	t_node *aux2 = NULL;

	aux1 = desempilhar(stackA);
	aux2 = desempilhar(stackA);
	empilhar(stackA, aux1->data);
	empilhar(stackA, aux2->data);
}

void swap_ab(t_stack *stackA, t_stack *stackB){
	t_node *aux1 = NULL;
	t_node *aux2 = NULL;

	aux1 = desempilhar(stackA);
	aux2 = desempilhar(stackA);
	empilhar(stackA, aux1->data);
	empilhar(stackA, aux2->data);

	aux1 = desempilhar(stackB);
	aux2 = desempilhar(stackB);
	empilhar(stackB, aux1->data);
	empilhar(stackB, aux2->data);
}

int	main()
{
	// t_node *remover = NULL;
	t_stack stackA;
	t_stack stackB;

	ft_printf("****************** Criar as Pilhas ******************\n");
	criar_pilha(&stackA);
	criar_pilha(&stackB);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	ft_printf("\n****************** Empilhar Stack A ******************\n");
	empilhar(&stackA, 3);
	empilhar(&stackA, 2);
	empilhar(&stackA, 1);
	imprimir_pilha(&stackA, 'A');
	ft_printf("\n****************** Empilhar Stack B ******************\n");
	empilhar(&stackB, 5);
	empilhar(&stackB, 4);
	empilhar(&stackB, 3);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	ft_printf("\n****************** Push AB ******************\n");
	push_b(&stackA, &stackB);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	ft_printf("\n****************** Push BA ******************\n");
	push_a(&stackA, &stackB);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	ft_printf("\n****************** Swap A ******************\n");
	swap(&stackA);
	imprimir_pilha(&stackA, 'A');
	ft_printf("\n****************** Swap B ******************\n");
	swap(&stackB);
	imprimir_pilha(&stackB, 'B');
	
	ft_printf("\n****************** Swap AB ******************\n");
	swap_ab(&stackA, &stackB);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	
	ft_printf("\n****************** Rotate A ******************\n");
	shift_up(&stackA);
	imprimir_pilha(&stackA, 'A');

	ft_printf("\n****************** Rotate A ******************\n");
	shift_up(&stackA);
	imprimir_pilha(&stackA, 'A');

	ft_printf("\n****************** Rotate A ******************\n");
	shift_up(&stackA);
	imprimir_pilha(&stackA, 'A');

	ft_printf("\n****************** Rotate AB ******************\n");
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	rotate_all(&stackA, &stackB);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
	// t_node *stackA = NULL;
	// t_node *stackB = NULL;
	// t_node *remover = NULL;
	// //push - empilhar;
	// stackA = empilhar(stackA, 1);
	// stackA = empilhar(stackA, 2);
	// stackB = empilhar(stackB, 3);
	// stackB = empilhar(stackB, 4);
	// //imprimir pilha
	// imprimir_pilha(stackA, 'A');
	// imprimir_pilha(stackB, 'B');
	// //pop - Desempilhar;

	// stackB = swap_ab(stackA, stackB);  ////consigo alterar a lista da pilha B porém não consigo alterar a lista da pilha A enquanto altero a da Pilha B.
	// remover = desempilhar(&stackA);
	// // stackA = desempilhar(&stackA);
	// imprimir_pilha(stackA, 'A');   
	// imprimir_pilha(stackB, 'B');
	// // if (remover){
	// // 	ft_printf("\nElemento removido com sucesso!\n");
	// // }
	// // else
	// // 	ft_printf("\nSem Nó a remover!\n");
	// // imprimir_pilha(stackA, 'A');
	// // imprimir_pilha(stackB, 'B');
}
