#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b){

    if(*(int*)a>*(int*)b){
        return -1;
    }else if(*(int*)a<*(int*)b){
        return 1;
    }else{
        return 0;
    }
}

int A[10010];
int visit[10010];

int main(){

int M,tmp,ca,i;
int box,cb,sum;

while(scanf("%d",&M)!=EOF){
    for(i=0;i<10010;i++){
        A[i]=0;
        visit[i]=0;
    }

    ca=0;
    while(1){
        scanf("%d",&tmp);
        if(tmp==0){
            break;
        }
        A[ca]=tmp;
        ca++;
    }
    qsort(A,ca,sizeof(int),cmp);
    box=0;
    cb=0;
    sum=0;
    while(cb<ca){
        for(i=0;i<ca;i++){
            if(visit[i]==0){
                if((sum+A[i])<=M){
                    sum=sum+A[i];
                    visit[i]=1;
                    cb++;
                }
            }
        }
        box++;
        sum=0;
    }
    printf("%d\n",box);

}

return 0;
}
