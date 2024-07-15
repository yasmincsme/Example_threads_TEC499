#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
  
int mails = 0;
pthread_mutex_t mutex;

void* routine() {
	for(int i = 0; i<100000; i++) {
        pthread_mutex_lock(&mutex);
        ++mails;
        pthread_mutex_unlock(&mutex);
        system("clear");
        printf("%d\n", mails);
        //usleep(1);
    }
}

int main(int argc, char *argv[]) {
	pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);

    if(pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return 1;
    }

    if(pthread_create(&t2, NULL, &routine, NULL) != 0) {
        return 2;
    }


	pthread_join(t1, NULL); //wait for the thread
	pthread_join(t2, NULL); //

    pthread_mutex_destroy(&mutex);

    //printf("%d\n", mails);

	return 0;
}