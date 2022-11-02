/*
    Name: Grant Lane
    Date: July 26, 2022
    Program that encipher's messages from the users
    input based on a key from the user
*/
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string input);
void encipher(string plaintext, int key);
char encipher_letter(char letter, int key);
char upper_over(char letter, int key);
char lower_over(char letter, int key);
char caesars_alg(int location, int key, int alpha_start);

int main(int argc, string argv[])
{
    //Case for the program to be ran correctly
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage ./caesar key\n");
        return 1;
    }
    //main program
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    encipher(plaintext, key);
    return 0;
}
/*
    Function that determines if the
    user's second argument is only digits
*/
bool only_digits(string input)
{
    int counter = 0;
    while (isdigit(input[counter]))
    {
        counter++;
    }
    //When counter is not equal to the length of input
    //it shows the input is something other than only digits
    return counter == strlen(input);
}
/*
    Function that prints the users plaintext
    enciphered
*/
void encipher(string plaintext, int key)
{
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {

            printf("%c", encipher_letter(plaintext[i], key));

        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
/*
    Function that encipher's a char
*/
char encipher_letter(char letter, int key)
{
    char new_char;
    int letter_loc = letter;
    int counter = 0;
    //Only letter's enter this function so you only need
    //to worry about uppers and lowers
    if (isupper(letter))
    {
        new_char = caesars_alg(letter_loc, key, 65);
    }
    else
    {
        new_char = caesars_alg(letter_loc, key, 96);
    }
    return new_char;
}
/*
    function that does the work of caeser's algorithm
    but handles the ascii number's as well
*/
char caesars_alg(int location, int key, int alpha_start)
{
    //alphastart is using 'a' as 0 as the start
    location -= alpha_start;
    location = (location + key) % 26;
    return location + alpha_start;
}