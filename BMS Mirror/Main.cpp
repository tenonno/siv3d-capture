
# include <Siv3D.hpp>

#include "Display.hpp"
#include "WindowSelector.hpp"
#include "WindowLayer.hpp"


void Main()
{

	Window::Resize(1280, 720);

	Image image(Display::Size());

	DynamicTexture texture(image);


	Window::SetLayer(WindowLayer::TopMost);
	Graphics::SetVSyncEnabled(false);

	GUI gui(GUIStyle::Default);
	gui.setTitle(L"window title");
	gui.add(L"title", GUITextField::Create(20));
	gui.textField(L"title").setText(L"Siv3D App");


	while (System::Update())
	{

		ClearPrint();
		
	
		auto window = WindowSelector::FromTitle(gui.textField(L"title").text);


		// 自分を撮っているなら背景色を変更する
		if (window.handle == Window::GetHandle()) {
			Graphics::SetBackground(HSV(System::FrameCount() * 10.0, 1.0, 0.8));
		}


		if (!window) continue;


		window.print(image);
		texture.fill(image);


		texture(window.clientRect).scale(0.9).drawAt(Window::Center());


	}

}
