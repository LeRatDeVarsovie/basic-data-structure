# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

/*
#################################
# BASIC DATA STRUCTURES LIBRARY #
#################################
*/

# define STACK_SIZE 100
# define ERROR_EMPTY_STACK -1

typedef struct {

    int array[STACK_SIZE];
    int top_index;

} stack;


stack* initialize_stack(void) {
    stack* instance = malloc(sizeof(stack));
    instance->top_index = 0;

    return instance;
}

int len(stack* instance) {
    int length = instance->top_index;

    return length;
}

void stack_element(int element, stack* instance) {
    instance->array[instance->top_index] = element;
    instance->top_index += 1;
}

int pop_element(stack* instance) {
    if (len(instance) == 0) {
        return ERROR_EMPTY_STACK;
    }
    else {
        instance->array[(instance->top_index)-1] = 0;
        instance->top_index--;
    }

    return 0;
}

void show_stack(stack* instance) {
    if (len(instance) > 0) {
        printf("\n");

        for (int i=len(instance)-1; i>=0; i--) {
            printf("\n|%d|", instance->array[i]);
        }

        printf("\n\n");
    }
    else {
        printf("\n\n| |\n\n");
    }
}

void free_stack(stack* instance) {
    free(instance->array);
    free(instance);
}


int main() {
    stack* instance = initialize_stack();
    printf("A stack have been initialized !\n");

    while (true) {
        system("clear");

        show_stack(instance);

        int answer;

        printf("Choose an option :\n\n1 . add an integer to the stack\n2 . pop an element (if the stack is empty)\n3 . exit\n");
        printf("\nEnter your answer : ");
        scanf("%d", &answer);

        switch (answer) {

        case 1:
            int element;

            printf("\nEnter the element you want to add : ");
            scanf("%d", &element);

            stack_element(element, instance);
            break;
        
        case 2:
            int status = pop_element(instance);

            if (status != 0) {
                printf("\nERROR: empty stack.\n");
                return -1;
            }
            break;
            
        case 3:
            return 0;
        
        default:
            printf("\nERROR: please select a valid option\n");
            main();

        }
    }

    free_stack(instance);
    
    return 0;
}   