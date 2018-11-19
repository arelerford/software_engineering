// Author: Justin Selsor (Sep. 25, 2018)
// For the Milkman Project. Software Enginering.

#include <GL/glx.h>
#include <list>
#include "fonts.h"
#include "Entity.h"
#include "CollisonManager.h"
#include <string.h>

using namespace std;

void Entity::render (void) {

}

void Entity::update (void) {

}

bool Entity::checkCollision (Entity& e) {
    if (x < (e.x + e.width) && (x + width) > e.x && y < (e.y + e.height) &&
        (y + height) > e.y) {
            return true;
    }
    
    return false;
}

// Manageges Physics interactions

// TODO: Modifie to allow for offsets also look at paramters for
//       ggprint8b(Rect, int, int, string) and what they do.
//       ggprint8b(Rect, ,color, string to draw) 
void show_credits_justin(Rect *r)
{
    ggprint16(r, 150, 0, "Justin S.");
}

// TODO: Animate image.
void show_justin_image (int x, int y, GLuint textid)
{
    glColor3f (1.0f, 1.0f, 1.0f);
    
    int wid = 40;

    glPushMatrix();

    glTranslatef(x, y, 0);
    
    glBindTexture(GL_TEXTURE_2D, textid);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex2i (-wid, -wid);
        glTexCoord2f(0.0f, 0.0f); glVertex2i (-wid, wid);
        glTexCoord2f(1.0f, 0.0f); glVertex2i (wid, wid);
        glTexCoord2f(1.0f, 1.0f); glVertex2i (wid, -wid);
    glEnd();

    glPopMatrix();
}

// Converts a pixel positon to a opengl mapping.
float convert_pixel_position (float positon, float res)
{
    return (2 / res) * (positon) - 1;
}

// Converts a gl mapping to a pixel position.
float convert_gl_postion (float positon, float res)
{
    return positon * res;
}
