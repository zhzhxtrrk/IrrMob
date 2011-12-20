#include "demo.h"

extern const char* sdpath;

MyScene::MyScene(IrrlichtDevice* device) {
    this->device = device;
    sceneManager = device->getSceneManager();
    guienv = device->getGUIEnvironment();
    driver = device->getVideoDriver();
    
    createScene();
    device->setEventReceiver(this);
}

MyScene::~MyScene() {
	sceneManager->clear();
	guienv->clear();
}

void MyScene::createScene() {
    device->getFileSystem()->addFileArchive("/Users/zhzhxtrrk/Desktop/tmp/");
    sceneManager->loadScene("Scene.irr");
    
    ISceneNode* node = sceneManager->getSceneNodeFromName("Plane");
    if (node)
    {
        SMaterial& mat = node->getMaterial(0);
        mat.TextureLayer[0].getTextureMatrix().setScale(vector3df(1, 1, 1));
    }
}

void MyScene::run() {
	sceneManager->drawAll();
	guienv->drawAll();
}

bool MyScene::OnEvent(const SEvent& event)
{
	if (event.EventType == EET_KEY_INPUT_EVENT) {
		switch (event.KeyInput.Key) {
            case KEY_ESCAPE:
                device->closeDevice();
                break;
		}
	}
    
	return false;
}
