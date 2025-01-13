#pragma once
#include<mutex>
#include<fstream>

void MSleep(unsigned int ms);

//��ȡ��ǰʱ���  ms
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
	/*init��Ⱦ����
	* @para w ���ڿ��
	* @para h ���ڸ߶�
	* @para fmt ���Ƶ����ظ�ʽ
	* @para win_id ���ھ������Ϊnullptr�򴴽��´���*/
	virtual bool Init(int w, int h, Format fmt = XVideoView::Format::RGBA) = 0;

	/*@para data ��Ⱦ�Ķ���������
	* linesize һ�����ݵ��ֽ���������YUV420P����Yһ���ֽ���
	* linesiuze<=0 �͸��ݿ�Ⱥ����ظ�ʽ�Զ������С*/
	virtual bool Draw(const unsigned char* data, int linesize = 0) = 0;
	virtual bool Draw(const unsigned char* y, int y_picth,
		const unsigned char* u, int u_picth,
		const unsigned char* v, int v_picth) = 0;

	//���������������Դ ��������
	virtual void Close() = 0;

	//�������˳��¼�
	virtual bool IsExit() = 0;

	//��ʾ����
	void Scale(int w, int h) {
		scale_w_ = w;
		scale_h_ = h;
	}

	bool DrawFrame(AVFrame* frame);

	int render_fps() { return render_fps_; }

	//���ļ�
	bool Open(std::string filepath);

	/*
	* ��ȡһ֡���ݣ���ά��AVFrame�ռ�
	  ÿ�ε��ûḲ����һ������*/
	AVFrame* Read();

	void set_win_id(void* win) { win_id_ = win; }
private:
	std::ifstream ifs_;
	AVFrame* frame_ = nullptr;
protected:
	void* win_id_ = nullptr;						//���ھ��
	int render_fps_ = 0;							//֡����ʾ
	int width_ = 0;									//���ʿ��
	int height_ = 0;
	Format fmt_ = RGBA;								//���ظ�ʽ
	std::mutex mtx_;
	int scale_w_ = 0;								//��ʾ��С
	int scale_h_ = 0;
	long long beg_ms_ = 0;							//��ʱ��ʼʱ��
	int count_ = 0;									//ͳ����ʾ����
};

