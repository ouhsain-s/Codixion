#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int data_ready = 0;
int data = 0;

void *producer(void *arg)
{
	sleep(2); // simulate work

	pthread_mutex_lock(&mutex);

	data = 42;
	data_ready = 1;
	printf("Producer: data ready!\n");

	pthread_cond_signal(&cond); // نفيق consumer

	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *consumer(void *arg)
{
	pthread_mutex_lock(&mutex);

	while (data_ready == 0)
	{
		printf("Consumer: waiting...\n");
		pthread_cond_wait(&cond, &mutex);
	}

	printf("Consumer: got data = %d\n", data);

	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, consumer, NULL);
	pthread_create(&t2, NULL, producer, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}