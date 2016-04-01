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
    //resize(gray,gray,size);
    imshow("resized",gray);
    string output;

    vector<Rect>   boxes;
    vector<string> words;
    vector<float>  confidences;
    Ptr<OCRTesseract> ocr = OCRTesseract::create();
    ocr->run(gray, output, &boxes, &words, &confidences, OCR_LEVEL_WORD);
    Scalar color=Scalar(255,0,0);
    for (int i=0;i<boxes.size();i++)
    {

      rectangle(img, boxes[i].tl(), boxes[i].br(), color, 2, 8, 0 );
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
    cout << output <<endl;
    imshow("Original Image",img);
    waitKey(0);
    return 0;
}
