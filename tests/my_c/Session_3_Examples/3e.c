#include <stdio.h>

int *pGlobal;
void func1()
{
    int local_int=0x01CAFE;
    pGlobal = &local_int;
}
void func2()
{
    int another_int = 0xBADBAD;
    printf("func2(): another_int contains 0x%x\n", another_int);
    getchar(); // Just for pause... Press enter to continue.
    *pGlobal = 0xFFFFFFFF; // This may crash, but probably
                           // it will overwrite another_int!!!
    printf("func2(): another_int contains 0x%x, but we didn't change that!!!\n", another_int);
    getchar(); // Just for pause... Press enter to continue.
}
void main()
{
    pGlobal = NULL;
    func1();
    printf("pGlobal points to 0x%p (Content: 0x%x)\n", \
                                 pGlobal, *pGlobal);
    getchar(); // Just for pause... Press enter to continue.                                 
    
    printf("Running func2()\n");
    getchar(); // Just for pause... Press enter to continue.
    
    func2();
    getchar(); // Just for pause... Press enter to continue.    
    
    printf("pGlobal points to 0x%p (Content: 0x%x)\n", \
                                 pGlobal, *pGlobal);
    printf("Running func1()\n");
    getchar(); // Just for pause... Press enter to continue.
    func1();
    printf("pGlobal points to 0x%p (Content: 0x%x)\n", \
                                 pGlobal, *pGlobal);
    getchar(); // Just for pause... Press enter to continue.                                 
}
