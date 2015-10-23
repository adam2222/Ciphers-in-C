#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


/* User inputs name (no special characters). 
Program returns initials in all-caps. */

int main(void)
{   
    
    char initials[10];
    
    string name = GetString();
    
    if (name != NULL)
    {   
        printf("%c", toupper(name[0]));
        
        // Cycling through "name" string one letter at a time
        for (int i = 1, j = 1, n = strlen(name); i < n; i++) 
        { 
            // If current character in "name" array is a space, 
            // add the next character to the "initials" array
            if (isspace(name[i]))
            { 
                initials[j] = name[i + 1];
                
                printf("%c", toupper(initials[j])); 
                j++;
            }  
             
        }
        printf("\n");
          
    }
    
}
