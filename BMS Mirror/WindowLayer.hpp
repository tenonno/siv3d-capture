#pragma once


#include "Window.hpp"

namespace s3d
{

	enum class WindowLayer
	{
		Top = 0,
		Bottom = 1,
		TopMost = -1,
		NoTopMost = -2
	};


	namespace Window
	{

		// ウィンドウハンドルを取得します。
		inline WindowHandle GetHandle()
		{
			return ::FindWindowW(nullptr, Window::GetTitle().c_str());
		}


		// ウィンドウのレイヤーを指定します。
		inline void SetLayer(WindowLayer layer)
		{

			::SetWindowPos(
				Window::GetHandle(),
				reinterpret_cast<WindowHandle>(layer),
				0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

		}


	}

}