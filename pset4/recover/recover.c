#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512
int main(int argc, char *argv[])
{

   // Open memory card
   if (argc!=2)
   {
      printf("Usage: ./recover image\n");
      return 1;
   }

   // Open input file
   char *infile = argv[1];
   FILE *inptr = fopen(infile, "r");
   if (inptr == NULL)
   {
      fprintf(stderr, "Could not open %s.\n", infile);
      return 1;
   }

   // Create Buffer
   unsigned char buff[block_size];

   // Initialise file counter
   int jpg_counter = 0;
   FILE *outptr = NULL;

   // Cheeck if jpeg is found
   int jpgFound = 0; // False

   // Iterate thorugh blocks of 512 bytes
   while (fread(&buffer, sizeof(buff), 1, inptr)) || feof ((inptr) == 1)
   {
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0 == 0xe0))
      {
         if (jpgFound == 1)
         {
            fclose(outptr);
         }

         sprintf(outfile, "%03i.jpg", jpgCounter);
         outptr = fopen(outfile, "w");
         jpgCounter++;
      }

      else (outptr != NULL)
      {
         fwrite (buffer, sizeof(buffer), 1, outptr)
      }

   }

   if (outptr == NULL)
   {
      fclose(outptr);
   }

   if(inptr == NULL)
   {
      fclose(inptr);
   }

   // Free memory for image
   free(image);

   return 0;

}
