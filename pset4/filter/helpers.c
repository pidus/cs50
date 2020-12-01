#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // formula
            BYTE k = (BYTE) round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = k;
            image[i][j].rgbtGreen = k;
            image[i][j].rgbtBlue = k;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int separr[3];
            // formula
            separr[0] = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            separr[1] = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            separr[2] = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            // clip to 255 max
            image[i][j].rgbtRed = (BYTE)(separr[0] > 255) ? 255 : separr[0];
            image[i][j].rgbtGreen = (BYTE)(separr[1] > 255) ? 255 : separr[1];
            image[i][j].rgbtBlue = (BYTE)(separr[2] > 255) ? 255 : separr[2];
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // even case
        if (width % 2 == 0)
        {
            int x = width / 2;
            for (int k = 0; k < x; k++)
            {
                RGBTRIPLE t;
                t = image[i][k];
                image[i][k] = image[i][(width - 1) - k];
                image[i][(width - 1) - k] = t;
            }
        }
        // odd case
        else
        {
            int x = (width - 1) / 2;
            for (int k = 0; k < x; k++)
            {
                RGBTRIPLE t;
                t = image[i][k];
                image[i][k] = image[i][(width - 1) - k];
                image[i][(width - 1) - k] = t;
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy to keep blur values
    RGBTRIPLE cpimg[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int r = 0, g = 0, b = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                // if pixel doesn't exists, skip
                if ((k < 0) || (k >= height))
                {
                    continue;
                }
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if ((l < 0) || (l >= width))
                    {
                        continue;
                    }
                    // total
                    r += image[k][l].rgbtRed;
                    g += image[k][l].rgbtGreen;
                    b += image[k][l].rgbtBlue;

                    count++;
                }
            }
            // generate copy
            cpimg[i][j].rgbtRed = (BYTE) round(r / (float) count);
            cpimg[i][j].rgbtGreen = (BYTE) round(g / (float) count);
            cpimg[i][j].rgbtBlue = (BYTE) round(b / (float) count);
        }
    }
    // overwrite image with copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = cpimg[i][j];
        }
    }
    return;
}
