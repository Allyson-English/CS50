#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float rgb_sum = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;

            float rgb_avrg = round(rgb_sum / 3);

            int r_average = rgb_avrg;

            image[i][j].rgbtRed = r_average;
            image[i][j].rgbtGreen = r_average;
            image[i][j].rgbtBlue = r_average;
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
            // Red Pixels
            float redPixel_red = 0.393 * image[i][j].rgbtRed;
            float redPixel_green = 0.769 * image[i][j].rgbtGreen;
            float redPixel_blue = 0.189 * image[i][j].rgbtBlue;

            float sepiaRed_f = round(redPixel_red + redPixel_green + redPixel_blue);

            int sepiaRed = sepiaRed_f;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            // Green Pixels
            float greenPixel_red = 0.349 * image[i][j].rgbtRed;
            float greenPixel_green = 0.686 * image[i][j].rgbtGreen;
            float greenPixel_blue = 0.168 * image[i][j].rgbtBlue;

            float sepiaGreen_f = round(greenPixel_red + greenPixel_green + greenPixel_blue);

            int sepiaGreen = sepiaGreen_f;

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // Blue Pixels
            float bluePixel_red = 0.272 * image[i][j].rgbtRed;
            float bluePixel_green = 0.534 * image[i][j].rgbtGreen;
            float bluePixel_blue = 0.131 * image[i][j].rgbtBlue;

            float sepiaBlue_f = round(bluePixel_red + bluePixel_green + bluePixel_blue);

            int sepiaBlue = sepiaBlue_f;

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = width - 1;

    int left_r;
    int left_b;
    int left_g;
    int right_r;
    int right_g;
    int right_b;

    for (int i = 0; i < height; i++)
    {

// if image is even, pixel value should be replaced with pixel value in opposite array position up to middle pixel (don't go beyond middle pixel because that will create a mirror image)
        if (w % 2 == 0)
        {
            for (int j = 0; j < w / 2; j++)
            {
                left_r = image[i][j].rgbtRed;
                left_g = image[i][j].rgbtGreen;
                left_b = image[i][j].rgbtBlue;

                right_r = image[i][w - j].rgbtRed;
                right_g = image[i][w - j].rgbtGreen;
                right_b = image[i][w - j].rgbtBlue;

                image[i][j].rgbtRed = right_r;
                image[i][j].rgbtGreen = right_g;
                image[i][j].rgbtBlue = right_b;

                image[i][w - j].rgbtRed = left_r;
                image[i][w - j].rgbtGreen = left_g;
                image[i][w - j].rgbtBlue = left_b;
            }
        }
// if pixel is odd, switch value of pixel with that of opposite array up to the middle point but not including the center line, which will remain the same
        else if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                left_r = image[i][j].rgbtRed;
                left_g = image[i][j].rgbtGreen;
                left_b = image[i][j].rgbtBlue;

                right_r = image[i][w - j].rgbtRed;
                right_g = image[i][w - j].rgbtGreen;
                right_b = image[i][w - j].rgbtBlue;

                image[i][j].rgbtRed = right_r;
                image[i][j].rgbtGreen = right_g;
                image[i][j].rgbtBlue = right_b;

                image[i][w - j].rgbtRed = left_r;
                image[i][w - j].rgbtGreen = left_g;
                image[i][w - j].rgbtBlue = left_b;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    int redFinal;
    int blueFinal;
    int greenFinal;

// Make a copy of image so we aren't updating pixels based on pixels that are already blurred
//  To update: create three arrays (one for each color) and set value based on position of item in 2D array

    int imgCpyRed[height][width];
    int imgCpyGreen[height][width];
    int imgCpyBlue[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgCpyRed[i][j] = image[i][j].rgbtRed;
            imgCpyGreen[i][j] = image[i][j].rgbtGreen;
            imgCpyBlue[i][j] = image[i][j].rgbtBlue;
        }
    }


// at each pixel value, pull values of surrounding pixels and compute average

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int count = 0;
            float red_pixelValue = 0;
            float blue_pixelValue = 0;
            float green_pixelValue = 0;

            red_pixelValue += imgCpyRed[row][column];
            blue_pixelValue += imgCpyBlue[row][column];
            green_pixelValue += imgCpyGreen[row][column];
            count++;

            if (column + 1 < width)
            {
                red_pixelValue += imgCpyRed[row][column + 1];
                blue_pixelValue += imgCpyBlue[row][column + 1];
                green_pixelValue += imgCpyGreen[row][column + 1];
                count++;
            }
            if (column - 1 >= 0)
            {
                red_pixelValue += imgCpyRed[row][column - 1];
                blue_pixelValue += imgCpyBlue[row][column - 1];
                green_pixelValue += imgCpyGreen[row][column - 1];
                count++;
            }
            if (row - 1 >= 0)
            {
                red_pixelValue += imgCpyRed[row - 1][column];
                blue_pixelValue += imgCpyBlue[row - 1][column];
                green_pixelValue += imgCpyGreen[row - 1][column];
                count++;
            }
            if (column + 1 < width && row - 1 >= 0)
            {
                red_pixelValue += imgCpyRed[row - 1][column + 1];
                blue_pixelValue += imgCpyBlue[row - 1][column + 1];
                green_pixelValue += imgCpyGreen[row - 1][column + 1];
                count++;
            }
            if (column - 1 >= 0 && row - 1 >= 0)
            {
                red_pixelValue += imgCpyRed[row - 1][column - 1];
                blue_pixelValue += imgCpyBlue[row - 1][column - 1];
                green_pixelValue += imgCpyGreen[row - 1][column - 1];
                count++;
            }

            if (row + 1 < height)
            {
                red_pixelValue += imgCpyRed[row + 1][column];
                blue_pixelValue += imgCpyBlue[row + 1][column];
                green_pixelValue += imgCpyGreen[row + 1][column];
                count++;
            }

            if (row + 1 < height && column - 1 >= 0)
            {
                red_pixelValue += imgCpyRed[row + 1][column - 1];
                blue_pixelValue += imgCpyBlue[row + 1][column - 1];
                green_pixelValue += imgCpyGreen[row + 1][column - 1];
                count++;
            }

            if (row + 1 < height && column + 1 < width)
            {
                red_pixelValue += imgCpyRed[row + 1][column + 1];
                blue_pixelValue += imgCpyBlue[row + 1][column + 1];
                green_pixelValue += imgCpyGreen[row + 1][column + 1];
                count++;
            }

            red_pixelValue = round(red_pixelValue / count);
            blue_pixelValue = round(blue_pixelValue / count);
            green_pixelValue = round(green_pixelValue / count);

            redFinal = red_pixelValue;
            blueFinal = blue_pixelValue;
            greenFinal = green_pixelValue;

            image[row][column].rgbtRed = redFinal;
            image[row][column].rgbtBlue = blueFinal;
            image[row][column].rgbtGreen = greenFinal;
        }

    }
    return;
}
