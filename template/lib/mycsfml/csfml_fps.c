/*
** EPITECH PROJECT, 2023
** bsmyradar
** File description:
** The csfml_fps.c
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
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 1) {
        my_printf("%3d FPS\n", fps);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps++;
}
