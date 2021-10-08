//
// COMP 371 Assignment1
// Matthew Gee 
// Team 13 (except everybody else dropped or went AWOL so it was literally just me.
// 


/*Controls:
A: move camera left
S: move camera down
D: move camera right
W: move camera up
K: move camera back
I: move camera forward
X: move camera to original
U: upscale
J: downscale

1-5: choose which object to rotate/move
Left: move object left
Right: move object right
Up: move object up
Down:  move object down
Comma: move object toward
Period: move object away
8/9/0: choose render mode of objects

R: rotate around x axis
T: rotate around y axis
*/

#include <iostream>
#include <list>

#define GLEW_STATIC 1   // This allows linking with Static Library on Windows, without DLL
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler

#include <GLFW/glfw3.h> // cross-platform interface for creating a graphical context,
// initializing OpenGL and binding inputs

#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp> // include this to create transformation matrices
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp> 

//#include "draw.h"

using namespace glm;
using namespace std;

int currentObject = 1;
int currentLetter = 1;

GLuint worldMatrixLocation;
GLenum mode = GL_TRIANGLES;

float x_location = 0;
float y_location = 3;
float z_location = 0;

float x1_location = 0;
float y1_location = 3;
float z1_location = 0;

float x2_location = 0;
float y2_location = 3;
float z2_location = 0;

float x3_location = 0;
float y3_location = 3;
float z3_location = 0;

float x4_location = 0;
float y4_location = 3;
float z4_location = 0;

float x5_location = 0;
float y5_location = 3;
float z5_location = 0;

float upscale = 1;
float x_rotate = 0;
float y_rotate = 0;
float x1_rotate = 0;
float y1_rotate = 0;
float x2_rotate = 0;
float y2_rotate = 0;
float x3_rotate = 0;
float y3_rotate = 0;
float x4_rotate = 0;
float y4_rotate = 0;
float x5_rotate = 0;
float y5_rotate = 0;

float spinningCubeAngle = 0.0f;
float mainCubeAngle = 0.0f;
float smallCubeAngle = 0.0f;
float smallerCubeAngle = 0.0f;

vec3 originalPosition;

mat4 cube1Matrix;
mat4 cube1Matrix1;
mat4 cube1Matrix2;
mat4 cube1Matrix3;
mat4 cube1Matrix4;
mat4 cube1Matrix5;
mat4 cube1Matrix6;
mat4 cube1Matrix7;
mat4 cube1Matrix8;
mat4 cube1Matrix9;
mat4 cube1Matrix10;
mat4 cube1Matrix11;
mat4 cube1Matrix12;
mat4 cube1Matrix13;
mat4 cube1Matrix14;
mat4 cube1Matrix15;
mat4 cube1Matrix16;
mat4 cube1Matrix17;
mat4 cube1Matrix18;
mat4 cube1Matrix19;
mat4 cube1Matrix20;
mat4 cube1Matrix21;
mat4 cube1Matrix22;
mat4 cube1Matrix23;
mat4 cube1Matrix24;
mat4 cube1Matrix25;
mat4 cube1Matrix26;
mat4 cube1Matrix27;
mat4 cube1Matrix28;
mat4 cube1Matrix29;
mat4 cube1Matrix30;
mat4 cube1Matrix31;
mat4 cube1Matrix32;
mat4 cube1Matrix33;
mat4 cube1Matrix34;
mat4 cube1Matrix35;
mat4 cube1Matrix36;
mat4 cube1Matrix37;
mat4 cube1Matrix38;
mat4 cube1Matrix39;
mat4 cube1Matrix40;
mat4 cube1Matrix41;
mat4 cube1Matrix42;
mat4 cube1Matrix43;
mat4 cube1Matrix44;
mat4 cube1Matrix45;
mat4 cube1Matrix46;
mat4 cube1Matrix47;
mat4 cube1Matrix48;
mat4 cube1Matrix49;

mat4 cube2Matrix;
mat4 cube2Matrix1;
mat4 cube2Matrix2;
mat4 cube2Matrix3;
mat4 cube2Matrix4;
mat4 cube2Matrix5;
mat4 cube2Matrix6;
mat4 cube2Matrix7;
mat4 cube2Matrix8;
mat4 cube2Matrix9;
mat4 cube2Matrix10;
mat4 cube2Matrix11;
mat4 cube2Matrix12;
mat4 cube2Matrix13;
mat4 cube2Matrix14;
mat4 cube2Matrix15;
mat4 cube2Matrix16;
mat4 cube2Matrix17;
mat4 cube2Matrix18;
mat4 cube2Matrix19;
mat4 cube2Matrix20;
mat4 cube2Matrix21;
mat4 cube2Matrix22;
mat4 cube2Matrix23;
mat4 cube2Matrix24;
mat4 cube2Matrix25;
mat4 cube2Matrix26;
mat4 cube2Matrix27;
mat4 cube2Matrix28;
mat4 cube2Matrix29;
mat4 cube2Matrix30;
mat4 cube2Matrix31;
mat4 cube2Matrix32;
mat4 cube2Matrix33;
mat4 cube2Matrix34;
mat4 cube2Matrix35;
mat4 cube2Matrix36;
mat4 cube2Matrix37;
mat4 cube2Matrix38;
mat4 cube2Matrix39;
mat4 cube2Matrix40;
mat4 cube2Matrix41;
mat4 cube2Matrix42;
mat4 cube2Matrix43;
mat4 cube2Matrix44;
mat4 cube2Matrix45;
mat4 cube2Matrix46;
mat4 cube2Matrix47;
mat4 cube2Matrix48;
mat4 cube2Matrix49;

