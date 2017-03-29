//
// Created by 34721 on 2017/3/17.
//

#ifndef FACERECOGNITION_FACE_DETECT_CPP
#define FACERECOGNITION_FACE_DETECT_CPP

#include "com_niu_flvthumbnail_FlvUtil.h"
#include <jni.h>
#include <string>
#include <stdlib.h>
#include <opencv/cv.h>

using namespace std;
using namespace cv;

JNIEXPORT jintArray JNICALL Java_com_niu_flvthumbnail_FlvUtil_getFlvImage(JNIEnv *, jobject, jstring, jstring) {


    cv::VideoCapture capture
//    CvCapture* capture = cvCaptureFromAVI("C:\\me.avi");
    int i = 0;
    IplImage* img = 0;
    char image_name[25];
    cvNamedWindow( "dd");
    //读取和显示
    while(1)
    {
        img = cvQueryFrame(capture); //获取一帧图片
        if(img == NULL)
            break;

        cvShowImage( "vivi", img ); //将其显示
        char key = cvWaitKey(20);
        sprintf(image_name, "%s%d%s", "..\\tutu\\image", ++i, ".jpg");//保存的图片名
        cvSaveImage( image_name, img);   //保存一帧图片
    }

    cvReleaseCapture(&capture);
    cvDestroyWindow("dd");

    return 0;
}


