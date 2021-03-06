#include <iostream>

#include "Point.hpp"
#include "skelxut.hpp"

using namespace std;
using namespace cv;

static double sigmaHat = 0.0;
static double preSigmaHat = sigmaHat;

static int countTimes = 0;   // count if sigmaHat remains unchanged
static int t = 0;   // count for iterations
static int k = 22;   // k nearest neighbors

Mat contract(Mat img, string filename, const double detailFactor, const bool perturbationFlag){
    // k = skelx::computeK(img);  // compute k
    // k = 22;
    // minRadius = skelx::computeMinimumSearchRadius(k);
    // cout << "k = " << k << endl;

    while(true){
        vector<skelx::Point> pointset = skelx::getPointsetInitialized(img);
        skelx::computeUi(img, pointset, k, perturbationFlag);
        skelx::PCA(img, pointset, detailFactor);
        // skelx::visualize(img, pointset, t);
        skelx::movePoint(pointset);
        // imwrite("results/" + to_string(t) + ".png", img);
        img = skelx::draw(img, pointset);
        // skelx::cleanImage(img);

        for(skelx::Point &p : pointset) sigmaHat += p.sigma;
        sigmaHat /= pointset.size();

        ++t;
        // std::cout << "iter:" << t << "   sigmaHat = " << sigmaHat << endl;
        // check if sigmaHat remains unchanged
        // if it doesn't change for 3 times, go to postprocessing
        if(sigmaHat == preSigmaHat){
            if(countTimes == 2) {
                // imwrite("results/0_extracted_" + filename + "_" + to_string(static_cast<int>(detailFactor)) + ".png", img);
                vector<skelx::Point> pointset = skelx::getPointsetInitialized(img);
                skelx::computeUi(img, pointset, k, perturbationFlag);
                skelx::PCA(img, pointset, detailFactor);
                return skelx::postProcess(img, pointset);
            }
            else ++countTimes;
        }else{
            preSigmaHat = sigmaHat;
            countTimes = 0;
        }
    }
}