mat4 cube3Matrix;
mat4 cube3Matrix1;
mat4 cube3Matrix2;
mat4 cube3Matrix3;
mat4 cube3Matrix4;
mat4 cube3Matrix5;
mat4 cube3Matrix6;
mat4 cube3Matrix7;
mat4 cube3Matrix8;
mat4 cube3Matrix9;
mat4 cube3Matrix10;
mat4 cube3Matrix11;
mat4 cube3Matrix12;
mat4 cube3Matrix13;
mat4 cube3Matrix14;
mat4 cube3Matrix15;
mat4 cube3Matrix16;
mat4 cube3Matrix17;
mat4 cube3Matrix18;
mat4 cube3Matrix19;
mat4 cube3Matrix20;
mat4 cube3Matrix21;
mat4 cube3Matrix22;
mat4 cube3Matrix23;
mat4 cube3Matrix24;
mat4 cube3Matrix25;
mat4 cube3Matrix26;
mat4 cube3Matrix27;
mat4 cube3Matrix28;
mat4 cube3Matrix29;
mat4 cube3Matrix30;
mat4 cube3Matrix31;
mat4 cube3Matrix32;
mat4 cube3Matrix33;
mat4 cube3Matrix34;
mat4 cube3Matrix35;
mat4 cube3Matrix36;
mat4 cube3Matrix37;
mat4 cube3Matrix38;
mat4 cube3Matrix39;
mat4 cube3Matrix40;
mat4 cube3Matrix41;
mat4 cube3Matrix42;
mat4 cube3Matrix43;
mat4 cube3Matrix44;
mat4 cube3Matrix45;
mat4 cube3Matrix46;
mat4 cube3Matrix47;
mat4 cube3Matrix48;
mat4 cube3Matrix49;

mat4 cube4Matrix;
mat4 cube4Matrix1;
mat4 cube4Matrix2;
mat4 cube4Matrix3;
mat4 cube4Matrix4;
mat4 cube4Matrix5;
mat4 cube4Matrix6;
mat4 cube4Matrix7;
mat4 cube4Matrix8;
mat4 cube4Matrix9;
mat4 cube4Matrix10;
mat4 cube4Matrix11;
mat4 cube4Matrix12;
mat4 cube4Matrix13;
mat4 cube4Matrix14;
mat4 cube4Matrix15;
mat4 cube4Matrix16;
mat4 cube4Matrix17;
mat4 cube4Matrix18;
mat4 cube4Matrix19;
mat4 cube4Matrix20;
mat4 cube4Matrix21;
mat4 cube4Matrix22;
mat4 cube4Matrix23;
mat4 cube4Matrix24;
mat4 cube4Matrix25;
mat4 cube4Matrix26;
mat4 cube4Matrix27;
mat4 cube4Matrix28;
mat4 cube4Matrix29;
mat4 cube4Matrix30;
mat4 cube4Matrix31;
mat4 cube4Matrix32;
mat4 cube4Matrix33;
mat4 cube4Matrix34;
mat4 cube4Matrix35;
mat4 cube4Matrix36;
mat4 cube4Matrix37;
mat4 cube4Matrix38;
mat4 cube4Matrix39;
mat4 cube4Matrix40;
mat4 cube4Matrix41;
mat4 cube4Matrix42;
mat4 cube4Matrix43;
mat4 cube4Matrix44;
mat4 cube4Matrix45;
mat4 cube4Matrix46;
mat4 cube4Matrix47;
mat4 cube4Matrix48;
mat4 cube4Matrix49;

mat4 cube5Matrix;
mat4 cube5Matrix1;
mat4 cube5Matrix2;
mat4 cube5Matrix3;
mat4 cube5Matrix4;
mat4 cube5Matrix5;
mat4 cube5Matrix6;
mat4 cube5Matrix7;
mat4 cube5Matrix8;
mat4 cube5Matrix9;
mat4 cube5Matrix10;
mat4 cube5Matrix11;
mat4 cube5Matrix12;
mat4 cube5Matrix13;
mat4 cube5Matrix14;
mat4 cube5Matrix15;
mat4 cube5Matrix16;
mat4 cube5Matrix17;
mat4 cube5Matrix18;
mat4 cube5Matrix19;
mat4 cube5Matrix20;
mat4 cube5Matrix21;
mat4 cube5Matrix22;
mat4 cube5Matrix23;
mat4 cube5Matrix24;
mat4 cube5Matrix25;
mat4 cube5Matrix26;
mat4 cube5Matrix27;
mat4 cube5Matrix28;
mat4 cube5Matrix29;
mat4 cube5Matrix30;
mat4 cube5Matrix31;
mat4 cube5Matrix32;
mat4 cube5Matrix33;
mat4 cube5Matrix34;
mat4 cube5Matrix35;
mat4 cube5Matrix36;
mat4 cube5Matrix37;
mat4 cube5Matrix38;
mat4 cube5Matrix39;
mat4 cube5Matrix40;
mat4 cube5Matrix41;
mat4 cube5Matrix42;
mat4 cube5Matrix43;
mat4 cube5Matrix44;
mat4 cube5Matrix45;
mat4 cube5Matrix46;
mat4 cube5Matrix47;
mat4 cube5Matrix48;
mat4 cube5Matrix49;

mat4 letter5Matrix;
mat4 letter5Matrix1;
mat4 letter5Matrix2;
mat4 letter5Matrix3;
mat4 letter5Matrix4;
mat4 letter5Matrix5;
mat4 letter5Matrix6;
mat4 letter5Matrix7;
mat4 letter5Matrix8;
mat4 letter5Matrix9;
mat4 letter5Matrix10;
mat4 letter5Matrix11;
mat4 letter5Matrix12;
mat4 letter5Matrix13;
mat4 letter5Matrix14;
mat4 letter5Matrix15;
mat4 letter5Matrix16;
mat4 letter5Matrix17;
mat4 letter5Matrix18;

mat4 letter2Matrix;
mat4 letter2Matrix1;
mat4 letter2Matrix2;
mat4 letter2Matrix3;
mat4 letter2Matrix4;
mat4 letter2Matrix5;
mat4 letter2Matrix6;
mat4 letter2Matrix7;
mat4 letter2Matrix8;
mat4 letter2Matrix9;
mat4 letter2Matrix10;
mat4 letter2Matrix11;
mat4 letter2Matrix12;
mat4 letter2Matrix13;
mat4 letter2Matrix14;
mat4 letter2Matrix15;
mat4 letter2Matrix16;
mat4 letter2Matrix17;
mat4 letter2Matrix18;

