#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Check command line arguments (should be file name plus one other string)
    if (argc != 2)
    {
        printf("Usage: ./recover image.\n");
        return 1;
    }

    // Open file
    FILE *memoryCard = fopen(argv[1], "r");
    if (memoryCard == NULL)
    {
        printf("File cannot be opened.\n");
        return 2;
    }

    BYTE buffer[512]; //array of 512 integers BYTES
    int count = 0; // increment for each JPG image found to name image file accordingly
    char filename[8]; //create string for filename (include room for 8 characters to accommodate null terminator)

    FILE *imageFile; //creates an empty file to read images into

    while (fread(buffer, sizeof(buffer), 1, memoryCard) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (count > 0)
            {
                fclose(imageFile); // close image file that is currently being written to

                sprintf(filename, "%03d.jpg", count); // name image file
                count += 1; // increment count for next image file name

                imageFile = fopen(filename, "w");

                fwrite(buffer, sizeof(buffer), 1, imageFile);
            }

            if (count == 0)
            {
                sprintf(filename, "%03d.jpg", count);
                count += 1;

                imageFile = fopen(filename, "w");
                fwrite(buffer, sizeof(buffer), 1, imageFile);
            }
        }
        else if (count > 0)
        {
            fwrite(buffer, sizeof(buffer), 1, imageFile);
        }
    }
    fclose(imageFile);
    fclose(memoryCard);

    return 0;
}
