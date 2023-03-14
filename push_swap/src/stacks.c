#include "../includes/push_swap.h"
#include <stdio.h>

typedef struct s_node{
	int data;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_stack{
	t_node *topo;
    t_node *fundo;
	int tam;
} t_stack;

void criar_pilha(t_stack *stackA){
	stackA->topo = NULL;
    stackA->fundo = NULL;
	stackA->tam = 0;
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
        new->next = stack->topo;
        stack->topo = new;
        stack->tam++;
    }
    else
        ft_printf("erro alocar Memoria!\n");
}
void remover_no_fim(t_stack *stack)
{
    t_node *new = malloc(sizeof(t_node));
    t_node *aux = malloc(sizeof(t_node));

    // if (stack->topo){
    //     t_node *remove = 
    // }
    if(new){
        new->data = 0;
        new->next = NULL;

        //é o primeiro?
        if (stack->topo == NULL)
            stack->topo = new;
        else{
            aux = stack->topo;
            while(aux->next)
                aux = aux->next;
            aux->next=new;
        }
        stack->tam--;
    }
    else
        ft_printf("Erro ao alocar memoria!\n");
}

void inserir_no_fim(t_stack *stack, int num)
{
    t_node *new = malloc(sizeof(t_node));
    t_node *aux = malloc(sizeof(t_node));

    if(new){
        new->data = num;
        new->next = NULL;

        //é o primeiro?
        if (stack->topo == NULL)
            stack->topo = new;
        else{
            aux = stack->topo;
            while(aux->next)
                aux = aux->next;
            aux->next=new;
        }
        stack->tam++;
    }
    else
        ft_printf("Erro ao alocar memoria!\n");
}

void shift_down(t_stack *stack)
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

// void inserir_no_fim(t_stack *stack, int num)
// {
//     t_node *new = malloc(sizeof(t_node));
// 	t_node *aux = malloc(sizeof(t_node));
	
// 	if (new){
// 		new->data = value;
// 		new->next = NULL;
		
// 		//é o primeiro?
// 		if (stack->topo == NULL)
// 			stack->topo = new;
// 		else {
// 			aux = stack->topo;
// 			while(aux->next)
// 				aux = aux->next;
// 			aux->next = new;
// 		}
//         stack->tam++;
// 	}
// 	else
// 		ft_printf("Erro ao alocar memoria!\n");
// }

// void inserir_no_fim(t_node **stack, int value)
// {
// 	t_node *new = malloc(sizeof(t_node));
// 	t_node *aux = malloc(sizeof(t_node));
	
// 	if (new){
// 		new->data = value;
// 		new->next = NULL;
		
// 		//é o primeiro?
// 		if (*stack == NULL)
// 			*stack = new;
// 		else {
// 			aux = *stack;
// 			while(aux->next)
// 				aux = aux->next;
// 			aux->next = new;
// 		}
// 	}
// 	else
// 		ft_printf("Erro ao alocar memoria!\n");
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
	empilhar(&stackA, 1);
	empilhar(&stackA, 2);
	empilhar(&stackA, 3);
	imprimir_pilha(&stackA, 'A');
	ft_printf("\n****************** Empilhar Stack B ******************\n");
	empilhar(&stackB, 4);
	empilhar(&stackB, 5);
	empilhar(&stackB, 6);
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

	// ft_printf("\n****************** shift_up_RR ******************\n");
	// imprimir_pilha(&stackA, 'A');
	// imprimir_pilha(&stackB, 'B');
	// shift_up_rr(&stackA, &stackB);
	// imprimir_pilha(&stackA, 'A');
	// imprimir_pilha(&stackB, 'B');
    ft_printf("\n****************** shift_down_RRR ******************\n");
    shift_down(&stackA);
    shift_down(&stackB);
	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
    ft_printf("\n****************** inserir no inicio ******************\n");
    inserir_no_inicio(&stackA, 25);
    inserir_no_inicio(&stackB, 1235);
   	imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
    ft_printf("\n****************** inserir no fim ******************\n");
    inserir_no_fim(&stackA, 690);
    inserir_no_fim(&stackB, 18);
    imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
    ft_printf("\n****************** desempulhar ******************\n");
    desempilhar(&stackA);
    desempilhar(&stackB);
    imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
    ft_printf("\n****************** Remover no fim ******************\n");
    remover_no_fim(&stackA);
    remover_no_fim(&stackB);
    imprimir_pilha(&stackA, 'A');
	imprimir_pilha(&stackB, 'B');
}
