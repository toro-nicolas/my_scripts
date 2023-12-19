/*
** EPITECH PROJECT, 2023
** csfml_audio
** File description:
** All the functions related to audio in CSFML
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
