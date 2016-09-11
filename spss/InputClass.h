////////////////////////////////////////////////////////////////////////////////
// Filename: inputclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INPUTCLASS_H_
#define _INPUTCLASS_H_


///////////////////////////////
// PRE-PROCESSING DIRECTIVES //
///////////////////////////////
#define DIRECTINPUT_VERSION 0x0800


/////////////
// LINKING //
/////////////
//#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")


//////////////
// INCLUDES //
//////////////
#include <Windows.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: InputClass
////////////////////////////////////////////////////////////////////////////////
class InputClass
{
	typedef struct keyboard{
		bool keyState;
		LPARAM lparam;
	}keyboard;

public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	void Shutdown();
	bool Frame();

	bool IsEscapePressed();
	void GetMouseLocation(int&, int&);

	bool IsPressed(unsigned char);
	bool IsRMBpressed();

	void setKey(bool, unsigned int, LPARAM);
		void unsetKey(bool, unsigned int, LPARAM);
private:
	keyboard m_keyboardState[256];

	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
};

#endif
