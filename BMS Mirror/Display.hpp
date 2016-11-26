#pragma once

#include <Siv3D.hpp>

#include "Windows.hpp"


namespace Display {

	// �f�B�X�v���C�̉𑜓x���擾���܂��B
	inline s3d::Size Size() {

		const auto x = ::GetSystemMetrics(SM_CXSCREEN);
		const auto y = ::GetSystemMetrics(SM_CYSCREEN);

		return s3d::Size(x, y);

	}

}

