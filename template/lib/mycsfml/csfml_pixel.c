/*
** EPITECH PROJECT, 2023
** csfml_pixel
** File description:
** All the functions related to pixels in CSFML
*/

#include "mycsfml.h"

framebuffer_t *framebuffer_create(unsigned int width,
    unsigned int height)
{
    framebuffer_t *frame = malloc(sizeof(framebuffer_t));

    frame->pixels = malloc((width * height * 32) / 8);
    for (unsigned int i = 0; i < width * height; i++) {
        frame->pixels[(i * 4) + 0] = 0;
        frame->pixels[(i * 4) + 1] = 0;
        frame->pixels[(i * 4) + 2] = 0;
        frame->pixels[(i * 4) + 3] = 255;
    }
    frame->width = width;
    frame->height = height;
    return frame;
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
}

void framebuffer_draw(sfRenderWindow *window,
    framebuffer_t *framebuffer)
{
    sfTexture* texture = sfTexture_create(framebuffer->width,
        framebuffer->height);
    sfSprite* sprite = sfSprite_create();

    if (texture != NULL) {
        sfSprite_setTexture(sprite, texture, sfFalse);
        sfTexture_updateFromPixels(texture, framebuffer->pixels,
            framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void my_put_pixel(framebuffer_t *framebuffer,
    unsigned int x, unsigned int y, sfColor color)
{
    framebuffer->pixels[(x + (y * framebuffer->width)) * 4 + 0] = color.r;
    framebuffer->pixels[(x + (y * framebuffer->width)) * 4 + 1] = color.g;
    framebuffer->pixels[(x + (y * framebuffer->width)) * 4 + 2] = color.b;
    framebuffer->pixels[(x + (y * framebuffer->width)) * 4 + 3] = color.a;
}

void draw_square(framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color)
{
    for (unsigned int x = 0; x < size; x++) {
        for (unsigned int y = 0; y < size; y++) {
            my_put_pixel(framebuffer, position.x + x, position.y + y, color);
        }
    }
}
