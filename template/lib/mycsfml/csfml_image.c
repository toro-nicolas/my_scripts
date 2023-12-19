/*
** EPITECH PROJECT, 2023
** csfml_image
** File description:
** All the functions related to images in CSFML
*/

#include "mycsfml.h"

void image_draw(sfRenderWindow* window, char *file,
    unsigned int width, unsigned int height)
{
    sfTexture *texture = sfTexture_create(width, height);
    sfSprite *sprite = sfSprite_create();
    sfImage *image;

    if (open(file, O_RDONLY) != -1) {
        image = sfImage_createFromFile(file);
        if (texture != NULL) {
            sfSprite_setTexture(sprite, texture, sfFalse);
            sfTexture_updateFromImage(texture, image, 0, 0);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        sfImage_destroy(image);
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void image_draw_from_rect(sfRenderWindow* window, char *file, sfIntRect* rect)
{
    sfTexture *texture;
    sfSprite *sprite = sfSprite_create();

    if (open(file, O_RDONLY) != -1) {
        texture = sfTexture_createFromFile(file, rect);
        if (texture != NULL) {
            sfSprite_setTexture(sprite, texture, sfFalse);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        sfTexture_destroy(texture);
    }
    sfSprite_destroy(sprite);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value) {
        rect->left = 0;
    } else {
        rect->left = rect->left + offset;
    }
}

void move_rect_from_start(sfIntRect *rect, int start, int offset,
    int sprite_numbers)
{
    if (rect->left + offset >= offset * sprite_numbers) {
        rect->left = start;
    } else {
        rect->left = rect->left + offset;
    }
}

static void set_sprite_settings(sprite_t *sprite_box, sfSprite *sprite)
{
    if (sprite_box->rect != NULL)
        sfSprite_setTextureRect(sprite, *sprite_box->rect);
    if (sprite_box->scale != NULL)
        sfSprite_setScale(sprite, *sprite_box->scale);
    if (sprite_box->color != NULL)
        sfSprite_setColor(sprite, *sprite_box->color);
    if (sprite_box->rotation != 0.0)
        sfSprite_setRotation(sprite, sprite_box->rotation);
    if (sprite_box->origin != NULL)
        sfSprite_setOrigin(sprite, *sprite_box->origin);
}

sfSprite *create_sf_sprite(sprite_t *sprite_box, sfTexture *texture,
    sfVector2f position)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *new_texture;

    if (sprite_box->file != NULL) {
        new_texture = sfTexture_createFromFile(sprite_box->file, NULL);
        sfSprite_setTexture(sprite, new_texture, sfFalse);
    }
    if (texture != NULL)
        sfSprite_setTexture(sprite, texture, sfFalse);
    set_sprite_settings(sprite_box, sprite);
    sfSprite_setPosition(sprite, position);
    return sprite;
}
