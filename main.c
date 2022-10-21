#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//#include "bits/mathcalls.h"

#define STEP 0.001
#define COEF 9
#define GROWTH 0.07

double abs_d(double x)
{
    return ((x >= 0) ? x : (-1) * x);
}

double oscillator(double osc, double coef)
{
    return abs_d(sin(osc) * coef);
}

char getCoords(double osc, double coef)
{
    return (char)(((int)(round(oscillator(osc, coef))) % 10) + '0');
}

int winWidth = 50;  // 50
int winHeight = 30; // 30

int main(void)
{
    char buffer[winHeight * winWidth];
    memset(buffer, ' ', winHeight * winWidth);
    memmove(buffer, "                          --:                                             .-*.:-                                           -:.*.  -.                                       :-  =-:   :-                                    .-.   =.-    .-.                                 -:    ::.-      -:                              :-      =  =       :-                           .-.      .-  =         -.                        -:        -.  =          :-                     :-          =   =           .-.                 .-.          ::   =             -:               -:            =    =              .-            .-.           ..+... =                -.         -:..:::::::::::..=....=-::::::::::::::::=-       +==--::..         =    ::         ..:::::-=        -:    ..::::::::.-:   ::  .::::::.     -:          .-             .:+:::--::.           -.             -:             =   -             .-                .-.           -.  =            ::                   -:          .:  =           -.                     .-          =  =         .-                         -:        =  =        :-                           .-       -. =       -:                              -:     .- =      =.                                .-     = -    .-                                    -:   =.-   -:                                      .-  :=:  -.                                         -: *:.-                                            :-*--                                               -:                                                                        ", 29 * 50);
    char coord[7] = "\x1b[01;5H";
    size_t cpt = 0;
    double osc = 0;

    while (1)
    {

        printf("\x1b[2J");
        printf("%s", coord);

        // fflush(stdout);

        for (int i = 0; i < winHeight * winWidth; i++)
        {
            putchar((i % winWidth) ? buffer[i] : '\n');
        }

        printf("%lu - %c", cpt, coord[3]);

        osc += GROWTH;
        coord[3] = getCoords(osc, COEF);

        fflush(stdout);
        usleep(100 * 1000);
        //  sleep(1);
    }
}

//============================ scrap ==========================================

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

// printf("\x1b[1;5H");
// printf("%s", coord); // = "\x1b[X;YH"
// puts(coord);
//  coord[3] = '2';
// printf("\x1b[01;1H");

//(i%winWidth)*(((int)(i/winHeight))

// int Xoffset = 0;
// int Yoffset = 0;
// double Xpos = 0;
// double Ypos = 0;
// int Xcurrpos = 0;
// int Ycurrpos = 0;
// printf("\x1b[3J");
// printf("\x1b[01;1H");
// fflush(stdout);

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

//============================ test ===========================================

// assert(abs_d(-2) == 2);

// while (1)
// {
//     printf(" \n cpt: %li\n ", cpt);
//     printf("%c", getCoords(osc, COEF));
//     // printf("%i", round(oscillator(osc, 10)));
//     // printf("%f", oscillator(osc, 10));
//     // printf("%c", getCoords(coord, osc, 1));
//     fflush(stdout);
//     cpt++;
//     osc += GROWTH;
//     usleep(100 * 1000);
//     // sleep(1);
// }

// printf("\x1b[2J");
// for (int i = 0; i < winHeight * winWidth; i++)
//{
//    putchar((i % winWidth) ? buffer[i] : '\n');
//}