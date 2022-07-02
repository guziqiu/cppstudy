#include <iostream>
using namespace std;

class Televison {
public:
	void On() {
		cout << "电视打开..." << endl;
	}
	void Off() {
		cout << "电视机关闭..." << endl;
	}
};

class Light {
public:
	void On() {
		cout << "灯打开..." << endl;
	}
	void Off() {
		cout << "灯关闭..." << endl;
	}
};

class Audio {
public:
	void On() {
		cout << "音箱打开..." << endl;
	}
	void Off() {
		cout << "音箱关闭..." << endl;
	}
};

class Microphone {
public:
	void On() {
		cout << "麦克风打开..." << endl;
	}
	void Off() {
		cout << "麦克风关闭..." << endl;
	}
};

class DVDPlayer {
public:
	void On() {
		cout << "DVD打开..." << endl;
	}
	void Off() {
		cout << "DVD关闭..." << endl;
	}
};

class GameMachine {
public:
	void On() {
		cout << "游戏机打开..." << endl;
	}
	void Off() {
		cout << "游戏机关闭..." << endl;
	}
};

class KTVMode {
public:
	KTVMode() {
		pTv         = new Televison();
		pLight      = new Light();
		pAudio      = new Audio();
		pMicrophone = new Microphone();
		pDvd        = new DVDPlayer();
	}

	void OnKTV() {
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMicrophone->On();
		pDvd->On();
	}

	void OffKTV() {
		pTv->Off();
		pLight->Off();
		pAudio->Off();
		pMicrophone->Off();
		pDvd->Off();
	}

	~KTVMode() {
		delete pTv        ;
		delete pLight     ;
		delete pAudio     ;
		delete pMicrophone;
		delete pDvd       ;
	}
public:
	Televison  *pTv;
	Light      *pLight;
	Audio      *pAudio;
	Microphone *pMicrophone;
	DVDPlayer  *pDvd;
};

void test01() {
	KTVMode *ktv = new KTVMode();
	ktv->OnKTV();
}


int main() {
	test01();

	return 0;
}
