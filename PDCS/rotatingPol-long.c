#include "primlib.h"
#include <stdlib.h>
#include <assert.h>


#ifndef PI
#define PI 3.14159265358979323846
#endif

#ifndef TWO_PI
#define TWO_PI 6.28318530717958647692
#endif

#ifndef NUMBER_OF_VERTICES
#define NUMBER_OF_VERTICES 5
#endif

#ifndef ROTATION_AMOUNT
#define ROTATION_AMOUNT 0.01
#endif


static float width, height, centerX, centerY;
static float phi = 0, r = 150, changeAmount = 0.2;
static float theta = (TWO_PI / NUMBER_OF_VERTICES); //Angle between consecutive vertices
static float beta = 0;

static short *pVertices;
static short twiceNumberOfVertices = NUMBER_OF_VERTICES * 2; //Repeatedly used for small loops
static short lastPoint = NUMBER_OF_VERTICES * 2 - 2; //Used for drawing polygon on the screen


short *makePoly(void);
void translate(short *pV, float x, float y);
void rotate(short *pV, float angle);
void changeR(void);


int main(int argc, char* argv[]){
	if(initGraph()){
		exit(3);
	}
	width = screenWidth();
	height = screenHeight();

	centerX = width / 2;
	centerY = height / 2;

	// pVertices = makePoly(); //Create a polygon
	pVertices = makePoly();

	//Animation loop
	while(!isKeyDown(SDLK_ESCAPE)){

		//Draw background
		filledRect(0, 0, width, height, BLACK);

		//Translate polygon by given amount
		translate(pVertices, centerX, centerY);


		for (unsigned short i = 0; i < twiceNumberOfVertices; i += 2){

			if (i == lastPoint){
				line(pVertices[i], pVertices[i+1], pVertices[0], pVertices[1], MAGENTA);

			}else{
				//Drawing line from the last to the first point
				line(pVertices[i], pVertices[i+1], pVertices[i+2], pVertices[i+3], MAGENTA);
			}
		}

		//Rotation of polygon
		rotate(pVertices, beta);

		//Correction for angles that exceeded TWO_PI
		if (beta > TWO_PI){
			beta -= TWO_PI;
		}else if (-beta > TWO_PI){
			beta += TWO_PI;
		}
		beta += ROTATION_AMOUNT;

		changeR();

		SDL_Delay(10);
		updateScreen();
	}


	free(pVertices); //It's really important to free up the used allocated memory
	assert(pVertices != 0);
	return 0;
}


void translate(short *pV, float x, float y){
	for (unsigned short i = 0; i < twiceNumberOfVertices; i += 2){
		pV[i] += (short)roundf(x);
		pV[i+1] += (short)roundf(y);
	}
}


void rotate(short *pV, float angle){
	phi = 0;

	for (unsigned short i = 0; i < twiceNumberOfVertices; i += 2){

		//x value of vertex
		pV[i] = (short)(r * cos(phi + angle));

		//y value of vertex
		pV[i+1] = (short)(r * sin(phi + angle));

		phi += theta;
	}
}


short *makePoly(void){

	short *vertices = (short *) calloc(twiceNumberOfVertices, sizeof(short)); //Remember to put 'sizeof(<data type you're gonna use>)'

	rotate(vertices, 0);

	return vertices;
}


void changeR(void){

	if (r > centerY){
		changeAmount = -changeAmount;
	}else if (r < 50){
		changeAmount = -changeAmount;
	}

	r += changeAmount;
}
