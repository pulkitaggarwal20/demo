#include<stdio.h>

int main(){
    char op;
    double n1,n2;
    printf("Enter operator(+,-,*,/):");
    scanf("%c",&op);
    printf("Enter two numbers:");
    scanf("%lf %lf",&n1,&n2);
    switch(op){
        case'+': printf("%.2lf\n",n1+n2);
        break;
        case'-': printf("%.2lf\n",n1-n2);
        break;
        case'*': printf("%.2lf\n",n1*n2);
        break;
        case'/':
             if(n2 !=0) printf("%.2lf\n",n1/n2);
             else printf("Error! Div by zero.\n");
             break;
        default: printf("Error! Invalid operator.\n");
    }
    return 0;
}