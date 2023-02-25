#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int avg = round((red+green+blue) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
     }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width / 2; j++){
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image [i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            float avg = 0.0;
            
            int red = 0;
            int green = 0;
            int blue = 0;
            
            for (int k = -1; k <= 1; k++){
                for (int l = -1; l <= 1; l++){
                    if (i + k != height && i + k != -1 && j + l != width && j + l != -1){
                        
                        red += temp[i + k][j + l].rgbtRed;
                        green += temp[i + k][j + l].rgbtGreen;
                        blue += temp[i + k][j + l].rgbtBlue;
                        avg++;
                    }
                }
            }
            
            image[i][j].rgbtRed = round(red / avg);
            image[i][j].rgbtGreen = round(green / avg);
            image[i][j].rgbtBlue = round(blue / avg);
        }
    }
    return;
}
