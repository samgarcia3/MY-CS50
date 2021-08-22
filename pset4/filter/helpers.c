#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each pixel H x W
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create pointers for each color
            BYTE* originalRed = &image[i][j].rgbtRed;
            BYTE* originalGreen = &image[i][j].rgbtGreen;
            BYTE* originalBlue = &image[i][j].rgbtBlue;

            // Average for each pixels RGB value for grayscale
            float grayAvg = round((*originalRed + *originalGreen + *originalBlue) / 3.0);

            // Set each pixel RGB value to the gray average
            *originalRed = grayAvg;
            *originalGreen = grayAvg;
            *originalBlue = grayAvg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterarate through each pixel H x W
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Create pointers for each color
            BYTE* originalRed = &image[i][j].rgbtRed;
            BYTE* originalGreen = &image[i][j].rgbtGreen;
            BYTE* originalBlue = &image[i][j].rgbtBlue;
            
            // Average for each pixel RGB value for sepia
            float sepiaRed = (int)round((.393 * *originalRed) + (.769 * *originalGreen) + (.189 * *originalBlue));
            // Values should not exceed 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            float sepiaGreen = (int)round((.349 * *originalRed) + (.686 * *originalGreen) + (.168 * *originalBlue));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            float sepiaBlue = (int)round((.272 * *originalRed) + (.534 * *originalGreen) + (.131 * *originalBlue));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            // Activate each pixel(s) RGB value to sepia average
            *originalRed = sepiaRed;
            *originalGreen = sepiaGreen;
            *originalBlue = sepiaBlue;
            
        }
    }
    return;
}


void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterarate through each pixel H x W
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Initialize a temporary source    
            RGBTRIPLE temp = image[i][width - 1 - j];  
            
            // Relocate left side pixel(s) to right side pixel(s)
            image[i][width - 1 - j] = image[i][j];  
            
            // left side pixel(s) replaced by temp source (right side)
            image[i][j] =  temp;                    
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    // Iterate throgh each pixel H x W
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;            
            sum_blue = sum_green = sum_red = counter = 0;
            
            //CORNERS            
            // Bottom right corner pixel
            if (i >= 0 && j >= 0)
            {
                sum_red += temp[i][j].rgbtRed;
                sum_green += temp[i][j].rgbtGreen;
                sum_blue += temp[i][j].rgbtBlue;
                counter++;
            }
            
            // Bottom left corner pixel
            if (i >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i][j-1].rgbtRed;
                sum_green += temp[i][j-1].rgbtGreen;
                sum_blue += temp[i][j-1].rgbtBlue;
                counter++;
            }
            
            // Top left corner pixel
            if (i - 1 >= 0 && j >= 0)
            {
                sum_red += temp[i-1][j].rgbtRed;
                sum_green += temp[i-1][j].rgbtGreen;
                sum_blue += temp[i-1][j].rgbtBlue;
                counter++;
            }
            
            // Top right corner pixel
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                sum_red += temp[i-1][j-1].rgbtRed;
                sum_green += temp[i-1][j-1].rgbtGreen;
                sum_blue += temp[i-1][j-1].rgbtBlue;
                counter++;
            }
            
            // Rows and Columns           
            // Bottom row pixels
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                sum_red += temp[i][j+1].rgbtRed;
                sum_green += temp[i][j+1].rgbtGreen;
                sum_blue += temp[i][j+1].rgbtBlue;
                counter++;
            }
            
            // Top row pixels
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                sum_red += temp[i-1][j+1].rgbtRed;
                sum_green += temp[i-1][j+1].rgbtGreen;
                sum_blue += temp[i-1][j+1].rgbtBlue;
                counter++;
            }
            
            // Left column pixels
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                sum_red += temp[i+1][j].rgbtRed;
                sum_green += temp[i+1][j].rgbtGreen;
                sum_blue += temp[i+1][j].rgbtBlue;
                counter++;
            }
            
            // Right column pixels
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                sum_red += temp[i+1][j-1].rgbtRed;
                sum_green += temp[i+1][j-1].rgbtGreen;
                sum_blue += temp[i+1][j-1].rgbtBlue;
                counter++;
            }
            
            // Non restricted pixels
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                sum_red += temp[i+1][j+1].rgbtRed;
                sum_green += temp[i+1][j+1].rgbtGreen;
                sum_blue += temp[i+1][j+1].rgbtBlue;
                counter++;
            }            //find average colour value
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}
