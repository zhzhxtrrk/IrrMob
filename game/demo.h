#ifndef DEMO_H_
#define DEMO_H_

#include <irrlicht.h>

#include <iostream>

using namespace std;

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class MyScene : virtual public IReferenceCounted, public IEventReceiver {
private:
	IrrlichtDevice* device;

	ISceneManager* sceneManager;
	IVideoDriver* driver;
	IGUIEnvironment* guienv;

public:
	MyScene(IrrlichtDevice* device);
	virtual ~MyScene();

	void createScene();
	void run();

    bool OnEvent(const SEvent& event);
};

#endif /* DEMO_H_ */