mat4 letter3Matrix;
mat4 letter3Matrix1;
mat4 letter3Matrix2;
mat4 letter3Matrix3;
mat4 letter3Matrix4;
mat4 letter3Matrix5;
mat4 letter3Matrix6;
mat4 letter3Matrix7;
mat4 letter3Matrix8;
mat4 letter3Matrix9;
mat4 letter3Matrix10;
mat4 letter3Matrix11;
mat4 letter3Matrix12;
mat4 letter3Matrix13;
mat4 letter3Matrix14;
mat4 letter3Matrix15;
mat4 letter3Matrix16;
mat4 letter3Matrix17;
mat4 letter3Matrix18;

mat4 letter4Matrix;
mat4 letter4Matrix1;
mat4 letter4Matrix2;
mat4 letter4Matrix3;
mat4 letter4Matrix4;
mat4 letter4Matrix5;
mat4 letter4Matrix6;
mat4 letter4Matrix7;
mat4 letter4Matrix8;
mat4 letter4Matrix9;
mat4 letter4Matrix10;
mat4 letter4Matrix11;
mat4 letter4Matrix12;
mat4 letter4Matrix13;
mat4 letter4Matrix14;
mat4 letter4Matrix15;
mat4 letter4Matrix16;
mat4 letter4Matrix17;
mat4 letter4Matrix18;

mat4 letter1Matrix;
mat4 letter1Matrix1;
mat4 letter1Matrix2;
mat4 letter1Matrix3;
mat4 letter1Matrix4;
mat4 letter1Matrix5;
mat4 letter1Matrix6;
mat4 letter1Matrix7;
mat4 letter1Matrix8;
mat4 letter1Matrix9;
mat4 letter1Matrix10;
mat4 letter1Matrix11;
mat4 letter1Matrix12;
mat4 letter1Matrix13;
mat4 letter1Matrix14;
mat4 letter1Matrix15;
mat4 letter1Matrix16;
mat4 letter1Matrix17;
mat4 letter1Matrix18;


void drawArrow() {
	mat4 axisMatrix = translate(mat4(1.0f), vec3(0.0f, 5.0f, 0.0f)) * scale(mat4(1.0f), vec3(1.0f, 1.0f, 1.0f));
	glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &axisMatrix[0][0]);
	glDrawArrays(GL_LINES, 0, 4);
};

void drawLetter(int x) {
	letter1Matrix1 = translate(mat4(1.0f), vec3(x1_location + 1 -20, y1_location + 1, z1_location));
	letter2Matrix1 = translate(mat4(1.0f), vec3(x2_location + 1 - 10, y2_location + 1, z2_location));
	letter3Matrix1 = translate(mat4(1.0f), vec3(x3_location + 1, y3_location + 1, z3_location));
	letter4Matrix1 = translate(mat4(1.0f), vec3(x4_location + 1 + 10, y4_location + 1, z4_location));
	letter5Matrix1 = translate(mat4(1.0f), vec3(x5_location + 1 + 20, y5_location + 1, z5_location));


		letter1Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter1Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter1Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter1Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter1Matrix6 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter1Matrix7 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter1Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter1Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter1Matrix10 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter1Matrix11 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter1Matrix12 = translate(mat4(1.0f), vec3(1.0f, -1.0f, 0.0f));
		letter1Matrix13 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		letter1Matrix14 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter1Matrix15 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter1Matrix16 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter1Matrix17 = translate(mat4(0.0f), vec3(1.0f, 0.0f, 0.0f));
		letter1Matrix18 = translate(mat4(0.0f), vec3(0.0f, 1.0f, 0.0f));
		letter1Matrix = letter1Matrix1 * rotate(mat4(1.0f), x1_rotate, vec3(1.0f, 0.0f, 0.0f));
		letter1Matrix = letter1Matrix * rotate(mat4(1.0f), y1_rotate, vec3(0.0f, 1.0f, 0.0f));
		letter1Matrix = letter1Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter1Matrix = letter1Matrix * letter1Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0

		letter2Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter2Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter2Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter2Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter2Matrix6 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix7 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix10 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter2Matrix11 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter2Matrix12 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter2Matrix13 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter2Matrix14 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter2Matrix15 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix16 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix17 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix18 = translate(mat4(0.0f), vec3(0.0f, 1.0f, 0.0f));
		letter2Matrix = letter2Matrix1 * rotate(mat4(1.0f), x2_rotate, vec3(1.0f, 0.0f, 0.0f));
		letter2Matrix = letter2Matrix * rotate(mat4(1.0f), y2_rotate, vec3(0.0f, 1.0f, 0.0f));
		letter2Matrix = letter2Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter2Matrix = letter2Matrix * letter2Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0

		letter3Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter3Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter3Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter3Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter3Matrix6 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix7 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix10 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter3Matrix11 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter3Matrix12 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter3Matrix13 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter3Matrix14 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter3Matrix15 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix16 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix17 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix18 = translate(mat4(0.0f), vec3(0.0f, 1.0f, 0.0f));
		letter3Matrix = letter3Matrix1 * rotate(mat4(1.0f), x3_rotate, vec3(1.0f, 0.0f, 0.0f));
		letter3Matrix = letter3Matrix * rotate(mat4(1.0f), y3_rotate, vec3(0.0f, 1.0f, 0.0f));
		letter3Matrix = letter3Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter3Matrix = letter3Matrix * letter3Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0

		letter4Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter4Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter4Matrix4 = translate(mat4(1.0f), vec3(0.0f, 2.0f, 0.0f));
		letter4Matrix5 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix6 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix7 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix9 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		letter4Matrix10 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		letter4Matrix11 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter4Matrix12 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter4Matrix13 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter4Matrix14 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter4Matrix15 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix16 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix17 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix18 = translate(mat4(0.0f), vec3(0.0f, 1.0f, 0.0f));
		letter4Matrix = letter4Matrix1 * rotate(mat4(1.0f), x4_rotate, vec3(1.0f, 0.0f, 0.0f));
		letter4Matrix = letter4Matrix * rotate(mat4(1.0f), y4_rotate, vec3(0.0f, 1.0f, 0.0f));
		letter4Matrix = letter4Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter4Matrix = letter4Matrix * letter4Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0

		letter5Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter5Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter5Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter5Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter5Matrix6 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix7 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix10 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter5Matrix11 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter5Matrix12 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter5Matrix13 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		letter5Matrix14 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		letter5Matrix15 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix16 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix17 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix18 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		letter5Matrix = letter5Matrix1 * rotate(mat4(1.0f), x5_rotate, vec3(1.0f, 0.0f, 0.0f));
		letter5Matrix = letter5Matrix * rotate(mat4(1.0f), y5_rotate, vec3(0.0f, 1.0f, 0.0f));
		letter5Matrix = letter5Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		letter5Matrix = letter5Matrix * letter5Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &letter5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0

	

}



