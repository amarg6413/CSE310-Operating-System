#include<stdio.h>
#include<pthread.h>.
#define MAX_PID 1000
#define MIN_PID 100
const int max_size = MAX_PID - MIN_PID;
int bitmap[max_size];
int allocate_map(){
    printf("Started marking every bitmap free");
    int i=0;
    while(i<max_size){
        bitmap[i++]=0;//mark everyone as zero
    }
    print("Successfully marked");
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
            
        }
    }
}
int main(){


}