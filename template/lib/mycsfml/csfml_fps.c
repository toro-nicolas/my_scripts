/*
** EPITECH PROJECT, 2023
** csfml_fps
** File description:
** All the functions related to fps in CSFML
*/

#include "mycsfml.h"

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.01) {
        my_printf("%3d FPS\n", fps);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}

int get_fps(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    int tmp = 0;

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 1) {
        tmp = fps;
        fps = 0;
        sfClock_restart(clock);
        return tmp;
    } else
        fps++;
    return -1;
}
