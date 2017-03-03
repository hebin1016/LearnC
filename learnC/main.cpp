//
//  main.cpp
//  learnC
//
//  Created by hebin on 2017/1/15.
//  Copyright © 2017年 hebin. All rights reserved.
//

#include "main.hpp"


#include "jni.h"

JNIEXPORT jstring JNICALL Java_com_test_getStringFromC(JNIEnv *env,jclass jcls){
    return env->NewStringUTF("test");
}
