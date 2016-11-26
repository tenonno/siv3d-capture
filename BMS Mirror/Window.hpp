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


		// �E�B���h�E���C���[�W�ɕ`�����݂܂��B
		void print(Image &image) const;

		
		// �E�B���h�E�n���h��
		Property_Get(WindowHandle, handle) const {
			return this->_handle;
		}

		// �E�B���h�E�̑傫��
		Property_Get(Size, size) const {
			::RECT rect;
			::GetWindowRect(this->handle, &rect);
			return Size(rect.right - rect.left, rect.bottom - rect.top);
		};

		
		// �f�o�C�X�R���e�L�X�g�n���h��
		Property_Get(DeviceContextHandle, deviceContextHandle) const {
			return this->_deviceContextHandle;
		};


		// �X�N���[����̗̈�
		Property_Get(Rect, screenRect) const {
			RECT rect;
			::GetWindowRect(this->handle, &rect);
			return Rect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.left);
		};


		// �N���C�A���g�̈�
		Property_Get(Rect, clientRect) const {

			// ���ΓI�ȃN���C�A���g�̈���擾�����i�͂Ȃ��H
			// �X�N���[����̗̈�̍�������v�Z����

			::RECT rect;
			::GetWindowRect(this->handle, &rect);

			::POINT point;
			point.x = rect.left;
			point.y = rect.top;
			::ScreenToClient(this->handle, &point);

			return Rect(-point.x, -point.y, this->clientSize);

		};


		// �N���C�A���g�̈�̑傫��
		Property_Get(Size, clientSize) const {
			::RECT rect;
			::GetClientRect(this->handle, &rect);
			return Size(rect.right - rect.left, rect.bottom - rect.top);
		};

	};

}

