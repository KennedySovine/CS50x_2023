#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 2){
      printf("Usage: ./recover image");
      return 1;
  }
  FILE *card = fopen(argv[1], "r");
  unsigned char *buffer = malloc(512);
  if (buffer == NULL){
      return 1;
  }
  char *filename = malloc(3 * sizeof(int));
  int photoc = 0;

  while (fread(buffer, sizeof(unsigned char), 512, card) == 512){
      if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
          if (photoc == 1){
              sprintf(filename, "%03i.jpg", photoc);
              FILE *imageF = fopen(filename, "w");
              fwrite(buffer, 1, 512, imageF);
              fclose(imageF);
          }
          else{
              sprintf(filename, "%03i.jpg", photoc);
              FILE *imageF = fopen(filename, "w");
              fwrite(buffer, 1, 512, imageF);
              fclose(imageF);
          }
          photoc++;
      }
      else if (photoc != 0){
          FILE *imageF = fopen(filename, "a");
          fwrite(buffer, 1, 512, imageF);
          fclose(imageF);
      }
  }
  free (buffer);
  free(filename);
  fclose(card);
  printf("contagem = %i\n", photoc);
}