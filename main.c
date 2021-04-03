/* Teste de um buffer circular
 *
 * Este programa serve para implementar e testar uma implementacao de buffer
 * circular
 */

#include <stdio.h>

char buffer[5];
int inicio = 0; /*define um inicio para o buffer*/
int i; /*variavel de preenchimento do buffer*/
int j; /*variavel de leitura do buffer*/
int tam = sizeof(buffer)/sizeof(buffer[0]); /*encontra o tamanho do buffer*/
int preenchido = 0; /*variavel que avalia o tanto do buffer que já foi utilizado. Assim e possivel checar se ainda ha espaço ou se o buffer esta vazio*/

void adicionar_buffer(char c) {
/* So vai ser possivel escrever no buffer, ou seja, adicionar c, se a quantidade de coisas ja adicionadas ao buffer for menor que o seu tamanho */
    if (preenchido < tam) {
        buffer[i] = c;
        i = (i + 1) % 5; /*aponta para a proxima posicao livre. a divisao em modulo garante que i retorne para o inicio depois que ultrapassar 5, ou seja garante a circularidade*/
        preenchido++; /*aponta que mais um elemento foi adicionado ao buffer*/
    }
}

void remover_buffer() {
/* So e possivel remover algo do buffer se ele não estiver vazio */
    if (preenchido > inicio) {
        j = (j + 1) % 5; /*aponta para a proxima posicao a ser lida. a divisao em modulo garante que j retorne para o inicio depois que ultrapassar 5, ou seja garante a circularidade*/
        preenchido--;
    }
}

void imprimir_buffer() {
	/* Imprime todo o conteudo do buffer */
    int t = (j)%5;
    if (preenchido > inicio && preenchido < tam) { 
    /* Enquanto o buffer nao estiver totalmente preenchido, eu vou imprimir a quantidade de itens que ja foram preenchidos */
		printf("%c", buffer[j]);
		do {
				printf(" %c", buffer[t + 1]);
                t=(t+1)%5;
            } while (t < preenchido);
        printf("nop");
		printf("\n");    
	}
    else if (preenchido == tam) {
    /* Se o buffer foi totalmente preenchido, imprimo todo o buffer */
    	int a;
    	printf("%c", buffer[j]);
    	for (a = 0; a < 4; a++) {
    		printf(" %c", buffer[t + 1]);
    		t=(t+1)%5;
		}
		printf("nop");
		printf("\n");
	}
	else if (preenchido == inicio) {
		printf("\n");
	} 
}

int main() {


  char c;  

  do {
    scanf("%c", &c);
    if (c == '\n') break;
    else if (c >= 48 && c <= 57) {
    /* Compara c com valores da tabela ascii. Se c for um numero, ele e adicionado ao buffer na posição indicada pelo indice de escrita i */
        adicionar_buffer(c);
        imprimir_buffer();
            }
    else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    /* Compara c com valores da tabela ascii. Se c for uma letra, removo o primeiro elemento do buffer indicado pelo indice j */
        remover_buffer();
        imprimir_buffer();
    }

  } while (1);
  
  
  return 0;
}

