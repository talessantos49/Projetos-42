#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(){
  size_t num = 3;
  char stringA[] = "1234";
  char stringB[] = "1235";
  printf("String A: %s\n", stringA);
  printf("String B: %s\n", stringB);
  printf("Valor da comparação: %d\n\n", ft_strncmp(stringA, stringB, num));
  printf("Valor da comparação: %d\n\n", strncmp(stringA, stringB, num));

  return 0;
}
  