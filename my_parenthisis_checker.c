#include<stdio.h>
#include<stdio.h>
#define max 15
void push(char);
char stack[max];
int i,top=-1;
char pop();
void display();

void main(){
char e[max],temp;
display();
int count=1;
printf(" \n enter the expression\n");
scanf("%s",&e);
for(i=0;i<lenstr(e);i++){
if (e[i]=='('||e[i]=='{'||e[i]=='[')
{
    push (e[i]);
}
if(e[i]==')'||e[i]=='}'||e[i]==']'){
    if (top==1)
    {
        count=0;
    }
    else{
        temp = pop();
    }
    if(e[i]==')'&&(temp=='{ '||temp =='[')){
        count==0;
    }
    if (e[i]==']'&&(temp=='('||temp=='{')){
        count==0;
    }
    if(e[i]=='}' && (temp=='('||temp=='[')){
        count==0;
    }
}

}





}