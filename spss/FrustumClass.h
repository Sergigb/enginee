////////////////////////////////////////////////////////////////////////////////
// Filename: frustumclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _FRUSTUMCLASS_H_
#define _FRUSTUMCLASS_H_
#define XM_CALLCONV __fastcall


//////////////
// INCLUDES //
//////////////
//#include <d3dx10math.h>
#include <DirectXMath.h>

typedef const DirectX::XMVECTOR  FXMVECTOR;
typedef const DirectX::XMVECTOR& GXMVECTOR;
typedef const DirectX::XMVECTOR& HXMVECTOR;
typedef const DirectX::XMVECTOR& CXMVECTOR;
typedef const DirectX::XMMATRIX& FXMMATRIX;
typedef const DirectX::XMMATRIX& CXMMATRIX;

////////////////////////////////////////////////////////////////////////////////
// Class name: FrustumClass
////////////////////////////////////////////////////////////////////////////////
class FrustumClass
{
public:
	FrustumClass();
	FrustumClass(const FrustumClass&);
	~FrustumClass();

	void XM_CALLCONV ConstructFrustum(float, DirectX::CXMMATRIX, DirectX::CXMMATRIX);

	bool CheckPoint(float, float, float);
	bool CheckCube(float, float, float, float);
	bool CheckSphere(float, float, float, float);
	bool CheckRectangle(float, float, float, float, float, float);

private:
	DirectX::XMVECTOR m_planes[6];
};

#endif

