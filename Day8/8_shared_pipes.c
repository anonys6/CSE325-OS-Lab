/*
int shmget(key_t key, size_t size, int shmflg); // returns shmid, -1 on error, 0 on success, 1 on already exists
void *shmat(int shmid, const void *shmaddr, int shmflg); // returns address of shared memory, -1 on error
int shmdt(const void *shmaddr); // returns 0 on success, -1 on error, detaches shared memory
int shmctl(int shmid, int cmd, struct shmid_ds *buf); // returns 0 on success, -1 on error, controls shared memory

*/