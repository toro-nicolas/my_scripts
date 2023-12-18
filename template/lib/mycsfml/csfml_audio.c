/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** The csfml_music_sound.c
*/

#include "mycsfml.h"

void play_sound_with_sleep(char *file, float volume)
{
    sfMusic *sound = sfMusic_createFromFile(file);
    sfClock *clock = sfClock_create();

    if (sound) {
        sfMusic_setVolume(sound, volume);
    }
    sfMusic_play(sound);
    while (sfClock_getElapsedTime(clock).microseconds < sfMusic_getDuration
    (sound).microseconds);
    sfMusic_destroy(sound);
}
