#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#define MAX_PID 1000
#define MIN_PID 100
const int max_size = MAX_PID - MIN_PID;
int map[900]={0};
int allocate_map(){
    printf("Started marking every bitmap free");
    int i=0;
    while(i<max_size){
        map[i++]=0;//mark everyone as zero
    }
    printf("Successfully marked");
    return 1;
}
int allocate_pid(){
    int i=0;
    while(i<max_size){
        if(map[i]==0){
            map[i]=1;
            return MIN_PID+i;
        }
        else
        {
         i++;   
        }
        if(i==max_size-1){
            printf("No available PID");
            return 1;
        }
    }
}

void release_pid(int pid){
    if(pid<1000 &&pid>=100)
    {
        printf("Releasing PID");
        map[pid-MIN_PID]==0;
        printf("Released PID %d",pid);
    }else
    {
        printf("Invalid PID");
    }
    
}

void *ThreadFun(void *threadid) {
    sleep(1);
    int tid;
    tid = allocate_pid();
    printf("Hello World! Thread ID, %d\n", tid);
    release_pid(tid);
    pthread_exit(NULL);
}
int main () {
    int a=allocate_map();
    printf("Enter the no of threads you want:-");
    int n;
    scanf("%d",&n);
    pthread_t threads[n];
    int i;
    for( i = 0; i < n; i++ ) {
          pthread_create(&threads[i], NULL, ThreadFun,NULL);
          pthread_join(threads[i],NULL);
   }

    for(i=0; i<n; i++)
        pthread_join(threads[i],NULL);

        printf("Hello after");
        pthread_exit(release_pid);

}