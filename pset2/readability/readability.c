#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>


int main(void)
{
   // Get user input for sentence
   string text = get_string("Text: ");

   
   // Letter count
   int count_letters = strlen(text);
   int letters = 0;
   for (int i = 0; (i < count_letters); i++)
   {
      if (isalpha(text[i]))
      {
         letters++;
      }
   }

   // Word count
   int count_words = strlen(text);
   int words = 1; 
   for (int i = 0; (i < count_words); i++)
   {
      if (isspace(text[i]))
      {
         words++;
      }
   }
   printf("word(s)%i\n", words);
   
   // Sentence count
   int count_sentences = strlen(text);
   int sentences = 0; 
   for (int i = 0; (i < count_sentences); i++)
   {
      if (text[i] == '.' || text[i] == '!' || text[i] == '?')
      {
         sentences++;
      }
   } 
   
   // Calculate the Coleman-Liau index
   float L = ((float)letters / words) * 100.00;
   float S = ((float)sentences / words) * 100.00;
   float index = 0.0588 * L - 0.296 * S - 15.8;
   int grade = round(index);
   
   if (grade < 1)
   {
      printf("Before Grade 1\n");
   }
   else if (grade > 16)
   {
      printf("Grade 16+\n");
   }
   else 
   {
      printf("Grade %i\n", grade);
   }
}