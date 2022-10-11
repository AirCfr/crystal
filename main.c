#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//#include "bits/mathcalls.h"

#define STEP 0.001

//(i%winWidth)*(((int)(i/winHeight))

int winWidth = 50;
int winHeight = 50;

int main(void)
{
    char buffer[winHeight * winWidth];
    memset(buffer, ' ', winHeight * winWidth);
    memmove(buffer, "                          --:                                             .-*.:-                                           -:.*.  -.                                       :-  =-:   :-                                    .-.   =.-    .-.                                 -:    ::.-      -:                              :-      =  =       :-                           .-.      .-  =         -.                        -:        -.  =          :-                     :-          =   =           .-.                 .-.          ::   =             -:               -:            =    =              .-            .-.           ..+... =                -.         -:..:::::::::::..=....=-::::::::::::::::=-       +==--::..         =    ::         ..:::::-=        -:    ..::::::::.-:   ::  .::::::.     -:          .-             .:+:::--::.           -.             -:             =   -             .-                .-.           -.  =            ::                   -:          .:  =           -.                     .-          =  =         .-                         -:        =  =        :-                           .-       -. =       -:                              -:     .- =      =.                                .-     = -    .-                                    -:   =.-   -:                                      .-  :=:  -.                                         -: *:.-                                            :-*--                                               -:                                                                        ", 29 * 50);

    // int Xoffset = 0;
    int Yoffset = 0;
    // double Xpos = 0;
    double Ypos = 0;
    // int Xcurrpos = 0;
    int Ycurrpos = 0;
    double osc = 0;

    // printf("\x1b[2J");
    // for (int i = 0; i < winHeight * winWidth; i++)
    //{
    //    putchar((i % winWidth) ? buffer[i] : '\n');
    //}

    /*while (1)
    {
        printf("\x1b[2J");
        printf("\x1b[H");
        for (int i = 0; i < winHeight * winWidth; i++)
        {
            putchar((i % winWidth) ? buffer[i] : '\n');
        }
        sleep(1);
    }*/

    while (1)
    {
        osc = 0;
        while (osc < 1)
        {
            printf("\x1b[2J");
            Ypos = sin(osc) * winHeight;
            if (Ypos - (double)Ycurrpos > 1)
            {
                Yoffset = (int)(Ypos - (double)Ycurrpos);
                Ycurrpos += Yoffset;
            }

            for (int i = 0; i < winHeight * winWidth; i++)
            {
                if (buffer[i] != ' ')
                {
                    if (i + Yoffset * winWidth > 0)
                    {
                        buffer[i + Yoffset * winWidth] = buffer[i];
                        buffer[i] = ' ';
                    }
                    else
                    {
                        osc = 1;
                    }
                }
            }

            printf("\x1b[H");
            for (int i = 0; i < winHeight * winWidth; i++)
            {
                putchar((i % winWidth) ? buffer[i] : '\n');
            }
            osc += STEP;
            Yoffset = 0;
            sleep(1);
        }
        while (Ypos > 0)
        {
            printf("\x1b[2J");
            Ypos = sin(osc) * winHeight;
            if ((double)Ycurrpos - Ypos > 1)
            {
                Yoffset = (int)((double)Ycurrpos - Ypos);
                Ycurrpos -= Yoffset;
            }

            for (int i = 0; i < winHeight * winWidth; i++)
            {
                if (buffer[i] != ' ')
                {
                    if (i + Yoffset * winWidth < winHeight * winWidth)
                    {
                        buffer[i - Yoffset * winWidth] = buffer[i];
                        buffer[i] = ' ';
                    }
                    else
                    {
                        osc = 1;
                    }
                }
                sleep(1);
            }

            printf("\x1b[H");
            for (int i = 0; i < winHeight * winWidth; i++)
            {
                putchar((i % winWidth) ? buffer[i] : '\n');
            }
            osc += STEP;
            Yoffset = 0;
        }
    }
}