void drawShape(int x) {

		cube1Matrix1 = translate(mat4(1.0f), vec3(-20, 3, -2));


		cube1Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix6 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix7 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));

		cube1Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix10 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix11 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix12 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix13 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));

		cube1Matrix14 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix15 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix16 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix17 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix18 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix19 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));

		cube1Matrix20 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube1Matrix21 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube1Matrix22 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube1Matrix23 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube1Matrix24 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube1Matrix25 = translate(mat4(1.0f), vec3(1.0f, 2.0f, 0.0f));
		cube1Matrix26 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix27 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix28 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix29 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix30 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube1Matrix31 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix32 = translate(mat4(1.0f), vec3(0.0f, 2.0f, 0.0f));
		cube1Matrix33 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix34 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix35 = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));

		cube1Matrix36 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix37 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix38 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix39 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix40 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix41 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix42 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix43 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix44 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix45 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix46 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix47 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix48 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube1Matrix49 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));

		cube1Matrix = cube1Matrix1 * rotate(mat4(1.0f), x_rotate, vec3(1.0f, 0.0f, 0.0f));
		cube1Matrix = cube1Matrix * rotate(mat4(1.0f), y_rotate, vec3(0.0f, 1.0f, 0.0f));
		cube1Matrix = cube1Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix19;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix20;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix21;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix22;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix23;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix24;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix25;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix26;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix27;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix28;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix29;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix30;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix31;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix32;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix33;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix34;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix35;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix36;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix37;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix38;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix39;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix40;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix41;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix42;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix43;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix44;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix45;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix46;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix47;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix48;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube1Matrix = cube1Matrix * cube1Matrix49;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube1Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0


		cube2Matrix1 = translate(mat4(1.0f), vec3(-10, 3, -2));

		cube2Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube2Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube2Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube2Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube2Matrix6 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube2Matrix7 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));

		cube2Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix10 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix11 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix12 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix13 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));

		cube2Matrix14 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube2Matrix15 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube2Matrix16 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube2Matrix17 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube2Matrix18 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube2Matrix19 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));

		cube2Matrix20 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube2Matrix21 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube2Matrix22 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube2Matrix23 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube2Matrix24 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube2Matrix25 = translate(mat4(1.0f), vec3(1.0f, 2.0f, 0.0f));
		cube2Matrix26 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix27 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix28 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix29 = translate(mat4(1.0f), vec3(0.0f, 2.0f, 0.0f));
		cube2Matrix30 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube2Matrix31 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube2Matrix32 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube2Matrix33 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix34 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix35 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix36 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix37 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix38 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix39 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix40 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix41 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix42 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix43 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix44 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix45 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix46 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix47 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix48 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube2Matrix49 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));

		cube2Matrix = cube2Matrix1 * rotate(mat4(1.0f), x_rotate, vec3(1.0f, 0.0f, 0.0f));
		cube2Matrix = cube2Matrix * rotate(mat4(1.0f), y_rotate, vec3(0.0f, 1.0f, 0.0f));
		cube2Matrix = cube2Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix19;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix20;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix21;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix22;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix23;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix24;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix25;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix26;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix27;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix28;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix29;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix30;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix31;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix32;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix33;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix34;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix35;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix36;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix37;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix38;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix39;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix40;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix41;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix42;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix43;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix44;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix45;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix46;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix47;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix48;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube2Matrix = cube2Matrix * cube2Matrix49;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube2Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0



		cube3Matrix1 = translate(mat4(1.0f), vec3(0, 3, -2));
		cube3Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube3Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube3Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube3Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube3Matrix6 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube3Matrix7 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));

		cube3Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix10 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix11 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix12 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix13 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));

		cube3Matrix14 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube3Matrix15 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube3Matrix16 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube3Matrix17 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube3Matrix18 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube3Matrix19 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));

		cube3Matrix20 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube3Matrix21 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube3Matrix22 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube3Matrix23 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube3Matrix24 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube3Matrix25 = translate(mat4(1.0f), vec3(1.0f, 2.0f, 0.0f));
		cube3Matrix26 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix27 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix28 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix29 = translate(mat4(1.0f), vec3(0.0f, 2.0f, 0.0f));
		cube3Matrix30 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube3Matrix31 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube3Matrix32 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube3Matrix33 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix34 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix35 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix36 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix37 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix38 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix39 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix40 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix41 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix42 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix43 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix44 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix45 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix46 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix47 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix48 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube3Matrix49 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));

		cube3Matrix = cube3Matrix1 * rotate(mat4(1.0f), x_rotate, vec3(1.0f, 0.0f, 0.0f));
		cube3Matrix = cube3Matrix * rotate(mat4(1.0f), y_rotate, vec3(0.0f, 1.0f, 0.0f));
		cube3Matrix = cube3Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix19;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix20;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix21;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix22;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix23;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix24;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix25;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix26;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix27;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix28;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix29;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix30;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix31;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix32;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix33;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix34;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix35;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix36;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix37;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix38;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix39;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix40;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix41;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix42;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix43;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix44;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix45;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix46;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix47;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix48;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube3Matrix = cube3Matrix * cube3Matrix49;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube3Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0


		cube4Matrix1 = translate(mat4(1.0f), vec3(10, 3, -2));
		cube4Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube4Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube4Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube4Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube4Matrix6 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube4Matrix7 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));

		cube4Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix10 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix11 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix12 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix13 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));

		cube4Matrix14 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube4Matrix15 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube4Matrix16 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube4Matrix17 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube4Matrix18 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube4Matrix19 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));

		cube4Matrix20 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube4Matrix21 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube4Matrix22 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube4Matrix23 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube4Matrix24 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube4Matrix25 = translate(mat4(1.0f), vec3(0.0f, 4.0f, 0.0f));
		cube4Matrix26 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix27 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix28 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix29 = translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));
		cube4Matrix30 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube4Matrix31 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube4Matrix32 = translate(mat4(1.0f), vec3(3.0f, 0.0f, 0.0f));

		cube4Matrix33 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix34 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix35 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix36 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix37 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix38 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix39 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix40 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix41 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix42 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix43 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix44 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix45 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix46 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix47 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix48 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube4Matrix49 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));

		cube4Matrix = cube4Matrix1 * rotate(mat4(1.0f), x_rotate, vec3(1.0f, 0.0f, 0.0f));
		cube4Matrix = cube4Matrix * rotate(mat4(1.0f), y_rotate, vec3(0.0f, 1.0f, 0.0f));
		cube4Matrix = cube4Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix19;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix20;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix21;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix22;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix23;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix24;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix25;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix26;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix27;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix28;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix29;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix30;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix31;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix32;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix33;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix34;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix35;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix36;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix37;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix38;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix39;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix40;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix41;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix42;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix43;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix44;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix45;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix46;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix47;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix48;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube4Matrix = cube4Matrix * cube4Matrix49;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube4Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0


		cube5Matrix1 = translate(mat4(1.0f), vec3(20, 3, -2));
		cube5Matrix2 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube5Matrix3 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube5Matrix4 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube5Matrix5 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube5Matrix6 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));
		cube5Matrix7 = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f));

		cube5Matrix8 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix9 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix10 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix11 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix12 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix13 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));

		cube5Matrix14 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube5Matrix15 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube5Matrix16 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube5Matrix17 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube5Matrix18 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));
		cube5Matrix19 = translate(mat4(1.0f), vec3(0.0f, -1.0f, 0.0f));

		cube5Matrix20 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube5Matrix21 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube5Matrix22 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube5Matrix23 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube5Matrix24 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube5Matrix25 = translate(mat4(1.0f), vec3(1.0f, 2.0f, 0.0f));
		cube5Matrix26 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix27 = translate(mat4(1.0f), vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix28 = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix29 = translate(mat4(1.0f), vec3(1.0f, 2.0f, 0.0f));
		cube5Matrix30 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube5Matrix31 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));
		cube5Matrix32 = translate(mat4(1.0f), vec3(-1.0f, 0.0f, 0.0f));

		cube5Matrix33 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix34 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix35 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix36 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix37 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix38 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix39 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix40 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix41 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix42 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix43 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix44 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix45 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix46 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix47 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix48 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));
		cube5Matrix49 = translate(mat4(0.0f), vec3(0.0f, 0.0f, 0.0f));

		cube5Matrix = cube5Matrix1 * rotate(mat4(1.0f), x_rotate, vec3(1.0f, 0.0f, 0.0f));
		cube5Matrix = cube5Matrix * rotate(mat4(1.0f), y_rotate, vec3(0.0f, 1.0f, 0.0f));
		cube5Matrix = cube5Matrix * scale(mat4(1.0f), vec3(upscale, upscale, upscale));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix2;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix3;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix4;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix5;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix6;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix7;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix8;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix9;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix10;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix11;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix12;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix13;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix14;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix15;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix16;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix17;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix18;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix19;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix20;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix21;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix22;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix23;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix24;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix25;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix26;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix27;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix28;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix29;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix30;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix31;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix32;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix33;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix34;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix35;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix36;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix37;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix38;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix39;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix40;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix41;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix42;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix43;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix44;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix45;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix46;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix47;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix48;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
		cube5Matrix = cube5Matrix * cube5Matrix49;
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &cube5Matrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0
	


}




