#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(){
    Mat img = imread("/Users/renyi/Documents/Postgraduate/Codes/SkeletonExtraction/dataset/GT/background/256x256/guitar.png", IMREAD_GRAYSCALE);
    for(int i = 1; i < img.rows - 1; ++i){
        for(int j = 1; j < img.cols - 1; ++j){
            img.at<uchar>(i, j) = img.at<uchar>(i, j) < 30 ? 0 : 255;
        }
    }
    // Mat temp = img.clone();
    // for(int i = 1; i < img.rows - 1; ++i){
    //     for(int j = 1; j < img.cols - 1; ++j){
    //         int sum = 0;
    //         if(img.at<uchar>(i, j) == 0){
    //             sum += (img.at<uchar>(i - 1, j - 1) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i - 1, j) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i - 1, j + 1) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i, j + 1) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i + 1, j + 1) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i + 1, j) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i + 1, j - 1) == 255 ? 1 : 0);
    //             sum += (img.at<uchar>(i, j - 1) == 255 ? 1 : 0);
    //         }
    //         if(sum != 0){
    //             temp.at<uchar>(i, j) = 255;
    //         }
    //     }
    // }
    // img = temp.clone();

    imwrite("/Users/renyi/Documents/Postgraduate/Codes/SkeletonExtraction/dataset/GT/background/augmented/guitar.png", img);

    return 0;
}