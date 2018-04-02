#include "primlib.h"
#include <stdlib.h>


#define TWO_PI (2 * M_PI)
#define NUMBER_OF_VERTICES 5
#define MINIMAL_R 50
#define ROTATION_STEP 0.02
#define DELAY_TIME 10
#define THETA (TWO_PI / NUMBER_OF_VERTICES) //Angle between consecutive vertices
#define LAST_POINT  (NUMBER_OF_VERTICES - 1) //Used for drawing polygon on the screen


typedef struct Point{
	short x;
	short y;
}point;


void translate(point *pV, float xChange, float yChange);
void rotate(point *pV, float *pbeta, float *pr);
void changeR(float *pr, float *pchangeAmount, float centerY);


int main(int argc, char* argv[]){

	if(initGraph()){
		exit(3);
	}
    static float width;
    static float height;
    static float centerX;
    static float centerY;

	width = screenWidth();
	height = screenHeight();
	centerX = width / 2;
	centerY = height / 2;

	static float beta = 0;
	static float r = 150, changeAmount = 0.2;

	point Vertices[NUMBER_OF_VERTICES];
	rotate(Vertices, &beta, &r);

	//Animation loop
	while(!isKeyDown(SDLK_ESCAPE)){

		//Draw background
		filledRect(0, 0, width, height, BLACK);

		//Translate polygon by given amount
		translate(Vertices, centerX, centerY);


		for (unsigned short i = 0; i < NUMBER_OF_VERTICES; i++){

			if (i == LAST_POINT){
				line(Vertices[i].x, Vertices[i].y, Vertices[0].x, Vertices[0].y, MAGENTA);

			}else{
				//Drawing line from the last to the first point
				line(Vertices[i].x, Vertices[i].y, Vertices[i+1].x, Vertices[i+1].y, MAGENTA);
			}
		}

		//Rotation of polygon
		rotate(Vertices, &beta, &r);

		beta += ROTATION_STEP;

		changeR(&r, &changeAmount, centerY);


		SDL_Delay(DELAY_TIME);
		updateScreen();
	}


	return 0;
}


void translate(point *pV, float xChange, float yChange){
	for (unsigned short i = 0; i < NUMBER_OF_VERTICES; i++){
		pV[i].x += (short)roundf(xChange);
		pV[i].y += (short)roundf(yChange);
	}
}


void rotate(point *pV, float *pbeta, float *pr){
	static float phi = 0;

	//Correction for angles that exceeded TWO_PI
	if (*pbeta >= TWO_PI){
		*pbeta -= TWO_PI;
	}else if (-(*pbeta) >= TWO_PI){
		*pbeta += TWO_PI;
	}

	for (unsigned short i = 0; i < NUMBER_OF_VERTICES; i++){

		pV[i].x = (short)(*pr * cos(phi + *pbeta));
		pV[i].y = (short)(*pr * sin(phi + *pbeta));

		phi += THETA;
	}
}


void changeR(float *pr, float *pchangeAmount, float centerY){

	if (*pr > centerY){
		*pchangeAmount = -(*pchangeAmount);
	}else if (*pr < MINIMAL_R){
		*pchangeAmount = -(*pchangeAmount);
	}

	*pr += *pchangeAmount;
}
