#pragma once

#include <Siv3D.hpp>
#include "Window.hpp"


namespace s3d
{

	namespace WindowSelector {

		// �^�C�g������E�B���h�E���擾���܂��B
		inline windows::Window FromTitle(const s3d::String &title)
		{
			const WindowHandle handle = ::FindWindowW(nullptr, title.c_str());
			
			return windows::Window(handle);
		}

		// �N���X������E�B���h�E���擾���܂��B
		inline windows::Window FromClassName(const s3d::String &className)
		{
			const WindowHandle handle = ::FindWindowW(className.c_str(), nullptr);

			return windows::Window(handle);
		}



	}
}