const char* getVertexShaderSource()
{
	// For now, you use a string for your shader code, in the assignment, shaders will be stored in .glsl files
	return
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;"
		"layout (location = 1) in vec3 aColor;"
		""
		"uniform mat4 worldMatrix;"
		"uniform mat4 viewMatrix = mat4(1.0);"  // default value for view matrix (identity)
		"uniform mat4 projectionMatrix = mat4(1.0);"
		""
		"out vec3 vertexColor;"
		"void main()"
		"{"
		"   vertexColor = aColor;"
		"   mat4 modelViewProjection = projectionMatrix * viewMatrix * worldMatrix;"
		"   gl_Position = modelViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0);"
		"}";
}


const char* getFragmentShaderSource()
{
	return
		"#version 330 core\n"
		"in vec3 vertexColor;"
		"out vec4 FragColor;"
		"void main()"
		"{"
		"   if(gl_FrontFacing)"
				"FragColor = vec4(vertexColor, 1.0f);"
		"	else"
		"		FragColor = vec4(0.529f, 0.808f, 0.922f, 1.0f);"
		"}";
}

int compileAndLinkShaders()
{
	// compile and link shader program
	// return shader program id

	// vertex shader
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShaderSource = getVertexShaderSource();
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShaderSource = getFragmentShaderSource();
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

int createLineBufferObject() {
	vec3 start = vec3(0.0f, 0.0f, 0.0f);
	vec3 end = vec3(5.0f, 5.0f, 5.0f);
	vec3 vertices[] = {
		vec3(0.0f,0.0f,0.0f), vec3(1.0f,1.0f,1.0f),
		vec3(0.0f,0.0f,0.0f), vec3(1.0f,1.0f,1.0f),
	};

	// Create a vertex array
	GLuint vertexArrayObject;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	// Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
	GLuint vertexBufferObject;
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		2 * sizeof(vec3), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		2 * sizeof(vec3),
		(void*)sizeof(vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);

	return vertexArrayObject;
}

int createVertexBufferObject()
{
	// single cube
	vec3 vertexArray[] = {  // position,                            color
		vec3(-0.5f,-0.5f,-0.5f), vec3(1.0f, 0.30f, 0.0f), //left - red
		vec3(-0.5f,-0.5f, 0.5f), vec3(1.0f, 0.30f, 0.0f),
		vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.30f, 0.0f),

		vec3(-0.5f,-0.5f,-0.5f), vec3(1.0f, 0.40f, 0.0f),
		vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.40f, 0.0f),
		vec3(-0.5f, 0.5f,-0.5f), vec3(1.0f, 0.40f, 0.0f),

		vec3(0.5f, 0.5f,-0.5f), vec3(0.40f, 0.320f, 1.0f), // far - blue
		vec3(-0.5f,-0.5f,-0.5f), vec3(0.40f, 0.320f, 1.0f),
		vec3(-0.5f, 0.5f,-0.5f), vec3(0.40f, 0.320f, 1.0f),

		vec3(0.5f, 0.5f,-0.5f), vec3(0.40f, 0.20f, 1.0f),
		vec3(0.5f,-0.5f,-0.5f), vec3(0.40f, 0.20f, 1.0f),
		vec3(-0.5f,-0.5f,-0.5f), vec3(0.40f, 0.20f, 1.0f),

		vec3(0.5f,-0.5f, 0.5f), vec3(0.10f, .70f, 0.64350f), // bottom - green
		vec3(-0.5f,-0.5f,-0.5f), vec3(0.10f, .70f, 0.64350f),
		vec3(0.5f,-0.5f,-0.5f), vec3(0.10f, .70f, 0.64350f),

		vec3(0.5f,-0.5f, 0.5f), vec3(0.0f, .70f, 0.350f),
		vec3(-0.5f,-0.5f, 0.5f), vec3(0.0f, .70f, 0.350f),
		vec3(-0.5f,-0.5f,-0.5f), vec3(0.0f, .70f, 0.350f),

		vec3(-0.5f, 0.5f, 0.5f), vec3(0.40f, 0.320f, 1.0f), // near - blue
		vec3(-0.5f,-0.5f, 0.5f), vec3(0.40f, 0.320f, 1.0f),
		vec3(0.5f,-0.5f, 0.5f), vec3(0.40f, 0.320f, 1.0f),

		vec3(0.5f, 0.5f, 0.5f), vec3(0.40f, 0.20f, 1.0f),
		vec3(-0.5f, 0.5f, 0.5f), vec3(0.40f, 0.20f, 1.0f),
		vec3(0.5f,-0.5f, 0.5f), vec3(0.40f, 0.20f, 1.0f),

		vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.30f, 0.0f), // right - red
		vec3(0.5f,-0.5f,-0.5f), vec3(1.0f, 0.30f, 0.0f),
		vec3(0.5f, 0.5f,-0.5f), vec3(1.0f, 0.30f, 0.0f),

		vec3(0.5f,-0.5f,-0.5f), vec3(1.0f, 0.40f, 0.0f),
		vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.40f, 0.0f),
		vec3(0.5f,-0.5f, 0.5f), vec3(1.0f, 0.40f, 0.0f),

		vec3(0.5f, 0.5f, 0.5f), vec3(0.10f, .70f, 0.64350f), // top - green
		vec3(0.5f, 0.5f,-0.5f), vec3(0.10f, .70f, 0.64350f),
		vec3(-0.5f, 0.5f,-0.5f), vec3(0.10f, .70f, 0.64350f),

		vec3(0.5f, 0.5f, 0.5f), vec3(0.0f, .70f, 0.350f),
		vec3(-0.5f, 0.5f,-0.5f), vec3(0.0f, .70f, 0.350f),
		vec3(-0.5f, 0.5f, 0.5f), vec3(0.0f, .70f, 0.350f)
	};

	// Create a vertex array
	GLuint vertexArrayObject;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	// Upload Vertex Buffer to the GPU, keep a reference to it (vertexBufferObject)
	GLuint vertexBufferObject;
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

	glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
		3,                   // size
		GL_FLOAT,            // type
		GL_FALSE,            // normalized?
		2 * sizeof(vec3), // stride - each vertex contain 2 vec3 (position, color)
		(void*)0             // array buffer offset
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
		3,
		GL_FLOAT,
		GL_FALSE,
		2 * sizeof(vec3),
		(void*)sizeof(vec3)      // color is offseted a vec3 (comes after position)
	);
	glEnableVertexAttribArray(1);
	return vertexArrayObject;
}


