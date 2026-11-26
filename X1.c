#include<stdio.h>
int main(){
    char str[100];
    printf("Enter the String: ");
    fgets(str,sizeof(str),stdin);
    printf("Original String: %s",str);
    printf("Char\tASCII\tXOR\n");
    printf("----------------\n");
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='\n' || str[i]==' ') continue;
        printf("%c\t%d\t%d\n",str[i],str[i],str[i]^0);
    }
    return 0;
}