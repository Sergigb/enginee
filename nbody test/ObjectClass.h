///////////////////////////////////////////////////////////////////////////////
// Filename: ObjectClass.h
///////////////////////////////////////////////////////////////////////////////
#ifndef _OBJECTCLASS_H_
#define _OBJECTCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <DirectXMath.h>

/////////////////
// MY INCLUDES //
/////////////////
#include "Common.h"


///////////////////////////////////////////////////////////////////////////////
// Class name: Object
///////////////////////////////////////////////////////////////////////////////
class Object
{

public:
	Object();
	~Object();
	void GetCoordinates(double*, double*, double*);
	void GetRotation(DirectX::XMVECTOR*);

	void translateXYZ(double, double, double);
	void frame(float);
	void SetSpeed(float);
	void rotate(float, float, float);

private:
	void SetCoordinates(double, double, double);

private:
	float m_speed;
	Common::coordinates m_objectCoordinates;
	DirectX::XMVECTOR m_objectRotation;
};

#endif

