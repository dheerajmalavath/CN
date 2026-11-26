#include<stdio.h>
int main(){
    int size,rate,time,stored=0,input,sent;
    printf("Enter Buckett size: ");
    scanf("%d",&size);
    printf("Enter output rate: ");
    scanf("%d",&rate);
    printf("Enter number of cycles: ");
    scanf("%d",&time);
    while(time--){
        printf("\nEnter incomming packets: ");
        scanf("%d",&input);
        stored+=input;
        if(stored>size){
            printf("Bucket overflow!! %d packets dropped.\n",stored-size);
            stored=size;
        }
        printf("Packets currently in the bucket: %d\n",stored);
        sent = (stored>=rate)?rate:stored;
        stored-=sent;
        printf("Packets sent: %d\n",sent);
        printf("Packets left: %d\n",stored);
    }
    return 0;
}