#pragma once
#include "xvideoview.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
class XSDL :public XVideoView {
public:
	bool Init(int w, int h, Format fmt = XVideoView::Format::RGBA) override;

	bool Draw(const unsigned char* data, int linesize = 0) override;
	bool Draw(const unsigned char* y, int y_picth,
		const unsigned char* u, int u_picth,
		const unsigned char* v, int v_picth) override;

	void Close() override;
	bool IsExit() override;
private:
	SDL_Window* win_;
	SDL_Renderer* render_;
	SDL_Texture* texture_;
};

