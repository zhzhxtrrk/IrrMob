#include "demo.h"

#include <irrlicht.h>

static void _irrPostTouchEvent(IrrlichtDevice* device, int type, int index, int x, int y);

// #define _IRR_COMPILE_WITH_ANDROID_DEVICE_
#ifdef _IRR_COMPILE_WITH_ANDROID_DEVICE_

#include <android/log.h>
#define  LOG_TAG    "libGame"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#include <jni.h>

IrrlichtDevice* device;
MyScene* myScene;

const char* sdpath;

extern "C" {
  JNIEXPORT
  void JNICALL Java_com_moqikaka_hello_HelloActivity_irrInit(JNIEnv *,
                                                             jclass, jint, jint, jstring);
  JNIEXPORT
  void JNICALL Java_com_moqikaka_hello_HelloActivity_irrUninit(JNIEnv *,
                                                               jclass);
  JNIEXPORT
  void JNICALL Java_com_moqikaka_hello_HelloActivity_irrResize(JNIEnv *,
                                                               jclass, jint, jint);
  JNIEXPORT
  void JNICALL Java_com_moqikaka_hello_HelloActivity_irrRenderFrame(
                                                                    JNIEnv *, jclass);
  JNIEXPORT
  void JNICALL Java_com_moqikaka_hello_HelloActivity_irrPostTouchEvent(
                                                                       JNIEnv*, jclass, jint, jint, jint, jint);
}

JNIEXPORT
void JNICALL Java_com_moqikaka_hello_HelloActivity_irrInit(
                                                           JNIEnv* env, jclass klass, jint width, jint height, jstring path) {
  sdpath = env->GetStringUTFChars(path, NULL);

  device = createDevice(video::EDT_OGLES1, dimension2du(width, height), 32,
                        false, false, false, 0);
  myScene = new MyScene(device);
}

JNIEXPORT
void JNICALL Java_com_moqikaka_hello_HelloActivity_irrUninit(
                                                             JNIEnv* env, jclass klass) {
  myScene->drop();
  device->drop();
}

JNIEXPORT
void JNICALL Java_com_moqikaka_hello_HelloActivity_irrRenderFrame(
                                                                  JNIEnv* env, jclass klass) {
  device->run();
  device->getVideoDriver()->beginScene(true, true, SColor(255, 255, 0, 0));
  myScene->run();
  device->getVideoDriver()->endScene();
}

JNIEXPORT
void JNICALL Java_com_moqikaka_hello_HelloActivity_irrResize(
                                                             JNIEnv* env, jclass klass, jint width, jint height) {
  device->getVideoDriver()->OnResize(dimension2du(width, height));
}

JNIEXPORT
void JNICALL Java_com_moqikaka_hello_HelloActivity_irrPostTouchEvent(
                                                                     JNIEnv* env, jclass klass, jint type, jint index, jint x, jint y) {
  _irrPostTouchEvent(device, type, index, x, y);

  LOGI("PostEvent!");
}

#elif defined(_IRR_COMPILE_WITH_IPHONE_DEVICE_)

IrrlichtDevice* gDevice;
MyScene* gScene;

extern "C" void initGame(void* window, int w, int h)
{
    SIrrlichtCreationParameters params;
    params.WindowId = window;
    params.WindowSize = dimension2du(w, h);
    params.DriverType = EDT_OGLES1;
    params.WithAlphaChannel = true;
    params.Stencilbuffer = false;
    params.Bits = 24;
    params.Vsync = false;
    
    gDevice = createDeviceEx(params);
    gScene = new MyScene(gDevice);
}

extern "C" void updateFrame()
{
    gDevice->run();
    gDevice->getVideoDriver()->beginScene(true, true, SColor(0, 255, 0, 0));
    gScene->run();
    gDevice->getVideoDriver()->endScene();
}

extern "C" void touchEvent(int type, int x, int y)
{
    _irrPostTouchEvent(gDevice, type, 0, x, y);
}

#else

int main(int argc, char** argv) {
  IrrlichtDevice* device = NULL;
  device = createDevice(EDT_OPENGL, // driver type
                        dimension2du(800, 600), // size
                        24, false, false, false,// color, shadow, fullscreen, aa
                        0);                     // event listener

  MyScene* scene = new MyScene(device);

  while (device->run()) {
    device->getVideoDriver()->beginScene(true, true, SColor(0, 0, 0, 0));
    scene->run();
    device->getVideoDriver()->endScene();
  }

  scene->drop();
  device->drop();

  return 0;
}

#endif

static void _irrPostTouchEvent(IrrlichtDevice* device, int type, int index, int x, int y) {
    SEvent ev;
    ev.EventType = EET_MOUSE_INPUT_EVENT;
    
    if (type == 1) {
        ev.MouseInput.Event = EMIE_LMOUSE_PRESSED_DOWN;
        ev.MouseInput.ButtonStates = EMBSM_LEFT;
    } else if (type == 2) {
        ev.MouseInput.Event = EMIE_MOUSE_MOVED;
        ev.MouseInput.ButtonStates = EMBSM_LEFT;
    } else {
        ev.MouseInput.Event = EMIE_LMOUSE_LEFT_UP;
        ev.MouseInput.ButtonStates = 0x00000000;
    }
    
    ev.MouseInput.X = x;
    ev.MouseInput.Y = y;
    
    device->postEventFromUser(ev);
}