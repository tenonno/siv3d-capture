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

		// �E�B���h�E�n���h�����擾���܂��B
		inline WindowHandle GetHandle()
		{
			return ::FindWindowW(nullptr, Window::GetTitle().c_str());
		}


		// �E�B���h�E�̃��C���[���w�肵�܂��B
		inline void SetLayer(WindowLayer layer)
		{

			::SetWindowPos(
				Window::GetHandle(),
				reinterpret_cast<WindowHandle>(layer),
				0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

		}


	}

}