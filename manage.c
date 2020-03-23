#include<stdio.h>
#include<pthread.h>
#define MAX_PID 1000
#define MIN_PID 100
const int max_size = MAX_PID - MIN_PID;
int bitmap[max_size]={0};
int allocate_map(){
    printf("Started marking every bitmap free");
    int i=0;
    while(i<max_size){
        bitmap[i++]=0;//mark everyone as zero
    }
    printf("Successfully marked");
    return 1;
}
int allocate_pid(){
    int i=0,flag=0;
    while(i<max_size){
        if(bitmap[i]==0){
            bitmap[i]==1;
            printf("Allocated the PID");
            return max_size+i;
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
        bitmap[pid-MIN_PID]==0;
        printf("Released PID %d",pid);
    }else
    {
        printf("Invalid PID");
    }
    
}/*
void *myThread(void *var) 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread \n"); 
    return NULL; 
} 
int main(){
printf("Enter the no of threads you want:-");
int n;
scanf("%d",&n);
pthread_t thread_id[n]; 
printf("Before Thread\n");
for (int i = 0; i < n; i++)
{
    pthread_create(&(thread_id+i), NULL, myThread, NULL);

    pthread_join(thread_id[i], NULL);  
}
printf("After Thread\n"); 

}*/

void *ThreadFun(void *threadid) {
   int tid;
   tid = allocate_pid();
   printf("Hello World! Thread ID, %d\n", tid);
   pthread_exit(NULL);
}
int main () {
    int a=allocate_map();
    printf("Enter the no of threads you want:-");
    int n;
    scanf("%d",&n);
    pthread_t threads[n];
    int rc;
    int i;
    for( i = 0; i < n; i++ ) {
          printf("main() : creating thread, %d",i);
          pthread_create(&threads[i], NULL, ThreadFun,NULL);
   }
   pthread_exit(NULL);
}


/*          rc = pthread_create(&threads[i], NULL, ThreadFun, (void *)allocate_pid());
*/