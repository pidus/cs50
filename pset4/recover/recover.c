#include <stdio.h>
// #include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK 512 //block size of FAT
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("usage: recover file\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("unable to read file\n");
        return 2;
    }

    //set up a few things
    BYTE buffer[BLOCK];
    FILE *img = NULL;
    int count = 0;
    char filename[8]; //8 characters => '000.jpg\0'

    while (true)
    {
        int fread_return = fread(&buffer, BLOCK, 1, file);
        if (fread_return != 1)
        {
            fclose(img);
            // printf("loop end\n");
            break; //get out of the loop
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //jpeg signature logic
        {
            if (img != NULL) //new image except first jpg
            {
                fclose(img);
                count++;
                // printf("file closed\n");
            }
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            fwrite(&buffer, BLOCK, 1, img);
            // printf("new img\n");
        }
        else
        {
            if (img != NULL) //some jpg found previously
            {
                fwrite(&buffer, BLOCK, 1, img);
                // printf("writing\n");
            }
        }
    }
    fclose(file);
    return 0;
}
