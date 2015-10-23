#include <stdio.h>
#include <string.h> // Contains strlen()
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h> // Contains atoi()

/*  Caesar's cipher
    Adam Intrator, 10/14/2015 
    
    Encrypts plain text inputed by user at the prompt.  
    "Key" is inputted as a command-line argument.
*/

int main(int argc, string argv[])
{
   
    // If user enters more than one command-line argument.
    if (argc != 2)
    {
        printf("Key must be one number.\n");
        
        return(1);
    } 
    
    // Converts command-line "number" from string to int.
    int key = atoi(argv[1]);
    
    
    string text = GetString();
    
    // Runs through each character, tests upper/lower/other and applies key.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {   
            
            printf("%c", (((text[i] + key) - 65) % 26) + 65);
            
        }
        
        else if (islower(text[i])) 
        {
            printf("%c", (((text[i] + key) - 97) % 26) + 97);
        }
        
        else
            
        {
            printf("%c", text[i]);
           
        }
        
       
    }
    
    printf("\n");
    
    return 0;
}


