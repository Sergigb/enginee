#include "main.h"


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

		std::cin >> opt;
		switch(opt){
		case 1:
			setSpeed(&test);
			break;
		case 2:
			setRotation(&test);
			break;
		case 3:
			translate(&test);
			break;
		case 4:
			rotate(&test);
			break;
		case 5:
			frame(&test);
			break;
		case 6:
			getCoordinates(&test);
			break;
		case 7:
			getRotation(&test);
			break;
		case 8:
			getSpeed(&test);
			break;
		case 0:
			i = 0;
			break;
		}

	}
	
	return 0;
}


void setSpeed(Object *object){
	float x, y, z;
	DirectX::XMFLOAT3 speed;

	system("CLS");

	std::cout << "X component: ";
	std::cin >> x;
	std::cout << "Y component: ";
	std::cin >> y;
	std::cout << "Z component: ";
	std::cin >> z;

	object->SetSpeed(x,y,z);
	object->GetSpeed(&speed);
	std::cout << "Speed set to: " << speed.x << ", " << speed.y << ", " << speed.z << std::endl;
}


void setRotation(Object *object){
	float x, y, z;
	DirectX::XMFLOAT3 rotation;

	system("CLS");

	std::cout << "X component: ";
	std::cin >> x;
	std::cout << "Y component: ";
	std::cin >> y;
	std::cout << "Z component: ";
	std::cin >> z;

	object->SetRotation(x,y,z);
	object->GetRotation(&rotation);
	std::cout << "Rotation set to: " << rotation.x << ", " << rotation.y << ", " << rotation.z << std::endl;
}


void translate(Object *object){


}


void rotate(Object *object){

}


void frame(Object *object){


}


void getCoordinates(Object *object){


}


void getRotation(Object *object){

}


void getSpeed(Object *object){


}