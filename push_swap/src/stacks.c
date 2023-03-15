#include "../includes/push_swap.h"
#include <stdio.h>

typedef struct s_node{
	int data;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_stack{
	t_node *first;
    t_node *last;
	int tam;
} t_stack;

void criar_pilha(t_stack *stackA){
	stackA->first = NULL;
    stackA->last = NULL;
	stackA->tam = 0;
}

void imprimir_pilha(t_stack *stack, char c){
	ft_printf("\n-------------- PILHA - ");
	ft_printf("%c",c);
	ft_printf(" tam: %d----------------\n", stack->tam);
	t_node *aux = stack->first;
	while (aux){
		ft_printf("%d\t",aux->data);
		aux = aux->next;
	}
	ft_printf("\n-------------- FIM DA PILHA ---------\n");
}

void inserir_na_fila(t_stack *stack, int num){
	t_node *new = malloc(sizeof(t_node));
	// t_node *aux = malloc(sizeof(t_node));

	if (new){
		new->data = num;
		new->next = NULL;
		if (stack->first == NULL){
			stack->first = new;
			stack->last = new;
		}
		else{
			stack->last->next = new;
			stack->last = new;
		}
		stack->tam++;
	}
	else
		ft_printf("Erro ao alocar memoria!\n");
}

t_node *remover_da_fila(t_stack *stack){
	t_node *remover = NULL;
	if (stack->first){
		remover = stack->first;
		stack->first = remover->next;
		stack->tam--;
	}
	else
		ft_printf("\tFila Vazia\n");
	return remover;
}

void imprimir_fila(t_stack *stack){
	t_node *aux = malloc(sizeof(t_node));
	aux = stack->first;
	ft_printf("\n\t ------ Fila -------\n\t");
	while (aux){
		ft_printf("%d ", aux->data);
		aux = aux->next;
	}
	ft_printf("\n\t ------ Fim da FILA ------ \n");
}

void empilhar(t_stack *stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	if(new){
		new->data = value;
		new->next = stack->first;
		stack->first = new;
		stack->tam++;
	}
	else
		ft_printf("\nErro ao alocar memoria...\n");
}

t_node *desempilhar(t_stack *stack){
	if (stack->first){
		t_node *remove = stack->first;
		stack->first = remove->next;
		stack->tam--;
		return remove;
	}
	else
		ft_printf("\nPilha Vazia!\n");
	return NULL;
}

void remover_lista(t_stack *stack, int valor){
	t_node *inicio = stack->first;
	t_node *noARemover = NULL;

	if (inicio != NULL && stack->first->data == valor){
		noARemover = stack->first;
		stack->first = noARemover->next;
		if(stack->first == NULL)
			stack->last = NULL;
	}
	else {
		while (inicio != NULL && inicio->next != NULL && inicio->next->data != valor){
			inicio = inicio->next;
		}
		if (inicio != NULL && inicio->next != NULL){
			noARemover = inicio->next;
			inicio->next = noARemover->next;
			if (inicio->next == NULL)
				stack->last = inicio;
		}
	}
	if (noARemover){
		free(noARemover);
		stack->tam--;
	}
}

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

void shift_up(t_stack *stack)
{
	t_node *aux = malloc(sizeof(t_node));
	t_node *new = malloc(sizeof(t_node));

	if (new){
		new->data = stack->first->data;
		new->next = NULL;
		desempilhar(stack);
		//é o primeiro?
		if (stack->first == NULL)
			stack->first = new;
		else{
			aux = stack->first;
			while (aux->next)
				aux = aux->next;
			aux->next = new;
		}
		stack->tam++;
	}
	else
		ft_printf("Erro ao alocar Memoria!\n");
}

void shift_up_rr(t_stack *stackA, t_stack *stackB)
{
	shift_up(stackA);
	shift_up(stackB);
}

void inserir_no_inicio(t_stack *stack, int num)
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
        ft_printf("erro alocar Memoria!\n");
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

void shift_down(t_stack *stack)
{	
	int aux;
	aux = stack->last->data;
	remover_lista(stack, stack->last->data);
	inserir_no_inicio(stack, aux);
}

void shift_down_rr(t_stack *stackA, t_stack *stackB)
{	
	shift_down(stackA);
	shift_down(stackB);
}

void push_b(t_stack *stackA, t_stack *stackB){
	// t_node *remover = NULL;

	empilhar(stackB, stackA->first->data);
	// remover = desempilhar(stackA);
	desempilhar(stackA);
	ft_printf("\n--------------------------------------------------\n");
}

void push_a(t_stack *stackA, t_stack *stackB){
	// t_node *remover = NULL;

	empilhar(stackA, stackB->first->data);
	// remover = desempilhar(stackB);
	desempilhar(stackB);
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
	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
	// // ft_printf("\n****************** Empilhar Stack A ******************\n");
	// // empilhar(&stackA, 1);
	// // empilhar(&stackA, 2);
	// // empilhar(&stackA, 3);
	// // imprimir_pilha(&stackA, 'A');
	// // ft_printf("\n****************** Empilhar Stack B ******************\n");
	// // empilhar(&stackB, 4);
	// // empilhar(&stackB, 5);
	// // empilhar(&stackB, 6);
	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
	// // ft_printf("\n****************** Push AB ******************\n");
	// // push_b(&stackA, &stackB);
	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
	// // ft_printf("\n****************** Push BA ******************\n");
	// // push_a(&stackA, &stackB);
	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
	// // ft_printf("\n****************** Swap A ******************\n");
	// // swap(&stackA);
	// // imprimir_pilha(&stackA, 'A');
	// // ft_printf("\n****************** Swap B ******************\n");
	// // swap(&stackB);
	// // imprimir_pilha(&stackB, 'B');
	
	// // ft_printf("\n****************** Swap AB ******************\n");
	// // swap_ab(&stackA, &stackB);
	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
	
	// // ft_printf("\n****************** Rotate A ******************\n");
	// // shift_up(&stackA);
	// // imprimir_pilha(&stackA, 'A');

	// // ft_printf("\n****************** Rotate A ******************\n");
	// // shift_up(&stackA);
	// // imprimir_pilha(&stackA, 'A');

	// // ft_printf("\n****************** Rotate A ******************\n");
	// // shift_up(&stackA);
	// // imprimir_pilha(&stackA, 'A');

	// // // ft_printf("\n****************** shift_up_RR ******************\n");
	// // // imprimir_pilha(&stackA, 'A');
	// // // imprimir_pilha(&stackB, 'B');
	// // // shift_up_rr(&stackA, &stackB);
	// // // imprimir_pilha(&stackA, 'A');
	// // // imprimir_pilha(&stackB, 'B');
    // // ft_printf("\n****************** shift_down_RRR ******************\n");
    // // shift_down(&stackA);
    // // shift_down(&stackB);
	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
    // // ft_printf("\n****************** inserir no inicio ******************\n");
    // // inserir_no_inicio(&stackA, 25);
    // // inserir_no_inicio(&stackB, 1235);
   	// // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
    // // ft_printf("\n****************** inserir no fim ******************\n");
    // // inserir_no_fim(&stackA, 690);
    // // inserir_no_fim(&stackB, 18);
    // // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
    // // ft_printf("\n****************** desempulhar ******************\n");
    // // desempilhar(&stackA);
    // // desempilhar(&stackB);
    // // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
    // // ft_printf("\n****************** Remover no fim ******************\n");
    // // remover_no_fim(&stackA);
    // // remover_no_fim(&stackB);
    // // imprimir_pilha(&stackA, 'A');
	// // imprimir_pilha(&stackB, 'B');
	// ft_printf("\n***********************FILA ************************\n");
	// imprimir_fila(&stackA);
	// imprimir_fila(&stackB);
	// inserir_na_fila(&stackA, 1);
	// inserir_na_fila(&stackB, 1);
	// inserir_na_fila(&stackA, 2);
	// inserir_na_fila(&stackB, 2);
	// inserir_na_fila(&stackA, 3);
	// inserir_na_fila(&stackB, 3);
	// // imprimir_fila(&stackA);
	// // imprimir_fila(&stackB);
	// // remover_lista(&stackA, stackA.last->data);
	// // remover_lista(&stackB, stackB.last->data);
	// imprimir_fila(&stackA);
	// imprimir_fila(&stackB);
	// ft_printf("\n******************************SHIFT DOWN*********************\n");
	// shift_down(&stackA);
	// shift_down(&stackB);
	// imprimir_fila(&stackA);
	// imprimir_fila(&stackB);
	// shift_down(&stackA);
	// shift_down(&stackB);
	// imprimir_fila(&stackA);
	// imprimir_fila(&stackB);
	// ft_printf("\n******************************SHIFT DOWN*********************\n");
	// shift_down_rr(&stackA, &stackB);
	// imprimir_fila(&stackA);
	// imprimir_fila(&stackB);
}
