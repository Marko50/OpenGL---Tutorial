//
// Created by user on 06-07-2017.
//

#ifndef GAMEENGINE_TRIANGLE_H
#define GAMEENGINE_TRIANGLE_H

#include "Shape.h"
#include <vector>

class Triangle: public Shape{
private:

public:
    Triangle(bool col, bool tex, float inf[], int infSize, int sizeNextVertex, int posFirstVertex, int sizeNextColor, int posFirstColor, int sizeNextTex, int posFirstTex, int layoutPos, int layoutColor, int layoutText, Shader* shape, std::vector<Texture* >t, std::vector<int>tCount ,std::vector<const char *> uniformName)
            : Shape(col, tex, inf, infSize, sizeNextVertex, posFirstVertex,sizeNextColor, posFirstColor,sizeNextTex,posFirstTex,layoutPos,layoutColor,layoutText, shape, t){
        this->initGLBuffers(tCount, uniformName);
    }
    void initGLBuffers(std::vector<int> textureCount, std::vector<const char *> uniformName);
    void draw();
};

#endif //GAMEENGINE_TRIANGLE_H
