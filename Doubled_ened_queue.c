#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int data;
    int size;
    int front;
    int end;
    int *arr;
}queue;

int isempty(queue*q){
    if(q->end==-1){
        return 1;
    }
    return 0;
}

int isfull(queue*q){
    if(q->end==q->size-1){
        return 1;
    }
    return 0;
}

void frontenqueue(queue*q,int value){
    if(isempty(q)){
        q->end++;
        q->arr[q->end]=value;
    }
    else{
        if(isfull(q)){
            q->arr[q->front+1]=value; // overwritring of element

        }
        else{
            for(int i=0;i<=q->end;i++){
                q->arr[i+1]=q->arr[i];
            }
            q->arr[q->front+1]=value;
        }
    }

}

void frontdequeue(queue*q){
    if(isempty(q)){
        printf("no element to delete");
    }
    else{
        for(int i=0;i<q->end;i++){
            q->arr[i]=q->arr[i+1];
            
        }
        q->end--;// decrement of end by 1
    }
}

void endenqueue(queue*q,int value){
    
     if(q->end<q->size-1){
        q->end++;
        q->arr[q->end]=value;
    }
    else{
        q->arr[q->end]=value;
    }
}

void enddequeue(queue*q){
    if(isempty(q)){
        printf("no elements");
    }
    else{
        q->end--;

    }
}

void print(queue*q){
    for(int i=q->front+1;i<=q->end;i++){
        printf("%d\n",q->arr[i]);
    }
}
int main(){
    queue * q=(queue*)malloc(sizeof(queue));
    q->size=5;
    q->front=-1;
    q->end=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    endenqueue(q,10);
     endenqueue(q,20);
      endenqueue(q,30);
       endenqueue(q,40);
        endenqueue(q,50);
        print(q);

        endenqueue(q,60);
        printf("\n");
        print(q);

        frontenqueue(q,100);
        printf("\n");
        print(q);
   
    frontdequeue(q);
    printf("\n");
        print(q);
    
    return 0;
}