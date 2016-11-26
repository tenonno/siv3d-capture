#pragma once

#define NOMINMAX
#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#undef MessageBox


namespace windows
{

	namespace Bitmap
	{

		using FileHeader = ::BITMAPFILEHEADER;
		using Info = ::BITMAPINFO;
		using InfoHeader = ::BITMAPINFOHEADER;

		// ビットマップのファイルタイプ
		const uint16 BM = 0x4d42;

	}


}