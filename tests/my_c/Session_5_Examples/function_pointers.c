#include <stdio.h> 

int add (int x, int y)
{
	return x + y; 
}

int mul (int x, int y)
{ 
	return x * y; 
}


void main()
{
    int (* p_func) (int , int);  // Function pointer 

    p_func = add; // Assign address to function pointer

    printf("Adding 2 and 3 : %i\n", p_func(2, 3)); //Call function through pointer
    
    p_func = mul; // Assign address to function pointer

    printf("Multiply 2 of 3 : %i\n", p_func(2, 3)); //Call function through pointer
   

}
