#ifndef RECIPE_H
#define RECIPE_H

#include <QString>


struct Recipe
{

public:
    QString recipeName;
    QString rating;
    QString servings;
    QString cookTime;
    QString prepTime;
    QString totalTime;
    QString ingredients;
    QString nutrition;
    QString direction;
};

#endif // RECIPE_H
