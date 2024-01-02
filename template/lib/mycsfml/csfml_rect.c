/*
** EPITECH PROJECT, 2023
** csfml_rect
** File description:
** All the functions related to rect in CSFML
*/

#include "mycsfml.h"

int rect_is_intersecting(sfIntRect rect1, sfIntRect rect2)
{
    if ((rect1.left < rect2.left + rect2.width &&
    rect1.left + rect1.width > rect2.left) &&
    (rect1.top < rect2.top + rect2.height &&
    rect1.height + rect1.top > rect2.top))
        return 1;
    return 0;
}

/*int vector_is_intersecting_rect(sfVector2f vector, sfIntRect rect)
{
    if ((vector.x >= rect.left && vector.x < rect.left + rect.width) &&
    (vector.y >= rect.top && vector.y < rect.top + rect.height))
        return 1;
    return 0;
}*/
int vector_is_intersecting_rect(sfVector2f vector, sfIntRect rect)
{
    return 0;
}

int rect_is_intersecting_circle(sfIntRect rect, sfVector2f circle,
    float radius)
{
    float max_x = circle.x;
    float max_y = circle.y;
    float distance_x;
    float distance_y;

    if (circle.x <= rect.left)
        max_x = rect.left;
    else if (circle.x >= rect.left + rect.width)
        max_x = rect.left + rect.width;
    if (circle.y <= rect.top)
        max_y = rect.top;
    else if (circle.y >= rect.top + rect.height)
        max_y = rect.top + rect.height;
    distance_x = circle.x - max_x;
    distance_y = circle.y - max_y;
    if (sqrt(distance_x * distance_x + distance_y * distance_y) <= radius)
        return 1;
    return 0;
}

int rect_is_in_rect(sfIntRect rect1, sfIntRect rect2)
{
    if ((rect1.left >= rect2.left && rect1.left + rect1.width <=
    rect2.left + rect2.width &&
    rect1.top >= rect2.top && rect1.top + rect1.height <=
    rect2.top + rect2.height) ||
    (rect1.left <= rect2.left && rect1.left + rect1.width >=
    rect2.left + rect2.width &&
    rect1.top <= rect2.top && rect1.top + rect1.height >=
    rect2.top + rect2.height))
        return 1;
    return 0;
}

int vector_is_in_rect(sfVector2f vector, sfIntRect rect)
{
    if (vector.x >= rect.left && vector.x <= rect.left + rect.width &&
    vector.y >= rect.top && vector.y <= rect.top + rect.height)
        return 1;
    return 0;
}
