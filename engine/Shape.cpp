//
// Created by user on 06-07-2017.
//

#include "Shape.h"

Shape::Shape(vertexArgs va, colArgs ca, texArgs ta, Shader* shad){
    this->shader  = shad;
    this->information = va.inf;
    this->size = va.infSize;
    this->sizeForNextVertex = va.sizeNextVertex;
    this->posForFirstVertex = va.posFirstVertex;
    this->layoutLocationVertex = va.layoutPos;
    this->colored = ca.col;
    this->sizeForNextColor = ca.sizeNextColor;
    this->posForFirstColor = ca.posFirstColor;
    this->layoutLocationColor = ca.layoutColor;
    this->textured = ta.tex;
    this->sizeForNextTex = ta.sizeNextTex;
    this->posForFirstTex = ta.posFirstTex;
    this->layoutLocationTex = ta.layoutText;
    this->textures = ta.text;
}
