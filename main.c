#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//#include "bits/mathcalls.h"

#define STEP 0.001

//(i%winWidth)*(((int)(i/winHeight))

int winWidth = 50;  // 50
int winHeight = 30; // 30

// int main(void)
//{
//     printf("\x1b[3J");
//     fflush(stdout);
//     while (1)
//     {
//         printf("\x1b[3J"); // clear + clear scrollback
//         // printf("\x1b[5;5H"); //position
//         printf("\x1b[G");
//
//         fflush(stdout);
//
//         putchar('x');
//     }
// }

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

    size_t cpt = 0;
    char coord[7] = "\x1b[01;5H";

    printf("\x1b[3J");
    printf("\x1b[01;1H");
    fflush(stdout);

    while (1)
    {

        printf("\x1b[3J");
        printf("\x1b[01;1H");
        printf("%lu - %c", cpt, coord[2]);

        printf("\x1b[1;5H");
        // printf("%s", coord); // = "\x1b[X;YH"
        fflush(stdout);

        for (int i = 0; i < winHeight * winWidth; i++)
        {
            putchar((i % winWidth) ? buffer[i] : '\n');
        }

        fflush(stdout);
        cpt++;
        // coord[3] = '2';

        sleep(1);
    }

    // while (1)
    //{
    //     osc = 0;
    //     while (osc < 1)
    //     {
    //         printf("\x1b[3J");
    //         printf("\x1b[H");
    //         fflush(stdout);
    //
    //        Ypos = sin(osc) * winHeight;
    //        if (Ypos - (double)Ycurrpos > 1)
    //        {
    //            Yoffset = (int)(Ypos - (double)Ycurrpos);
    //            Ycurrpos += Yoffset;
    //        }
    //
    //        for (int i = 0; i < winHeight * winWidth; i++)
    //        {
    //            if (buffer[i] != ' ')
    //            {
    //                if (i + Yoffset * winWidth > 0)
    //                {
    //                    buffer[i + Yoffset * winWidth] = buffer[i];
    //                    buffer[i] = ' ';
    //                }
    //                else
    //                {
    //                    osc = 1;
    //                }
    //            }
    //        }
    //
    //        // printf("\x1b[H");
    //        for (int i = 0; i < winHeight * winWidth; i++)
    //        {
    //            putchar((i % winWidth) ? buffer[i] : '\n');
    //        }
    //        osc += STEP;
    //        Yoffset = 0;
    //        sleep(1);
    //    }
    //    while (Ypos > 0)
    //    {
    //        // printf("\x1b[2J");
    //        Ypos = sin(osc) * winHeight;
    //        if ((double)Ycurrpos - Ypos > 1)
    //        {
    //            Yoffset = (int)((double)Ycurrpos - Ypos);
    //            Ycurrpos -= Yoffset;
    //        }
    //
    //        for (int i = 0; i < winHeight * winWidth; i++)
    //        {
    //            if (buffer[i] != ' ')
    //            {
    //                if (i + Yoffset * winWidth < winHeight * winWidth)
    //                {
    //                    buffer[i - Yoffset * winWidth] = buffer[i];
    //                    buffer[i] = ' ';
    //                }
    //                else
    //                {
    //                    osc = 1;
    //                }
    //            }
    //            sleep(1);
    //        }
    //
    //        for (int i = 0; i < winHeight * winWidth; i++)
    //        {
    //            putchar((i % winWidth) ? buffer[i] : '\n');
    //        }
    //        osc += STEP;
    //        Yoffset = 0;
    //    }
    //}
}