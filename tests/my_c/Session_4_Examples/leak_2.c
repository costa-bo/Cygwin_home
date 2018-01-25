#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_USER_INPUT (5)
#define MAX_USER_INPUT (5 * 1024 * 1024)
#define B_FALSE 0
#define B_TRUE 1
int main()
{
    char *user_input;
    unsigned char repeat = B_FALSE;

    do
    {
        repeat = B_FALSE;
        if( (user_input = (char *)malloc(MAX_USER_INPUT*sizeof(char))) == NULL )
        {
            printf("No more free memory!\n");
            return 1;
        }

        printf("Type something of %d to %d characters: ", MIN_USER_INPUT, MAX_USER_INPUT);

        scanf("%s",user_input); 

	if(strlen(user_input) < MIN_USER_INPUT)
        {
            printf("Input is less than %d bytes! Please try again.\n", MIN_USER_INPUT);
            repeat = B_TRUE;
        }

    } while (repeat);

    printf("You typed: %s\n", user_input);
    free(user_input);

    return 0;
}
