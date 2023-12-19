/*
** EPITECH PROJECT, 2023
** csfml_shape
** File description:
** All the functions related to shape in CSFML
*/

#include "mycsfml.h"

static void set_circle_shape_settings(circle_shape_t *circle_shape,
    sfCircleShape *circle)
{
    if (circle_shape->origin != NULL)
        sfCircleShape_setOrigin(circle, *circle_shape->origin);
    if (circle_shape->scale != NULL)
        sfCircleShape_setScale(circle, *circle_shape->scale);
    if (circle_shape->fill_color != 0)
        sfCircleShape_setFillColor(circle, *circle_shape->fill_color);
    if (circle_shape->outline_color != 0)
        sfCircleShape_setOutlineColor(circle, *circle_shape->outline_color);
    if (circle_shape->outline_thickness != 0.0)
        sfCircleShape_setOutlineThickness(circle,
            circle_shape->outline_thickness);
    if (circle_shape->rotation != 0.0)
        sfCircleShape_setRotation(circle, circle_shape->rotation);
    if (circle_shape->radius != 0.0)
        sfCircleShape_setRadius(circle, circle_shape->radius);
}

sfCircleShape *create_circle_shape(circle_shape_t *circle_shape,
    sfVector2f position)
{
    sfCircleShape *circle = sfCircleShape_create();

    set_circle_shape_settings(circle_shape, circle);
    sfCircleShape_setPosition(circle, position);
    return circle;
}

static void set_rectangle_shape_settings(rectangle_shape_t *rectangle_shape,
    sfRectangleShape *rectangle)
{
    if (rectangle_shape->origin != NULL)
        sfRectangleShape_setOrigin(rectangle, *rectangle_shape->origin);
    if (rectangle_shape->scale != NULL)
        sfRectangleShape_setScale(rectangle, *rectangle_shape->scale);
    if (rectangle_shape->fill_color != 0)
        sfRectangleShape_setFillColor(rectangle,
            *rectangle_shape->fill_color);
    if (rectangle_shape->outline_color != 0)
        sfRectangleShape_setOutlineColor(rectangle,
            *rectangle_shape->outline_color);
    if (rectangle_shape->outline_thickness != 0.0)
        sfRectangleShape_setOutlineThickness(rectangle,
            rectangle_shape->outline_thickness);
    if (rectangle_shape->rotation != 0.0)
        sfRectangleShape_setRotation(rectangle, rectangle_shape->rotation);
    if (rectangle_shape->size != NULL)
        sfRectangleShape_setSize(rectangle, *rectangle_shape->size);
}

sfRectangleShape *create_rectangle_shape(rectangle_shape_t *rectangle_shape,
    sfVector2f position)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    set_rectangle_shape_settings(rectangle_shape, rectangle);
    sfRectangleShape_setPosition(rectangle, position);
    return rectangle;
}

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f c1_position = sfCircleShape_getPosition(c1);
    sfVector2f c2_position = sfCircleShape_getPosition(c2);
    float c1_radius = sfCircleShape_getRadius(c1);
    float c2_radius = sfCircleShape_getRadius(c2);

    if ((my_compute_power_rec((int)c2_position.x - (int)c1_position.x, 2) +
    my_compute_power_rec((int)c2_position.y - (int)c1_position.y, 2))
    <= my_compute_power_rec((int)c1_radius + (int)c2_radius, 2))
        return 1;
    return 0;
}
