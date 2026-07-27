/*

 * AUTHOR  : Abhijit Smiju Kunnel
 * CLASS   : CSE B
 * ROLL NO : 2
 * REG NO  : 25CS005
 
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

char stack[100];
int top;

void push(char x){
    stack[++top] = x;
}
char pop(){
    if (top == -1) return -1;
    return stack[top--];
}

int precedence(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    return 0;
}

void ConvertInfixToPostfix(char infix[], char postfix[]){
    top = -1;
    int k = 0;

    for(int i=0; infix[i]!='\0'; i++){
        char ch = infix[i];
        if(isalnum(ch)){
            postfix[k++] = ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch==')'){
            while(top != -1 && stack[top] != '('){
                postfix[k++] = pop();
            }
            if(top != -1){
                pop();
            }
        }
        else{
            while(top != -1 && precedence(stack[top]) >= precedence(ch)){
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while(top != -1){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
}

int PostfixEval(char postfix[]){
    int stack[100], top = -1;
    for(int i=0; postfix[i]!='\0'; i++){
        char ch = postfix[i];
        if(isalpha(ch)){
            printf("Enter integer value for %c: ", ch);
            top++;
            scanf("%d",&stack[top]);
        }
        else if(ch == '+'){
            int op = stack[top-1]+stack[top];
            top--;
            stack[top] = op;
        }
        else if(ch == '-'){
            int op = stack[top-1]-stack[top];
            top--;
            stack[top] = op;
        }
        else if(ch == '*'){
            int op = stack[top-1]*stack[top];
            top--;
            stack[top] = op;
        }
        else if(ch == '/'){
            int op = stack[top-1]/stack[top];
            top--;
            stack[top] = op;
        }
        else if(ch == '^'){
            int op = pow(stack[top-1],stack[top]);
            top--;
            stack[top] = op;
        }
    }
    return stack[top]; 
}

int main(){

    int option, f=1;
    char infix[100], postfix[100];

    do{
        printf("\n--- Choose the following options ---\n");
        printf("1) Enter Infix\n2) Convert to Postfix\n3) Postfix Evaluation\n4) Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter Infix: ");
            scanf("%s", infix);
            break;
        case 2:
            ConvertInfixToPostfix(infix, postfix);
            break;
        case 3:
            printf("Result: %d\n", PostfixEval(postfix));
            break;    
        case 4:
            printf("Exiting Program\n");
            f=0;
            break;
        default:
            printf("Invalid Input\n");
            f=0;
            break;
        }
    }while(f == 1);
    return 0;
}