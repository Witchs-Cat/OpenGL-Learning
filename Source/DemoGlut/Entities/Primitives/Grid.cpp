#include "Grid.h"

void Grid::Render(RenderEventArgs* args)
{
    glBegin(GL_LINES);
    {
        glColor3f(1,0,0);
        glVertex3f(6,0,0);
        glVertex3f(0, 0, 0);

        glColor3f(0, 1, 0);
        glVertex3f(0, 6, 0);
        glVertex3f(0, 0, 0);

        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 6);
        glVertex3f(0, 0, 0);
    }
    glEnd();
}
