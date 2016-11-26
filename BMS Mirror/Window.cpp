#include "Window.hpp"


constexpr inline s3d::Color UInt32ToColor(const uint32 value) {
	return Color(GetBValue(value), GetGValue(value), GetRValue(value));
}



void windows::Window::print(Image &image) const
{
	
	const auto w = this->size.x;
	const auto h = this->size.y;

	const auto headerSize = sizeof(Bitmap::FileHeader) + sizeof(Bitmap::Info);

	const auto imageSize = w * h * 4;

	// Bitmap の情報を構築する

	Bitmap::FileHeader bmpHead = { 0 };
	bmpHead.bfType = Bitmap::BM;
	bmpHead.bfSize = headerSize + imageSize;
	bmpHead.bfReserved1 = 0;
	bmpHead.bfReserved2 = 0;
	bmpHead.bfOffBits = headerSize;


	Bitmap::InfoHeader infoHeader = { 0 };
	infoHeader.biSize = sizeof(Bitmap::InfoHeader);
	infoHeader.biWidth = w;
	infoHeader.biHeight = h;
	infoHeader.biPlanes = 1;
	infoHeader.biBitCount = 32;
	infoHeader.biCompression = BI_RGB;
	infoHeader.biSizeImage = 0;
	infoHeader.biXPelsPerMeter = 0;
	infoHeader.biYPelsPerMeter = 0;
	infoHeader.biClrUsed = 0;
	infoHeader.biClrImportant = 0;


	Bitmap::Info info = { 0 };
	info.bmiHeader = infoHeader;


	// 色情報
	uint32 *pixel = nullptr;


	const auto bitmap = ::CreateDIBSection(
		0,
		&info,
		DIB_RGB_COLORS,
		reinterpret_cast<void **>(&pixel),
		0,
		0);

	auto deviceContext = this->deviceContextHandle;

	// 保存用の HDC を作る
	auto captureDeviceContext = ::CreateCompatibleDC(this->deviceContextHandle);

	// キャプチャ
	::SelectObject(captureDeviceContext, bitmap);
	BitBlt(captureDeviceContext, 0, 0, w, h, deviceContext, 0, 0, SRCCOPY);


	// 速度的につらい処理
	for (int x = 0; x < w; ++x)
	{
		for (int y = 0; y < h; ++y)
		{

			const auto pos = y * w + x;

			uint32 value = *(pixel + pos);

			image[h - y][x] = UInt32ToColor(value);

		}
	}


	::DeleteDC(captureDeviceContext);
	::DeleteObject(bitmap);

}
