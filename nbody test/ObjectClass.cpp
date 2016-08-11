//////////////////////////////////////////////////////////////////////////////
//Filename: ObjectClass.h
//
//this file contains the definition of the methods in the class Object 
//////////////////////////////////////////////////////////////////////////////
#include "ObjectClass.h"

Object::Object(){
	m_objectCoordinates.x = 0.0L;
	m_objectCoordinates.y = 0.0L;
	m_objectCoordinates.x = 0.0L;
	
	m_speed.x = 0.0f;
	m_speed.y = 0.0f;
	m_speed.z = 0.0f;

	m_objectRotation = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
}

Object::~Object(){
}

void Object::translateXYZ(double dx, double dy, double dz){
	m_objectCoordinates.x += dx;
	m_objectCoordinates.y += dy;
	m_objectCoordinates.z += dz;
}


void Object::GetCoordinates(double *x, double *y, double *z){
	*x = m_objectCoordinates.x;
	*y = m_objectCoordinates.y;
	*z = m_objectCoordinates.z;
}


void Object::GetRotation(DirectX::XMVECTOR *rotation){
	*rotation = m_objectRotation;
}


void Object::SetCoordinates(double x, double y, double z){
	m_objectCoordinates.x = x;
	m_objectCoordinates.y = y;
	m_objectCoordinates.z = z;
}


void Object::SetSpeed(float X, float Y, float Z){
	m_speed.x = X;
	m_speed.y = Y;
	m_speed.z = Z;
}


void Object::GetSpeed(DirectX::XMFLOAT3 *speed){
	*speed = m_speed;
}


void Object::SetRotation(float rotationX, float rotationY, float rotationZ){
	DirectX::XMVECTOR qx, qy, qz;
	DirectX::XMVECTOR qt;
	DirectX::XMVECTOR axisX = DirectX::XMVectorSet(1,0,0,0); 
	DirectX::XMVECTOR axisY = DirectX::XMVectorSet(0,1,0,0);
	DirectX::XMVECTOR axisZ = DirectX::XMVectorSet(0,0,1,0);

	qx = DirectX::XMQuaternionIdentity();
	qy = DirectX::XMQuaternionIdentity();
	qz = DirectX::XMQuaternionIdentity();

	qx = DirectX::XMQuaternionRotationAxis(axisX, DirectX::XMConvertToRadians(rotationX));
	qy = DirectX::XMQuaternionRotationAxis(axisY, DirectX::XMConvertToRadians(rotationY));					//aquí puede que se pueda usar la función XMQaternionRotationNormal ya que usamos las normales de los vectores
	qz = DirectX::XMQuaternionRotationAxis(axisZ, DirectX::XMConvertToRadians(rotationZ));

	qt = DirectX::XMQuaternionMultiply(qx, qy);
	m_objectRotation = DirectX::XMQuaternionMultiply(qt, qz);
}


void Object::rotate(float rotationX, float rotationY, float rotationZ){
	DirectX::XMVECTOR qx, qy, qz;
	DirectX::XMVECTOR qt, qr;
	DirectX::XMVECTOR axisX = DirectX::XMVectorSet(1,0,0,0); 
	DirectX::XMVECTOR axisY = DirectX::XMVectorSet(0,1,0,0);
	DirectX::XMVECTOR axisZ = DirectX::XMVectorSet(0,0,1,0);

	qx = DirectX::XMQuaternionIdentity();
	qy = DirectX::XMQuaternionIdentity();
	qz = DirectX::XMQuaternionIdentity();

	qx = DirectX::XMQuaternionRotationAxis(axisX, DirectX::XMConvertToRadians(rotationX));
	qy = DirectX::XMQuaternionRotationAxis(axisY, DirectX::XMConvertToRadians(rotationY));					//aquí puede que se pueda usar la función XMQaternionRotationNormal ya que usamos las normales de los vectores
	qz = DirectX::XMQuaternionRotationAxis(axisZ, DirectX::XMConvertToRadians(rotationZ));

	qt = DirectX::XMQuaternionMultiply(qx, qy);
	qr = DirectX::XMQuaternionMultiply(qt, qz);

	m_objectRotation = DirectX::XMQuaternionMultiply(m_objectRotation, qr);
}


void Object::frame(float dTime){									//aquí intento obtener el desplazamiento en xyz en cada frame mediante transformaciones
	DirectX::XMMATRIX rotationMatrix = DirectX::XMMatrixRotationQuaternion(m_objectRotation);
	DirectX::XMMATRIX transMatrix;
	DirectX::XMFLOAT4X4 transMatrix_;
	
	transMatrix = DirectX::XMMatrixTranslation(m_speed.x * dTime, m_speed.y * dTime, m_speed.z * dTime);
	rotationMatrix = DirectX::XMMatrixMultiply(rotationMatrix, transMatrix);
	
	DirectX::XMStoreFloat4x4(&transMatrix_, transMatrix);

	m_objectCoordinates.x += (float)transMatrix_._41;
	m_objectCoordinates.y += (float)transMatrix_._42;
	m_objectCoordinates.z += (float)transMatrix_._43;
}
