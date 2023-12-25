#pragma once
#include <MinHook.h>
#include <Windows.h>
#include <iostream>
#include <d3d11.h>
#include <dxgi.h>
#pragma comment(lib, "minhook.x64.lib") //Connecting MinHook Library :D
#pragma comment(lib, "d3d11.lib")
typedef uintptr_t PTR;
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;
HWND window = NULL;
WNDPROC oWndProc;

namespace D3D11Wrapper {
	Present oPresent; //Hooking Original Present :D
}