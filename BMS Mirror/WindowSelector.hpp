#pragma once

#include <Siv3D.hpp>
#include "Window.hpp"


namespace s3d
{

	namespace WindowSelector {

		// タイトルからウィンドウを取得します。
		inline windows::Window FromTitle(const s3d::String &title)
		{
			const WindowHandle handle = ::FindWindowW(nullptr, title.c_str());
			
			return windows::Window(handle);
		}

		// クラス名からウィンドウを取得します。
		inline windows::Window FromClassName(const s3d::String &className)
		{
			const WindowHandle handle = ::FindWindowW(className.c_str(), nullptr);

			return windows::Window(handle);
		}



	}
}
