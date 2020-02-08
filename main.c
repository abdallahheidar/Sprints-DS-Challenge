#include <stdio.h>
#include <stdlib.h>

#include"stack.h"
#include"queue.h"
#include"linkedlist.h"

struct   Node_t * start = NULL;
unsigned char checkForBalancedParantheses(char* str);
long long evaluate(char* expression);

int main()
{
	/*
    ST_stackInfo stack;
    int size = 12;

    createStack(&stack, size );
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    int data1;
    pop(&stack, &data1 );
    printf("%d stack: \n ", data1);

    ST_queueInfo queue;
    int queuesize = 12;

   createQueue(&queue, queuesize );
   enqueue(&queue, 1);
   enqueue(&queue, 2);
   enqueue(&queue, 3);
   enqueue(&queue, 4);
   enqueue(&queue, 6);


    int data2;
    dequeue(&queue, &data2 );
    printf("%d queue: \n ", data2);
	*/

 /*
    checkForBalancedParantheses("{{{{{5}}}}}");
           evaluate("{6+3+2-2}");

      */

      /* testing the linked list
     struct   Node_t *start = NULL;

      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_begin(start,data);

      printf("Enter value of element\n");
      scanf("%d", &data);
      insert_at_end(start, data);

      traverse(start);

      delete_from_begin(start);
      traverse(start);
     */

    int operation= 0;
    int data= 0;

	for (;;) {
		printf("1. Insert an element at the beginning of linked list.\n");
		printf("2. Insert an element at the end of linked list.\n");
		printf("3. Traverse linked list.\n");
		printf("4. Delete an element from beginning.\n");
		printf("5. Delete an element from end.\n");
		printf("6. Exit\n");

		scanf("%d", &operation);

		if (operation == 1) {
		  printf("Enter value of element\n");
		  scanf("%d", &data);
		  insert_at_begin(&start, data);
		}
		else if (operation == 2) {
		  printf("Enter value of element\n");
		  scanf("%d", &data);
		  insert_at_end(&start, data);
		}
		else if (operation == 3)
		  display(&start);
		else if (operation == 4)
		  delete_from_begin(&start);
		else if (operation == 5)
		  delete_from_end(&start);
		else if (operation == 6)
		  break;
		else
		  printf("Please enter valid input.\n");
  }
    return 0;
}

unsigned char checkForBalancedParantheses(char* str){
    int i = 0;
    ST_stackInfo stack;
    int size = 12;
    int  dummy;

    createStack(&stack, size );

    while(str[i] != '\0'){
    if(str[i] == '[' || str[i] == '(' || str[i] == '{'){
            push(&stack, str[i]);
        }
        else if(str[i] == ')'||str[i]=='}'||str[i]==')'){

                if(stack.sptr[stack.top-1] =='(' && str[i]==')')
                pop(&stack, &dummy);
                else if(stack.sptr[stack.top-1]=='{' && str[i] == '}')
                pop(&stack, &dummy);
                else if(stack.sptr[stack.top-1]=='[' && str[i]==']')
                pop(&stack, &dummy);
                else{
                    printf("not balanced");
                    return 0;
                 }
            } // END OF ELSE IF

       i++;
    }

	if( stack.top == 0 ){
		   printf("balanced");
			return 1;
	}else{
			printf("not balanced");
			return 0;
	}

}