int main(int argc, char* argv[])
{
	// Initialize GLFW and OpenGL version
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create Window and rendering context using GLFW, resolution is 1024x768
	GLFWwindow* window = glfwCreateWindow(1024, 768, "Assignment1", NULL, NULL);
	if (window == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	// Disable mouse cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to create GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Compile and link shaders here ...



	int shaderProgram = compileAndLinkShaders();
	glUseProgram(shaderProgram);



	vec3 defaultColor(0.8f, 0.8f, 0.8f);

	// Camera parameters for view transform
	vec3 cameraPosition(1.6f, 5.0f, 10.0f); //right, up, away
	vec3 cameraLookAt(0.0f, 0.0f, -1.0f);
	vec3 cameraUp(0.0f, 1.0f, 0.0f);

	// Other camera parameters
	float cameraSpeed = 10.0f;
	float cameraFastSpeed = 2 * cameraSpeed;
	float cameraHorizontalAngle = 90.0f;
	float cameraVerticalAngle = 0.0f;
	bool  cameraFirstPerson = true; // press 1 or 2 to toggle this variable

	// Spinning cube at camera position


	// Set projection matrix for shader, this won't change
	mat4 projectionMatrix = glm::perspective(70.0f,            // field of view in degrees
		1024.0f / 768.0f,  // aspect ratio
		0.01f, 100.0f);   // near and far (near > 0)

	GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &projectionMatrix[0][0]);

	// Set initial view matrix
	mat4 viewMatrix = lookAt(cameraPosition,  // eye
		cameraPosition + cameraLookAt,  // center
		cameraUp); // up

	GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

	int vao1 = createLineBufferObject();//does nothing/isbroken

	// Define and upload geometry to the GPU here ...
	int vao = createVertexBufferObject();

	// For frame time
	float lastFrameTime = glfwGetTime();
	int lastMouseLeftState = GLFW_RELEASE;
	double lastMousePosX, lastMousePosY;
	glfwGetCursorPos(window, &lastMousePosX, &lastMousePosY);

	// Enable Backface culling. Disabled so to allow the backside of a cube to by skyblue ^__^
	//glEnable(GL_CULL_FACE);

	// @TODO 1 - Enable Depth Test
	glEnable(GL_DEPTH_TEST);

	originalPosition = cameraPosition; //for resetting

	// Entering Main Loop
	while (!glfwWindowShouldClose(window))
	{
		// Frame time calculation
		float dt = glfwGetTime() - lastFrameTime;
		lastFrameTime += dt;

		//Clear Depth Buffer Bit as well
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Draw geometry
		glBindVertexArray(vao);



		glUseProgram(shaderProgram);


		GLuint uColorLocation = glGetUniformLocation(shaderProgram, "uColor");
		worldMatrixLocation = glGetUniformLocation(shaderProgram, "worldMatrix");

		//BOXXXXXXXXXXXX
		mat4 environmentMatrix = translate(mat4(1.0f), vec3(0.0f, 1.0f, 0.0f)) * scale(mat4(1.0f), vec3(100.0f, 100.0f, 100.0f));
		glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &environmentMatrix[0][0]);
		glDrawArrays(mode, 0, 36); // 36 vertices, starting at index 0


		mainCubeAngle += 60.0f * dt;


		drawShape(currentObject);

		drawLetter(currentLetter);

		

		//Draw Grid
		mat4 gridWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
		for (int i = -50; i < 50; ++i)
		{
			for (int j = -50; j < 50; ++j)
			{
				gridWorldMatrix = translate(mat4(1.0f), vec3(0.0f + i * 1.0f, -2.0f, 0.0f + j * 1.0f)) * scale(mat4(1.0f), vec3(1.0f, 0.0f, 1.0f));
				glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &gridWorldMatrix[0][0]);
				glDrawArrays(GL_LINES, 0, 8);
			}
		}


		//FAILED ATTEMPT AT DRAWING AXIS MARKER
		//mat4 lineWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
		//mat4 xlineWorldMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
		//glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &xlineWorldMatrix[0][0]);
		//glDrawArrays(GL_LINES, 0, 2);
		//xlineWorldMatrix = translate(mat4(1.0f), vec3(5.0f, 0.0f, 0.0f));
		//glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &xlineWorldMatrix[0][0]);
		//glDrawArrays(GL_LINES, 0, 2);



		//mat4 ylineWorldMatrix = lineWorldMatrix * scale(mat4(1.0f), vec3(0.0f, 5.0f, 0.0f));
		//glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &ylineWorldMatrix[0][0]);
		//glDrawArrays(GL_LINES, 0, 2);
		//mat4 zlineWorldMatrix = lineWorldMatrix * scale(mat4(1.0f), vec3(0.0f, 0.0f, 5.0f));
		//glUniformMatrix4fv(worldMatrixLocation, 1, GL_FALSE, &zlineWorldMatrix[0][0]);
		//glDrawArrays(GL_LINES, 0, 2);



		// Draw in view space for first person camera
		mat4 spinningCubeViewMatrix = translate(mat4(1.0f), vec3(0.0f, 0.0f, -1.0f)) *
			rotate(mat4(1.0f), radians(spinningCubeAngle), vec3(0.0f, 1.0f, 0.0f)) *
			scale(mat4(1.0f), vec3(0.01f, 0.01f, 0.01f));
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &spinningCubeViewMatrix[0][0]);

		// End Frame
		glfwSwapBuffers(window);
		glfwPollEvents();

		// Handle inputs
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		// Camera settings
		bool fastCam = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
		float currentCameraSpeed = (fastCam) ? cameraFastSpeed : cameraSpeed;

		//Update camera horizontal and vertical angle
		double mousePosX, mousePosY;
		glfwGetCursorPos(window, &mousePosX, &mousePosY);
		double dx = mousePosX - lastMousePosX;
		double dy = mousePosY - lastMousePosY;
		lastMousePosX = mousePosX;
		lastMousePosY = mousePosY;

		// Convert to spherical coordinates
		const float cameraAngularSpeed = 30.0f;
		cameraHorizontalAngle -= dx * cameraAngularSpeed * dt;
		cameraVerticalAngle -= dy * cameraAngularSpeed * dt;

		// Clamp vertical angle to [-85, 85] degrees
		cameraVerticalAngle = std::max(-85.0f, std::min(85.0f, cameraVerticalAngle));
		if (cameraHorizontalAngle > 360)
		{
			cameraHorizontalAngle -= 360;
		}
		else if (cameraHorizontalAngle < -360)
		{
			cameraHorizontalAngle += 360;
		}

		float theta = radians(cameraHorizontalAngle);
		float phi = radians(cameraVerticalAngle);


		cameraLookAt = vec3(cosf(phi) * cosf(theta), sinf(phi), -cosf(phi) * sinf(theta));
		vec3 cameraHorizontalVector = glm::cross(cameraLookAt, vec3(0.0f, 1.0f, 0.0f));
		vec3 cameraVerticalVector = glm::cross(cameraLookAt, vec3(1.0f, 0.0f, 0.0f));
		glm::normalize(cameraHorizontalVector);
		glm::normalize(cameraVerticalVector);

		//camera lookat and side vectors to update positions with ASDWKIX
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) // move camera to the left
		{
			cameraPosition -= cameraHorizontalVector * currentCameraSpeed * dt;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) // move camera to the right
		{
			cameraPosition += cameraHorizontalVector * currentCameraSpeed * dt;
		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) // move camera up
		{
			cameraPosition -= cameraVerticalVector * currentCameraSpeed * dt;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) // move camera down
		{
			cameraPosition += cameraVerticalVector * currentCameraSpeed * dt;
		}
		if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) // move camera back
		{
			cameraPosition -= cameraLookAt * currentCameraSpeed * dt;
		}
		if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) // move camera forward
		{
			cameraPosition += cameraLookAt * currentCameraSpeed * dt;
		}
		if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) // move camera forward
		{
			cameraPosition = originalPosition;
		}

		//CHANGE ITEM KEYS
		if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) // move camera forward
		{
			currentObject = 1;
			currentLetter = 1;
		}
		if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) // move camera forward
		{
			currentObject = 2;
			currentLetter = 2;
		}
		if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) // move camera forward
		{
			currentObject = 3;
			currentLetter = 3;
		}
		if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) // move camera forward
		{
			currentObject = 4;
			currentLetter = 4;
		}
		if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) // move camera forward
		{
			currentObject = 5;
			currentLetter = 5;
		}

		//MOVE OBJECT KEYS
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				x1_location -= 0.1;
			}
			if (currentObject == 2) {
				x2_location -= 0.1;
			}
			if (currentObject == 3) {
				x3_location -= 0.1;
			}
			if (currentObject == 4) {
				x4_location -= 0.1;
			}
			if (currentObject == 5) {
				x5_location -= 0.1;
			}
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				x1_location += 0.1;
			}
			if (currentObject == 2) {
				x2_location += 0.1;
			}
			if (currentObject == 3) {
				x3_location += 0.1;
			}
			if (currentObject == 4) {
				x4_location += 0.1;
			}
			if (currentObject == 5) {
				x5_location += 0.1;
			}
		}
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				y1_location += 0.1;
			}
			if (currentObject == 2) {
				y2_location += 0.1;
			}
			if (currentObject == 3) {
				y3_location += 0.1;
			}
			if (currentObject == 4) {
				y4_location += 0.1;
			}
			if (currentObject == 5) {
				y5_location += 0.1;
			}
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				y1_location -= 0.1;
			}
			if (currentObject == 2) {
				y2_location -= 0.1;
			}
			if (currentObject == 3) {
				y3_location -= 0.1;
			}
			if (currentObject == 4) {
				y4_location -= 0.1;
			}
			if (currentObject == 5) {
				y5_location -= 0.1;
			}
		}
		if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				z1_location += 0.1;
			}
			if (currentObject == 2) {
				z2_location += 0.1;
			}
			if (currentObject == 3) {
				z3_location += 0.1;
			}
			if (currentObject == 4) {
				z4_location += 0.1;
			}
			if (currentObject == 5) {
				z5_location += 0.1;
			}
		}
		if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				z1_location -= 0.1;
			}
			if (currentObject == 2) {
				z2_location -= 0.1;
			}
			if (currentObject == 3) {
				z3_location -= 0.1;
			}
			if (currentObject == 4) {
				z4_location -= 0.1;
			}
			if (currentObject == 5) {
				z5_location -= 0.1;
			}
		}

		if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) // move camera forward
		{
			upscale += 0.1;
		}
		if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) // move camera forward
		{
			upscale -= 0.1;
		}

		//change rendering mode
		if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS) // move camera forward
		{
			mode = GL_TRIANGLES;
		}
		if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS) // move camera forward
		{
			mode = GL_POINTS;
		}
		if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) // move camera forward
		{
			mode = GL_LINES;
		}

		//Rotations
		if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) // move camera forward
		{

			if (currentObject == 1) {
				x1_rotate += 0.5;
			}
			if (currentObject == 2) {
				x2_rotate += 0.5;
			}
			if (currentObject == 3) {
				x3_rotate += 0.5;
			}
			if (currentObject == 4) {
				x4_rotate += 0.5;
			}
			if (currentObject == 5) {
				x5_rotate += 0.5;
			}

		}
		if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				y1_rotate += 0.5;
			}
			if (currentObject == 2) {
				y2_rotate += 0.5;
			}
			if (currentObject == 3) {
				y3_rotate += 0.5;
			}
			if (currentObject == 4) {
				y4_rotate += 0.5;
			}
			if (currentObject == 5) {
				y5_rotate += 0.5;
			}
		}

		if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) // move camera forward
		{
			if (currentObject == 1) {
				y1_rotate -= 0.5;
			}
				if (currentObject == 2) {
					y2_rotate -= 0.5;
				}
				if (currentObject == 3) {
					y3_rotate -= 0.5;
				}
				if (currentObject == 4) {
					y4_rotate -= 0.5;
				}
				if (currentObject == 5) {
					y5_rotate -= 0.5;
				}
			
		}

		if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) // trying to figure out how to align camera to an object
		{
			std::cout << x1_location << "\n";
			std::cout << y1_location << "\n";
			std::cout << z1_location << "\n";
			std::cout << x1_rotate << "\n";
			std::cout << y1_rotate << "\n";


			mat4 viewMatrix = mat4(1.0);

			viewMatrix = lookAt(cameraPosition, cameraPosition + cameraLookAt, cameraUp);
			//viewMatrix = lookAt(vec3(x1_location, y1_location, z1_location), vec3(x1_location, y1_location, z1_location) + cameraLookAt, cameraUp);



			GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
			glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

			lastMouseLeftState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
		}

		//////////////////

		// Set the view matrix 

		mat4 viewMatrix = mat4(1.0);

		viewMatrix = lookAt(cameraPosition, cameraPosition + cameraLookAt, cameraUp);
		//viewMatrix = lookAt(vec3(x1_location, y1_location, z1_location), vec3(x1_location, y1_location, z1_location) + cameraLookAt, cameraUp);

		

		GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
		glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);

		lastMouseLeftState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);


	}
	// Shutdown GLFW
	glfwTerminate();
	return 0;
}
