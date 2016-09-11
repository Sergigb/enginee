////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "inputclass.h"


InputClass::InputClass()
{
	for(int i = 0; i < 256; i++){
		m_keyboardState[i].keyState = false;
		m_keyboardState[i].lparam = 0;
	}
}


InputClass::InputClass(const InputClass& other)
{
}


InputClass::~InputClass()
{
}


void InputClass::Shutdown()
{
}



void InputClass::ProcessInput()
{
}


void InputClass::GetMouseLocation(int& mouseX, int& mouseY)
{
	mouseX = m_mouseX;
	mouseY = m_mouseY;
	return;
}


bool InputClass::IsPressed(unsigned char key){
	return m_keyboardState[key].keyState;
}

/*bool InputClass::IsRMBpressed(){
}*/

void InputClass::setKey(bool state, unsigned int key, LPARAM lparam){
	if(key <= 255 && key >= 0){
		m_keyboardState[key].keyState = true;
		m_keyboardState[key].lparam = lparam;
	}
}

void InputClass::unsetKey(bool state, unsigned int key, LPARAM lparam){
	if(key <= 255 && key >= 0){
		m_keyboardState[key].keyState = false;
		m_keyboardState[key].lparam = lparam;
	}
}