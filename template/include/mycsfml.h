/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** The header of the csfml functions
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "my.h"

#ifndef CSFML_H_
    #define CSFML_H_

/* Pixels functions */
typedef struct framebuffer_s {
    sfUint8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width,
    unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
void framebuffer_draw(sfRenderWindow *window,
    framebuffer_t *framebuffer);
void my_put_pixel(framebuffer_t *framebuffer,
    unsigned int x, unsigned int y, sfColor color);
void draw_square(framebuffer_t *framebuffer, sfVector2u position,
    unsigned int size, sfColor color);

/* Images functions */
typedef struct sprite_s {
    char *file;
    sfIntRect *rect;
    sfVector2f *scale;
    sfColor *color;
    float rotation;
    sfVector2f *origin;
} sprite_t;

void image_draw(sfRenderWindow* window, char *file,
    unsigned int width, unsigned int height);
void image_draw_from_rect(sfRenderWindow* window, char *file, sfIntRect *rect);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move_rect_from_start(sfIntRect *rect, int start, int offset,
    int sprite_numbers);
sfSprite *create_sf_sprite(sprite_t *sprite_box, sfTexture *texture,
    sfVector2f position);

/* Text functions */
typedef struct text_s {
    char *text;
    char *font;
    int size;
    float lineSpacing;
    float letterSpacing;
    sfColor color;
    float outlineColor_size;
    sfColor outlineColor;
    float rotation;
    sfUint32 style;
} text_t;

void draw_text(sfRenderWindow* window, text_t *text_box, sfVector2f position);
sfText *create_sf_text(text_t *text_box, sfVector2f position);

/* Music and sound functions */
void play_sound_with_sleep(char *file, float volume);

/* Shape functions */
typedef struct circle_shape_s {
    sfVector2f *origin;
    sfVector2f *scale;
    sfColor *fill_color;
    sfColor *outline_color;
    float outline_thickness;
    float radius;
    float rotation;
} circle_shape_t;

typedef struct rectangle_shape_s {
    sfVector2f *origin;
    sfVector2f *scale;
    sfColor *fill_color;
    sfColor *outline_color;
    float outline_thickness;
    sfVector2f *size;
    float rotation;
} rectangle_shape_t;

sfCircleShape *create_circle_shape(circle_shape_t *circle_shape,
    sfVector2f position);
sfRectangleShape *create_rectangle_shape(rectangle_shape_t *rectangle_shape,
    sfVector2f position);
int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2);

/* FPS functions */
void print_framerate(void);
int get_fps(void);

/* Rect functions */
int rect_is_intersecting(sfIntRect rect1, sfIntRect rect2);
int vector_is_intersecting_rect(sfVector2f vector, sfIntRect rect);
int rect_is_intersecting_circle(sfIntRect rect, sfVector2f circle,
    float radius);
int rect_is_in_rect(sfIntRect rect1, sfIntRect rect2);
int vector_is_in_rect(sfVector2f vector, sfIntRect rect);

#endif /* CSFML_H_ */
