////////////////////////////////////////////////////////////////////////////////
// Filename: colorshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _COLORSHADERCLASS_H_
#define _COLORSHADERCLASS_H_
#define XM_CALLCONV __fastcall


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
//#include <d3dx10math.h>
#include <DirectXMath.h>
#include <d3dx11async.h>
#include <fstream>
using namespace std;

typedef const DirectX::XMVECTOR  FXMVECTOR;
typedef const DirectX::XMVECTOR& GXMVECTOR;
typedef const DirectX::XMVECTOR& HXMVECTOR;
typedef const DirectX::XMVECTOR& CXMVECTOR;
typedef const DirectX::XMMATRIX& FXMMATRIX;
typedef const DirectX::XMMATRIX& CXMMATRIX;


////////////////////////////////////////////////////////////////////////////////
// Class name: ColorShaderClass
////////////////////////////////////////////////////////////////////////////////
class ColorShaderClass
{
private:
	struct MatrixBufferType
	{
		DirectX::XMMATRIX world;
		DirectX::XMMATRIX view;
		DirectX::XMMATRIX projection;
	};

public:
	ColorShaderClass();
	ColorShaderClass(const ColorShaderClass&);
	~ColorShaderClass();
	
	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	bool XM_CALLCONV Render(ID3D11DeviceContext*, int, DirectX::CXMMATRIX, DirectX::CXMMATRIX, DirectX::CXMMATRIX);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool XM_CALLCONV SetShaderParameters(ID3D11DeviceContext*, DirectX::CXMMATRIX, DirectX::CXMMATRIX, DirectX::CXMMATRIX);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
};

#endif

