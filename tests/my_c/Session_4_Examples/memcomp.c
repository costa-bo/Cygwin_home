#include <stdio.h>
#include <strings.h>

typedef struct{
    char username[8 + 1];
    char password[8 + 1];
} STRUCT_CREDENTIALS_T;

enum {PROG_NAME, USERNAME, PASSWORD};

const STRUCT_CREDENTIALS_T superuser = {"adminusr","n#ns1!ii"}; // 8 bytes for each field!

unsigned char check_super(STRUCT_CREDENTIALS_T *p)
{
    if(p == NULL)
    {
        printf("check_superuser(): NULL argument received!\n");
        return 0;
    }
    return ( (memcmp(p, &superuser, sizeof(STRUCT_CREDENTIALS_T)) == 0)?1:0 );
}

int main(int argc, char **argv)
{
    STRUCT_CREDENTIALS_T myuser;
    
    if(argc != 3)
    {
        printf("Usage:\n%s username password\n",argv[PROG_NAME]);        
        return 1; // Error
    }    
    
    // Here we have exactly 3 commandline arguments
    if(strlen(argv[USERNAME]) <= 8)
    {
        memcpy(&myuser.username, argv[USERNAME], sizeof(myuser.username));
    }
    else
    {
        printf("Username must have max 8 characters. You gave %d characters and this is a problem.\n", strlen(argv[USERNAME]));
        return 1; // Error        
    }        
    
    if(strlen(argv[PASSWORD]) <= 8)
    {
        memcpy(&myuser.password, argv[PASSWORD], sizeof(myuser.password));
    }
    else
    {
        printf("Password must have max 8 characters. You gave %d characters and this is a problem.\n", strlen(argv[PASSWORD]));
        return 1; // Error        
    }
     
    if ( check_super(&myuser) )
    {
        printf("User is administrator!\n");     
        return 0;
    }
    else
    {
        printf("Sorry!\n");
        return 1;
    }
    // Unreachable
    return 0;
}

