#include<iostream>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
 void sigmafilter(Mat &,int,int);
 Mat img=imread("/home/jeenal/Pictures/testeagle.jpg",CV_LOAD_IMAGE_UNCHANGED);
 if(img.empty())
{
 cout<<"no image";
 return 0;
}
 cout<<"all ok";
 sigmafilter(img,60,5);
 namedWindow("filtered image",CV_WINDOW_AUTOSIZE);
 imshow("filtered image",img);

 waitKey(0);
 return 0;
}


void sigmafilter(Mat &img,int sigma,int kernel_size)
{
 
 int rows=img.rows;
 int cols=img.cols;
 
 int midPixel=0, anyPixel=0 , sum=0 , no=0 , x=0 , x2=0 , x3=0 , y=0 , y2=0 , y3=0;
 for (int y=0; y<rows ;y++)  
    for (int x=0; x<cols;x++)   
        {
         midPixel = img.at<uchar>(y,x);   
         sum = 0; no = 0;
         for (int y2=-1*floor(kernel_size/2); y2 <= floor(kernel_size/2);y2++)
              {
               y3 = y + y2;
               if  (y3 >= 0 && y3 < rows) 
                 for (int x2=-floor(kernel_size/2); x2 <= floor(kernel_size/2);x2++)
                     {
                       x3 = x2 + x;
                       if ( x3 >= 0 && x3<cols )
                           {
                            anyPixel = img.at<uchar>(y3,x3);
                            if ( abs(midPixel-anyPixel) < sigma)
                                {sum += anyPixel; no++;}
                             
                           }
                     
                     }
               }
          if ( no > 0 ) 
             img.at<uchar>(y,x) = sum/no;
          else   img.at<uchar>(y,x) = midPixel; 
         
       }
 

       
  
}
