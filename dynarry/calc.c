#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include "math.h"

static const double pi = 3.14159265;
static const double e = 2.7182818;

/* param: s the string
 param: num a pointer to double
 returns: true (1) if s is a number else 0 or false.
 postcondition: if it is a number, num will hold
 the value of the number
*/
int isNumber(char *s, double *num)
{
    char *end;
    double returnNum;
    
    if(strcmp(s, "0") == 0)
    {
        *num = 0;
        return 1;
    }
    else
    {
        returnNum = strtod(s, &end);
        /* If there's anythin in end, it's bad */
        if((returnNum != 0.0) && (strcmp(end, "") == 0))
        {
            *num = returnNum;
            return 1;
        }
    }
    return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
    /* FIXME: You will write this function */
    double firstNum;
    double secondNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    secondNum = topDynArr(stack);
    popDynArr(stack);
    
    total = firstNum + secondNum;
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
    /* FIXME: You will write this function */
    double firstNum;
    double secondNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    secondNum = topDynArr(stack);
    popDynArr(stack);
    
    total = firstNum - secondNum;
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
    /* FIXME: You will write this function */
    double firstNum;
    double secondNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    secondNum = topDynArr(stack);
    popDynArr(stack);
    
    total = firstNum / secondNum;
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
    double firstNum;
    double secondNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    secondNum = topDynArr(stack);
    popDynArr(stack);
    
    total = firstNum * secondNum;
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	the first is raised to the pow of the second
    and the result is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
    double firstNum;
    double secondNum;
    double total;
    
    secondNum = topDynArr(stack);
    popDynArr(stack);
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    total = pow(firstNum, secondNum);
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and its result
    is squared and is pushed back onto the stack.
*/
void squared(struct DynArr *stack)
{
    double firstNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    total = firstNum * firstNum;
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and its result
    is cubed and is pushed back onto the stack.
*/
void cubed(struct DynArr *stack)
{
    double firstNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    total = firstNum * firstNum * firstNum;
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and its result
 is the absolute value and is pushed back onto
 the stack.
*/
void absoluteValue(struct DynArr *stack)
{
    double firstNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    total = firstNum;
    
    if (total < 0) {
        total = -total;
    }
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
 pre: the element must be a non-negative number
	post: the top element is popped and its result
 is the square root and is pushed back onto
 the stack.
*/
void sqareRoot(struct DynArr *stack)
{
    double firstNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    total = sqrt(firstNum);
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and its result
 is the exponential and is pushed back onto
 the stack.
*/
void exponential(struct DynArr *stack)
{
    double firstNum;
    double secondNum;
    double total;
    
    secondNum = topDynArr(stack);
    popDynArr(stack);
    firstNum = e;
    
    total = pow(firstNum, secondNum);
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and its result
 is the ln of the element and is pushed back onto
 the stack.
*/
void ln(struct DynArr *stack)
{
    double firstNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    total = log(firstNum);
    pushDynArr(stack, total);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped and its result
 is the log of the element and is pushed back onto
 the stack.
*/
void Log(struct DynArr *stack)
{
    double firstNum;
    double total;
    
    firstNum = topDynArr(stack);
    popDynArr(stack);
    
    total = log10(firstNum);
    pushDynArr(stack, total);
}

double calculate(int numInputTokens, char **inputString)
{
    
    int i;
    double result = 0.0;
    char *s;
    struct DynArr *stack;
    
    double num;
    
    //set up the stack
    stack = createDynArr(20);
    
    // start at 1 to skip the name of the calculator calc
    for(i=1;i < numInputTokens;i++)
    {
        s = inputString[i];
        
        // Hint: General algorithm:
        // (1) Check if the string s is in the list of operators.
        //   (1a) If it is, perform corresponding operations.
        //   (1b) Otherwise, check if s is a number.
        //     (1b - I) If s is not a number, produce an error.
        //     (1b - II) If s is a number, push it onto the stack
        
        if(strcmp(s, "+") == 0)
            add(stack);
        else if(strcmp(s,"-") == 0)
            subtract(stack);
        else if(strcmp(s, "/") == 0)
            divide(stack);
        else if(strcmp(s, "x") == 0)
        /* FIXME: replace printf with your own function */
            multiply(stack);
        else if(strcmp(s, "^") == 0)
        /* FIXME: replace printf with your own function */
            power(stack);
        else if(strcmp(s, "^2") == 0)
        /* FIXME: replace printf with your own function */
            squared(stack);
        else if(strcmp(s, "^3") == 0)
        /* FIXME: replace printf with your own function */
            cubed(stack);
        else if(strcmp(s, "abs") == 0)
        /* FIXME: replace printf with your own function */
            absoluteValue(stack);
        else if(strcmp(s, "sqrt") == 0)
        /* FIXME: replace printf with your own function */
            sqareRoot(stack);
        else if(strcmp(s, "exp") == 0)
        /* FIXME: replace printf with your own function */
            exponential(stack);
        else if(strcmp(s, "ln") == 0)
        /* FIXME: replace printf with your own function */
            ln(stack);
        else if(strcmp(s, "log") == 0)
        /* FIXME: replace printf with your own function */
            Log(stack);
        else
        {
            // FIXME: You need to develop the code here (when s is not an operator)
            // Remember to deal with special values ("pi" and "e")
            
            isNumber(s, &num);
            
            //     (1b - I) If s is not a number, produce an error.
            if (*s == 0) {          // we dont have a number
                
                if (topDynArr(stack) == 'i') {
                    popDynArr(stack);
                    
                    if (topDynArr(stack) == 'p') {
                        popDynArr(stack);
                        pushDynArr(stack, pi);
                    }
                    else {
                        printf("error: you did not enter a number or operator that is known\n");
                    }
                }
                else if (topDynArr(stack) == 'e') {
                    popDynArr(stack);
                    pushDynArr(stack, e);
                }
                else {
                    printf("error: you did not enter a number or operator that is known\n");
                }
            }
            //     (1b - II) If s is a number, push it onto the stack
            else {
                pushDynArr(stack, *s);
            }
        }
    }	//end for
    
    /* FIXME: You will write this part of the function (2 steps below)
     * (1) Check if everything looks OK and produce an error if needed.
     * (2) Store the final value in result and print it out.
     */
    
    double validateTop = topDynArr(stack);
    if (validateTop == 0) {
        printf("error: something bad happend top of stack==0\n");
    }
    
    result = topDynArr(stack);
    printf("result: %f\n",result);
    
    return result;
}

int main(int argc , char** argv)
{
    // assume each argument is contained in the argv array
    // argc-1 determines the number of operands + operators
    
    if (argc == 1)
        return 0;
    
    calculate(argc,argv);
    
    return 0;
}




