#include<stdio.h>
int main(){
    char str[100];
    int i;
    printf("Enter the string:");
    fgets(str,sizeof(str),stdin);
    printf("Original String: %s\n",str);
    printf("Char\tASCII\tXOR\tAND");
    printf("---------------------");
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='\n' || str[i]==' ') continue;
        char and_res = str[i]&127;
        char xor_res = str[i]^127;
        printf("%c\t%d\t%d\t%d\n",str[i],str[i],and_res,xor_res);
    }

    return 0;
}