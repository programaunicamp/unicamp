#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
	
	

	int num2=0;
	int num;

pthread_t threads[3];

sem_t temp_H, temp_S, temp_O;


void *thr_Hidrogenio(void *arg){

	int h = 0;

	

	for(;;){
		
		
		sem_wait(&temp_H);
		
		
		
		printf("H");
		h++;
		if(h==2){
			
		sem_post(&temp_S);
		h=0;
		}
	
	}
	
	pthread_exit(NULL);
}

void *thr_Enxofre(void *arg){
	
	int s = 0;
	
	for(;;){
		
		
		
		sem_wait(&temp_S);
		
			printf("S");
			s++;
			
			if(s==1){
				
				sem_post(&temp_O);
				sem_post(&temp_O);
				sem_post(&temp_O);
				sem_post(&temp_O);
				s=0;
			}
	}
	pthread_exit(NULL);
}

void *thr_Oxigenio(void *arg){
	
	int o = 0;
	
	for(;;){
		
	
		
		sem_wait(&temp_O);
		
			printf("O");
			o++;
			
			if(o==4){
				
				printf("\n");
				num2++;
				
				if(num!=num2){
				
				sem_post(&temp_H);
				sem_post(&temp_H);
				o=0;
				}
			}
	}

	

	pthread_exit(NULL);
}
	
	

int main(void) {
	
	

	
	scanf("%d",&num);
	
	sem_init(&temp_H, 0, 2);
  	sem_init(&temp_S, 0, 0);
  	sem_init(&temp_O, 0, 0);
	
	pthread_create(&(threads[0]),NULL,thr_Hidrogenio,NULL);
	pthread_create(&(threads[1]),NULL,thr_Enxofre,NULL);
	pthread_create(&(threads[2]),NULL,thr_Oxigenio,NULL);	
	
	
	//HHSOOOO
	
	pthread_join(threads[0],NULL);
	pthread_join(threads[1], NULL);	
	pthread_join(threads[2], NULL);


	
	
	
	



	return 1;
}
