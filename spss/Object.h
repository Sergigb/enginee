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
	void GetRotation(DirectX::XMFLOAT3*);
	void GetSpeed(DirectX::XMFLOAT3*);
	void GetQuaternion(DirectX::XMVECTOR *);

	void SetSpeed(float, float, float);
	void SetRotation(float, float, float);
	void translateXYZ(double, double, double);
	void translateLocal(double, double, double);

	void frame(float);
	void rotate(float, float, float);
	void SetCoordinates(double, double, double);

private:
	

private:
	DirectX::XMFLOAT3 m_speed;
	Common::coordinates m_objectCoordinates;
	DirectX::XMVECTOR m_objectRotation;
};

#endif

