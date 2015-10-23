#include <stdio.h>
#include <string.h> // Contains strlen()
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h> // Contains atoi()

/*  Vigenere cipher
    Adam Intrator, 10/14/2015 
    
    Encrypts plain text inputed by user at the prompt.  
    Keyword is inputted as a command-line argument.
*/

int main(int argc, string argv[])
{
   
    // If user enters more than one (or zero) command-line arguments.
    if (argc != 2)
    {
        printf("Key must be one word.\n");
        
        exit(1);
    } 
    
    string keyword = argv[1]; 
    
   // Making sure keyword string has only letters
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        
        if isalpha(keyword[i])  
        {
            continue;
        }
    
        else
        {
            printf("Key must only contain letters.\n");
            
            exit(1);
        }
    }   
    
    
    string text = GetString();
    
    // Runs through each character, tests upper/lower/other 
    // and applies successive keys (i.e. successive letters) from keyword.
    for (int i = 0, j = 0, n = strlen(keyword), p = strlen(text); i < p; i++)
    {
        if (isupper(text[i]))
        {   
           // Adds (j)th letter of keyword (converted to lower case) 
           // to (ith) letter of inputted text.
           printf("%c", (((text[i] - 65 + tolower(keyword[j]) - 97) % 26)) + 65); 
            
            j = (j + 1) % n;
        }
        
        else if (islower(text[i])) 
        {
             printf("%c", (((text[i] - 97 + tolower(keyword[j]) - 97) % 26) + 97));
             
             j = (j + 1) % n;
        }
        
        else   
        {
            printf("%c", text[i]);  
        } 
    }
    
    printf("\n");
    
    return 0;
}


