#pragma once

#include <Siv3D.hpp>

#include "Windows.hpp"


namespace Display {

	// ディスプレイの解像度を取得します。
	inline s3d::Size Size() {

		const auto x = ::GetSystemMetrics(SM_CXSCREEN);
		const auto y = ::GetSystemMetrics(SM_CYSCREEN);

		return s3d::Size(x, y);

	}

}

