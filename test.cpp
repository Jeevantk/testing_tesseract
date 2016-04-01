#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <iostream>
#include <opencv2/text.hpp>

using namespace cv;
using namespace std;
using namespace tesseract;
using namespace cv::text;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Please give the location of source sheet Music as ./test /path/to/MusicSheet" <<endl;
        return -1;
    }
    Mat img =imread(argv[1]);
    if (img.empty())
    {
        cout << "No Image found found at the given location,please try again" <<endl;
        return -1;
    }

    Mat gray;
    cvtColor(img, gray, CV_BGR2GRAY);
    Size size(img.cols*2,img.rows*2);
    resize(img,img,size);
    resize(gray,gray,size);
    //namedWindow("resized",WINDOW_NORMAL);
    //imshow("resized",gray);
    string output;

    vector<Rect>   boxes;
    vector<string> words;
    vector<float>  confidences;
    //NULL,NULL,"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY",3,3
    Ptr<OCRTesseract> ocr = OCRTesseract::create();
    //ocr.char_whitelist("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ocr->run(gray, output, &boxes, &words, &confidences, OCR_LEVEL_WORD);
    Scalar color=Scalar(255,0,0);
    for (int i=0;i<boxes.size();i++)
    {
      if (words[i].find_first_not_of(' ') != std::string::npos && confidences[i]>70.0)
      {
        imshow("individual Boxes",gray(boxes[i]));
        rectangle(img, boxes[i].tl(), boxes[i].br(),color, 2, 8, 0 );
        namedWindow("image",WINDOW_NORMAL);
        imshow("image",img);
        cout<<words[i]<<endl;
        cout<<confidences[i]<<endl;
        waitKey(0);
      }

      //rectangle(img, boxes[i].tl(), boxes[i].br(), color, 2, 8, 0 );
    }
    //threshold(gray,gray, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    /*TessBaseAPI ocr;
    ocr.Init(NULL, "eng",OEM_DEFAULT);
    ocr.SetPageSegMode(PSM_SINGLE_BLOCK);
    ocr.SetImage((uchar*)gray.data, gray.cols, gray.rows, 1, gray.cols);

    char* out = ocr.GetUTF8Text();

    cout << out << endl;
    */
    /*threshold(gray,gray, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    ocr.SetImage((uchar*)gray.data, gray.cols, gray.rows, 1, gray.cols);
    out = ocr.GetUTF8Text();
    cout << out << endl;*/
    //cout << output <<endl;
    imwrite("output2.jpg",img);
    waitKey(0);
    return 0;
}
