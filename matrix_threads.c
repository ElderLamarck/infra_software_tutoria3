#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct linha{
	int *caracter_coluna;
	int tamanho;
	int soma;
}Linha;

void *linhaSoma(void *arg);

int soma_global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){

	int ordem;
	scanf("%d", &ordem);
	Linha *linhas[ordem];
	pthread_t threads[ordem];
	for(int i = 0; i < ordem; i++){	
		Linha* linha = malloc(sizeof(Linha));
		linha->tamanho = ordem;
		linha->caracter_coluna = (int *)malloc(ordem * sizeof(int));
		for(int j = 0; j < ordem; j++){
			scanf(" %d", &linha->caracter_coluna[j]);
		}
		if (pthread_create(&threads[i], NULL, linhaSoma, linha));
	}
	for (int i = 0; i < ordem; i++) {
		pthread_join(threads[i], NULL);
	}
	printf("%d\n", soma_global);
	return 0;
}

void *linhaSoma(void *arg){
	pthread_mutex_lock(&mutex);
	Linha *linha = (Linha *) arg;
	for(int i = 0; i < linha->tamanho; i++){
		linha->soma += linha->caracter_coluna[i];
	}
	pthread_mutex_unlock(&mutex);
	soma_global += linha->soma;
	return arg;
}