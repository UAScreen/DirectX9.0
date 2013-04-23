#include "stdafx.h"
#include "D3DObject.h"

using namespace System::Windows::Forms;
D3DObject g_D3D;

D3DObject::D3DObject(void)
{
	g_hinst  = GetModuleHandle (0);
	DistanceTraveled = 0;
	
}

D3DObject::~D3DObject(void)
{
	 UnregisterClass( L"D3D Tutorial", wc.hInstance );
}

bool D3DObject::InitD3D()
{
	if(hWnd == NULL)
    return false;


  pD3D = Direct3DCreate9(D3D_SDK_VERSION);

  if(pD3D == NULL)
    return false;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp, sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

   
    if( FAILED( pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &pDevice ) ) )
    {
        return false;
    }

	 pDevice->GetBackBuffer(NULL, NULL, D3DBACKBUFFER_TYPE_MONO, &BackBuffer);
	 if(BackBuffer == NULL) return false;
		 

	 D3DXIMAGE_INFO Info;

	 std::wstring path =L"textures\\1.png";
	 

	 if (FAILED(D3DXGetImageInfoFromFile(path.c_str(), &Info)))
    {
		return false;
        
       
    } 
	 Info.Format = D3DFORMAT::D3DFMT_X8R8G8B8;
		pDevice -> CreateOffscreenPlainSurface(Info.Width, Info.Height, Info.Format, D3DPOOL_SYSTEMMEM, &CurrentMainSurface, NULL);
	 //pDevice -> CreateOffscreenPlainSurface(800, 600, Info.Format, D3DPOOL_SYSTEMMEM, &CurrentMainSurface, NULL);
		D3DXLoadSurfaceFromFile(CurrentMainSurface, NULL, NULL, path.c_str(), NULL, D3DX_FILTER_NONE, 0, NULL);
	RenewSurface = true;

	map_Ground = new Map_Ground(1,50,pDevice);
	
	map_Ground->Load();
	
	if( !map_Ground->LoadTexture(L"textures\\wall-brick.png"))
	{
		return false;
	}
	mario = new Mario(pDevice);
	mario->LoadTexture();
    return true;
}

void D3DObject::CleanupD3D()
{
 
  if(pD3D!=NULL)
    pD3D->Release();
   /* if(pDevice!=NULL)
    pDevice->Release();*/
}

VOID D3DObject::Render()
{
    if( NULL == pDevice )
        return;

    
	pDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 10, 10, 10 ), 1.0f, 0 );
	BackBuffer->Release();
	
  

	pDevice->SetRenderState(D3DRS_ZENABLE,D3DZB_FALSE); 
	if( SUCCEEDED( pDevice->BeginScene() ) )
    {
		if(RenewSurface)	
			pDevice->UpdateSurface(CurrentMainSurface, NULL, BackBuffer, NULL);

		// рендер карти (землі)
        pDevice->SetTexture( 0, map_Ground->Texture() );
		pDevice->SetTextureStageState( 0, D3DTSS_COLOROP, D3DTOP_MODULATE );
        pDevice->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
        pDevice->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
		
		pDevice->SetStreamSource(0, map_Ground->mapVertexBuffer(), 0, sizeof(D3DVERTEX));
		   pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1);
		   pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, map_Ground->VerticesCount());
		

		// рендер Mario
		pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE);
		pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
		pDevice->SetTexture( 0, mario->Texture() );
		pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_BLENDTEXTUREALPHA);
		
		pDevice->SetStreamSource(0, mario->VertexBuffer(), 0, sizeof(D3DVERTEX));
		pDevice->SetFVF(D3DFVF_XYZRHW|D3DFVF_DIFFUSE | D3DFVF_TEX1);
		pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, mario->VerticesCount());

        pDevice->EndScene();
    }
	
    pDevice->Present( NULL, NULL, NULL, NULL );
	RenewSurface = false;
}

void D3DObject::ProcessKeyPressed()
{
	static float x=0;
	static float y=0;

	float x_change = 0;
	float y_change = 0;
	


 	char     buffer[256]; 
	
	float change = 10;
 
	byte keys[255];

		
		GetKeyboardState( keys);
		
	if(keys[(int)Keys::D] > 50 || keys[(int)Keys::A] >50 || keys[(int)Keys::W] >50 || keys[(int)Keys::Right] >50 || keys[(int)Keys::Left] >50 || keys[(int)Keys::Up] >50 )
	{
			
				if( keys[(int)Keys::D] >50 || keys[(int)Keys::Right] >50 )
			   {
				  x_change = 1;
				  mario->TurnRight();
			   }
				else
			   if( keys[(int)Keys::A] > 50 || keys[(int)Keys::Left]>50  )
			   {
				  x_change =- 1;
				   mario->TurnLeft();
			   }
			   else x_change=0;

			  
			   if (keys[(int)Keys::W] > 50 || keys[(int)Keys::Up] >50 || keys[(int)Keys::Space] >50   ) 
				{
					if(g_D3D.mario->Jumping == false)
					{
						g_D3D.mario->Jump();
						
					}
				}
			
				g_D3D.DistanceTraveled+= x_change*change;
				
	}
				
			  map_Ground->CreateVerticesArray(DistanceTraveled);
			  map_Ground->Draw();
			  mario->UpdateSpeed();
			  mario->UpdatePosition();
			  mario->CreateVertices();
			  mario->Draw();

	
}