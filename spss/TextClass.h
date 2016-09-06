////////////////////////////////////////////////////////////////////////////////
// Filename: textclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTCLASS_H_
#define _TEXTCLASS_H_
#define XM_CALLCONV __fastcall

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "fontclass.h"
#include "fontshaderclass.h"

////////////
//INCLUDES//
////////////
#include <DirectXMath.h>

typedef const DirectX::XMVECTOR  FXMVECTOR;
typedef const DirectX::XMVECTOR& GXMVECTOR;
typedef const DirectX::XMVECTOR& HXMVECTOR;
typedef const DirectX::XMVECTOR& CXMVECTOR;
typedef const DirectX::XMMATRIX& FXMMATRIX;
typedef const DirectX::XMMATRIX& CXMMATRIX;

////////////////////////////////////////////////////////////////////////////////
// Class name: TextClass
////////////////////////////////////////////////////////////////////////////////
class TextClass
{
private:
	struct SentenceType
	{
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		int vertexCount, indexCount, maxLength;
		float red, green, blue;
	};


	struct VertexType
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT2 texture;
	};

public:
	TextClass();
	TextClass(const TextClass&);
	~TextClass();

	bool XM_CALLCONV Initialize(ID3D11Device*, ID3D11DeviceContext*, HWND, int, int, DirectX::CXMMATRIX);
	void Shutdown();
	bool XM_CALLCONV Render(ID3D11DeviceContext*, DirectX::CXMMATRIX, DirectX::CXMMATRIX);
	bool SetMousePosition(int, int, ID3D11DeviceContext*);

	bool SetFps(int, ID3D11DeviceContext*);
	bool SetCpu(int, ID3D11DeviceContext*);

	bool SetRenderCount(int, ID3D11DeviceContext*);

private:
	bool InitializeSentence(SentenceType**, int, ID3D11Device*);
	bool UpdateSentence(SentenceType*, char*, int, int, float, float, float, ID3D11DeviceContext*);
	void ReleaseSentence(SentenceType**);
	bool XM_CALLCONV RenderSentence(ID3D11DeviceContext*, SentenceType*, DirectX::CXMMATRIX, DirectX::CXMMATRIX);

private:
	FontClass* m_Font;
	FontShaderClass* m_FontShader;
	int m_screenWidth, m_screenHeight;
	DirectX::XMMATRIX m_baseViewMatrix;


	SentenceType* m_sentence1;
	SentenceType* m_sentence2;
};

#endif
