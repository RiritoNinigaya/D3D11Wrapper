#include "HookD3D11.hpp"
#pragma warning(suppress : 6387)
HRESULT __stdcall D3D11Wrapper::HookD3D11::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer{ 0 };
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView); //False Positive Warning DirectX 11 SDK
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			init = true;
		}
		else
			return oPresent(pSwapChain, SyncInterval, Flags);
		/*
		You're Internal IMGUI Menu Src Code
		*/
		return oPresent(pSwapChain, SyncInterval, Flags);
	}
}
	
		
