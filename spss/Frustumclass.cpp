////////////////////////////////////////////////////////////////////////////////
// Filename: frustumclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "frustumclass.h"


FrustumClass::FrustumClass()
{
}


FrustumClass::FrustumClass(const FrustumClass& other)
{
}


FrustumClass::~FrustumClass()
{
}


void XM_CALLCONV FrustumClass::ConstructFrustum(float screenDepth, DirectX::CXMMATRIX projectionMatrix, DirectX::CXMMATRIX viewMatrix)
{
	float zMinimum, r;
	DirectX::XMMATRIX matrix;
	DirectX::XMFLOAT4X4 matrix_;
	DirectX::XMFLOAT4X4 projectionMatrix_;

	DirectX::XMStoreFloat4x4(&projectionMatrix_, projectionMatrix);

	// Calculate the minimum Z distance in the frustum.
	zMinimum = -projectionMatrix_._43 / projectionMatrix_._33;
	r = screenDepth / (screenDepth - zMinimum);
	projectionMatrix_._33 = r;
	projectionMatrix_._43 = -r * zMinimum;

	// Create the frustum matrix from the view matrix and updated projection matrix.
	matrix = DirectX::XMMatrixMultiply(viewMatrix, projectionMatrix);
	
	DirectX::XMStoreFloat4x4(&matrix_, matrix);
	
	// Calculate near plane of frustum.
	DirectX::XMVectorSet(matrix_._14 + matrix_._13,
						 matrix_._24 + matrix_._23,
						 matrix_._34 + matrix_._33, 
						 matrix_._44 + matrix_._43);

	m_planes[0] = DirectX::XMPlaneNormalize(m_planes[0]);

	// Calculate far plane of frustum.
	DirectX::XMVectorSet(matrix_._14 - matrix_._13,
						 matrix_._24 - matrix_._23,
						 matrix_._34 - matrix_._33, 
						 matrix_._44 - matrix_._43);

	m_planes[1] = DirectX::XMPlaneNormalize(m_planes[1]);

	// Calculate left plane of frustum.
	DirectX::XMVectorSet(matrix_._14 + matrix_._11,
						 matrix_._24 + matrix_._21,
						 matrix_._34 + matrix_._31, 
						 matrix_._44 + matrix_._41);

	m_planes[2] = DirectX::XMPlaneNormalize(m_planes[2]);

	// Calculate right plane of frustum.
	DirectX::XMVectorSet(matrix_._14 - matrix_._11,
						 matrix_._24 - matrix_._21,
						 matrix_._34 - matrix_._31, 
						 matrix_._44 - matrix_._41);

	m_planes[3] = DirectX::XMPlaneNormalize(m_planes[3]);

	// Calculate top plane of frustum.
	DirectX::XMVectorSet(matrix_._14 - matrix_._12,
						 matrix_._24 - matrix_._22,
						 matrix_._34 - matrix_._32, 
						 matrix_._44 - matrix_._42);

	m_planes[4] = DirectX::XMPlaneNormalize(m_planes[4]);

	// Calculate bottom plane of frustum.
	DirectX::XMVectorSet(matrix_._14 + matrix_._12,
						 matrix_._24 + matrix_._22,
						 matrix_._34 + matrix_._32, 
						 matrix_._44 + matrix_._42);

	m_planes[5] = DirectX::XMPlaneNormalize(m_planes[5]);

	return;
}


bool FrustumClass::CheckPoint(float x, float y, float z)
{
	int i;
	float prod;
	DirectX::XMVECTOR plane;

	// Check if the point is inside all six planes of the view frustum.
	for(i=0; i<6; i++) 
	{
		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet(x, y, z, 0.0f));
		prod = DirectX::XMVectorGetX(plane) * x + DirectX::XMVectorGetY(plane) * y + DirectX::XMVectorGetZ(plane) * z + DirectX::XMVectorGetW(plane) * 1.0f;

		if(prod < 0.0f)
		{
			return false;
		}
	}

	return true;
}


bool FrustumClass::CheckCube(float xCenter, float yCenter, float zCenter, float radius)
{
	int i;
	float prod;
	DirectX::XMVECTOR plane;

	// Check if any one point of the cube is in the view frustum.
	for(i=0; i<6; i++) 
	{
		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - radius), (yCenter - radius), (zCenter - radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter - radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if( prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + radius), (yCenter - radius), (zCenter - radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter - radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - radius), (yCenter + radius), (zCenter - radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter + radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + radius), (yCenter + radius), (zCenter - radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter + radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - radius), (yCenter - radius), (zCenter + radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter - radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + radius), (yCenter - radius), (zCenter + radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter - radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - radius), (yCenter + radius), (zCenter + radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter + radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}
		
		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + radius), (yCenter + radius), (zCenter + radius), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + radius) +
			   DirectX::XMVectorGetY(plane) * (yCenter + radius) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + radius) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		return false;
	}

	return true;
}


bool FrustumClass::CheckSphere(float xCenter, float yCenter, float zCenter, float radius)
{
	int i;
	float prod;
	DirectX::XMVECTOR plane;

	// Check if the radius of the sphere is inside the view frustum.
	for(i=0; i<6; i++) 
	{
		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet(xCenter, yCenter, zCenter, 1.0f));
		prod = DirectX::XMVectorGetX(plane) * xCenter +
			   DirectX::XMVectorGetY(plane) * yCenter + 
			   DirectX::XMVectorGetZ(plane) * zCenter + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod < -radius)
		{
			return false;
		}
	}

	return true;
}


bool FrustumClass::CheckRectangle(float xCenter, float yCenter, float zCenter, float xSize, float ySize, float zSize)
{
	int i;
	float prod;
	DirectX::XMVECTOR plane;


	// Check if any of the 6 planes of the rectangle are inside the view frustum.
	for(i=0; i<6; i++)
	{
		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - xSize), (yCenter - ySize), (zCenter - zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter - ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}
		
		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + xSize), (yCenter - ySize), (zCenter - zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter - ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - xSize), (yCenter + ySize), (zCenter - zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter + ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - xSize), (yCenter - ySize), (zCenter + zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter - ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + xSize), (yCenter + ySize), (zCenter - zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter + ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter - zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + xSize), (yCenter - ySize), (zCenter + zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter - ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter - xSize), (yCenter + ySize), (zCenter + zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter - xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter + ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		plane = DirectX::XMPlaneDotCoord(m_planes[i], DirectX::XMVectorSet((xCenter + xSize), (yCenter + ySize), (zCenter + zSize), 1.0f));
		prod = DirectX::XMVectorGetX(plane) * (xCenter + xSize) +
			   DirectX::XMVectorGetY(plane) * (yCenter + ySize) + 
			   DirectX::XMVectorGetZ(plane) * (zCenter + zSize) + 
			   DirectX::XMVectorGetW(plane) * 1.0f;
		if(prod >= 0.0f)
		{
			continue;
		}

		return false;
	}

	return true;
}

