#pragma once
#include "../D3D11Wrapper/D3D11_WrapperIncludes.hpp"
bool init = false;
namespace D3D11Wrapper {
	namespace HookD3D11 {
		HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	}
}