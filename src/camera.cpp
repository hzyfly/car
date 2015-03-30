#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
int main(int argc,char **argv)
{
	IplImage* frame;
	IplImage* out;
	cvNamedWindow("origial",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("canny,CV_WINDOW_AUTOSIZE");
	CvCapture* capture=cvCreateCameraCapture(0);
	while(1)
	{
		frame=cvQueryFrame(capture);
		IplImage* out=cvCreateImage(cvSize(frame->width,frame-> height),IPL_DEPTH_8U,1);
		 cvCanny(frame,out,10,100,3);
		if(!frame) break;
		cvShowImage("original",frame);
		cvShowImage("canny",out);
		char c=cvWaitKey(33);
		if(c==27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("original");
}
