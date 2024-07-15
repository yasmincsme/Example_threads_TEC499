#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
 
#define NUM_THREADS 5
 
void* routine() {
	printf("Test from threads\n");
	sleep(3);
	printf("ending thread\n");
}

int main(int argc, char *argv[]) {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);


	pthread_join(t1, NULL); //wait for the thread
	pthread_join(t2, NULL); //

	return 0;
}