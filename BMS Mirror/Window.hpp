#pragma once


#include <Siv3D.hpp>
#include "WindowHandle.hpp"



namespace windows {


	class Window {

		WindowHandle _handle;
		DeviceContextHandle _deviceContextHandle;


	public:

		Window(const WindowHandle handle) : _handle(handle) {
			this->_deviceContextHandle = ::GetWindowDC(handle);
		}

		~Window() {
			::ReleaseDC(this->handle, this->deviceContextHandle);
		}

		explicit operator bool() const noexcept
		{
			return this->handle != nullptr;
		}


		// ウィンドウをイメージに描き込みます。
		void print(Image &image) const;

		
		// ウィンドウハンドル
		Property_Get(WindowHandle, handle) const {
			return this->_handle;
		}

		// ウィンドウの大きさ
		Property_Get(Size, size) const {
			::RECT rect;
			::GetWindowRect(this->handle, &rect);
			return Size(rect.right - rect.left, rect.bottom - rect.top);
		};

		
		// デバイスコンテキストハンドル
		Property_Get(DeviceContextHandle, deviceContextHandle) const {
			return this->_deviceContextHandle;
		};


		// スクリーン上の領域
		Property_Get(Rect, screenRect) const {
			RECT rect;
			::GetWindowRect(this->handle, &rect);
			return Rect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.left);
		};


		// クライアント領域
		Property_Get(Rect, clientRect) const {

			// 相対的なクライアント領域を取得する手段はない？
			// スクリーン上の領域の差分から計算する

			::RECT rect;
			::GetWindowRect(this->handle, &rect);

			::POINT point;
			point.x = rect.left;
			point.y = rect.top;
			::ScreenToClient(this->handle, &point);

			return Rect(-point.x, -point.y, this->clientSize);

		};


		// クライアント領域の大きさ
		Property_Get(Size, clientSize) const {
			::RECT rect;
			::GetClientRect(this->handle, &rect);
			return Size(rect.right - rect.left, rect.bottom - rect.top);
		};

	};

}

