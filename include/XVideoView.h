#pragma once
#include<mutex>
#include<fstream>

void MSleep(unsigned int ms);

//获取当前时间戳  ms
long long NowMs();

struct AVFrame;
class XVideoView {
public:
	enum Format {
		YUV420P = 0,
		ARGB = 25,
		RGBA = 26,
		BGRA = 28
	};
	enum RenderType {
		SDL = 0
	};
	static XVideoView* Create(RenderType type = RenderType::SDL);
	/*init渲染窗口
	* @para w 窗口宽度
	* @para h 窗口高度
	* @para fmt 绘制的像素格式
	* @para win_id 窗口句柄，若为nullptr则创建新窗口*/
	virtual bool Init(int w, int h, Format fmt = XVideoView::Format::RGBA) = 0;

	/*@para data 渲染的二进制数据
	* linesize 一行数据的字节数，对于YUV420P就是Y一行字节数
	* linesiuze<=0 就根据宽度和像素格式自动算出大小*/
	virtual bool Draw(const unsigned char* data, int linesize = 0) = 0;
	virtual bool Draw(const unsigned char* y, int y_picth,
		const unsigned char* u, int u_picth,
		const unsigned char* v, int v_picth) = 0;

	//清理所有申请的资源 包括窗口
	virtual void Close() = 0;

	//处理窗口退出事件
	virtual bool IsExit() = 0;

	//显示缩放
	void Scale(int w, int h) {
		scale_w_ = w;
		scale_h_ = h;
	}

	bool DrawFrame(AVFrame* frame);

	int render_fps() { return render_fps_; }

	//打开文件
	bool Open(std::string filepath);

	/*
	* 读取一帧数据，并维护AVFrame空间
	  每次调用会覆盖上一次数据*/
	AVFrame* Read();

	void set_win_id(void* win) { win_id_ = win; }
private:
	std::ifstream ifs_;
	AVFrame* frame_ = nullptr;
protected:
	void* win_id_ = nullptr;						//窗口句柄
	int render_fps_ = 0;							//帧率显示
	int width_ = 0;									//材质宽高
	int height_ = 0;
	Format fmt_ = RGBA;								//像素格式
	std::mutex mtx_;
	int scale_w_ = 0;								//显示大小
	int scale_h_ = 0;
	long long beg_ms_ = 0;							//计时开始时间
	int count_ = 0;									//统计显示次数
};

