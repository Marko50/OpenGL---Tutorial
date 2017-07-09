//
// Created by user on 06-07-2017.
//

#include "Shape.h"

Shape::Shape(bool col, bool tex, float inf[], int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor, int sizeNextTex, int posFirstTex, int layoutPos, int layoutColor, int layoutText, Shader* shape){
    this->shader  = shape;
    this->information = inf;
    this->size = infSize;
    this->sizeForNextVertex = sizeNextVertex;
    this->posForFirstVertex = posFirstVertex;
    this->layoutLocationVertex = layoutPos;
    this->colored = col;
    this->textured = tex;
    this->sizeForNextColor = sizeNextColor;
    this->posForFirstColor = posFirstColor;
    this->layoutLocationColor = layoutColor;
    this->sizeForNextTex = sizeNextTex;
    this->posForFirstTex = posFirstTex;
    this->layoutLocationTex = layoutText;
}
