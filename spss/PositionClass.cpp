////////////////////////////////////////////////////////////////////////////////
// Filename: positionclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "positionclass.h"


PositionClass::PositionClass()
{
	m_frameTime = 0.0f;
	m_rotationY = 0.0f;
	m_rotationX = 0.0f;
	m_leftTurnSpeed  = 0.0f;
	m_rightTurnSpeed = 0.0f;
	m_upTurnSpeed = 0.0f;
	m_downTurnSpeed = 0.0f;
}


PositionClass::PositionClass(const PositionClass& other)
{
}


PositionClass::~PositionClass()
{
}


void PositionClass::SetFrameTime(float time)
{
	m_frameTime = time;
	return;
}


void PositionClass::GetRotation(float &y, float &x)
{
	y = m_rotationY;
	x = m_rotationX;
	return;
}


void PositionClass::Rotate(bool k_left, bool k_right, bool k_up, bool k_down)
{
	// If the key is pressed increase the speed at which the camera turns right.  If not slow down the turn speed.
	if(k_left)	{
		m_leftTurnSpeed += m_frameTime * 0.01f;

		if(m_leftTurnSpeed > (m_frameTime * 0.15f))
			m_leftTurnSpeed = m_frameTime * 0.15f;
	}
	else{
		m_leftTurnSpeed -= m_frameTime* 0.005f;

		if(m_leftTurnSpeed < 0.0f)
			m_leftTurnSpeed = 0.0f;
	}

	if(k_right){
		m_rightTurnSpeed += m_frameTime * 0.01f;

		if(m_rightTurnSpeed > (m_frameTime * 0.15f))
			m_rightTurnSpeed = m_frameTime * 0.15f;
	}
	else{
		m_rightTurnSpeed -= m_frameTime* 0.005f;

		if(m_rightTurnSpeed < 0.0f)
			m_rightTurnSpeed = 0.0f;
	}

	if(k_up){
		m_upTurnSpeed += m_frameTime * 0.01f;

		if(m_upTurnSpeed > (m_frameTime * 0.15f))
			m_upTurnSpeed = m_frameTime * 0.15f;
	}
	else{
		m_upTurnSpeed -= m_frameTime* 0.005f;

		if(m_upTurnSpeed < 0.0f)
			m_upTurnSpeed = 0.0f;
	}

	if(k_down){
		m_downTurnSpeed += m_frameTime * 0.01f;

		if(m_downTurnSpeed > (m_frameTime * 0.15f))
			m_downTurnSpeed = m_frameTime * 0.15f;
	}
	else{
		m_downTurnSpeed -= m_frameTime* 0.005f;

		if(m_downTurnSpeed < 0.0f)
			m_downTurnSpeed = 0.0f;
	}


	// Update the rotation using the turning speed.
	m_rotationY += m_rightTurnSpeed - m_leftTurnSpeed;
	m_rotationX += m_downTurnSpeed - m_upTurnSpeed;
	if(m_rotationY > 360.0f)
	{
		m_rotationY -= 360.0f;
	}

	if(m_rotationX > 360.0f)
	{
		m_rotationX -= 360.0f;
	}
	return;
}

