#ifndef contracttt_hpp
#define contracttt_hpp

#include <string>
#include <opencv2/core.hpp>

cv::Mat contract(cv::Mat img, std::string filename, const double detailFactor = 10.0);

#endif