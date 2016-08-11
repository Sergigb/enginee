#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>


#include "Common.h"
#include "ObjectClass.h"


int main(void) {
	int i = 1, opt;
	Object test;

	while(i != 0){
		std::cout << "1 - SetSpeed - sets speed" << std::endl;
		std::cout << "2 - SetRotation - sets rotation" << std::endl;
		std::cout << "3 - translateXYZ - translates the object along the 3 axis" << std::endl;
		std::cout << "4 - rotate - rotates the object along yaw, pitch and roll" << std::endl;
		std::cout << "5 - frame - moves the object given a delta v" << std::endl << std::endl;
		std::cout << "6 - GetCoordinates - shows the current object coordinates" << std::endl;
		std::cout << "7 - GetRotation - shows the current object rotation" << std::endl;
		std::cout << "8 - GetSpeed - shows the current object speed" << std::endl;
		std::cout << "0 - exit" << std::endl;

		switch(opt){
		case 1:
			setSpeed(test);
			break;
		case 2:
			setRotation(test);
			break;
		case 3:
			translate(test);
			break;
		case 4:
			rotate(test);
			break;
		case 5:
			frame(test);
			break;
		case 6:
			getCoordinates(test);
			break;
		case 7:
			getRotation(test);
			break;
		case 8:
			getSpeed(test);
			break;
		case 0:
			i = 0;
			break;
		}
		std::cin >> opt;
	}
	
	getch();
	return 0;
}


void setSpeed(Object object){


}


void setRotation(Object object){
	
}


void translate(Object object){


}


void rotate(Object object){

}


void frame(Object object){


}


void getCoordinates(Object object){


}


void getRotation(Object object){

}


void getSpeed(Object object){


}