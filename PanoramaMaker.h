#pragma once
#include <iostream>
#include <memory>
#include "use_opencv.h"
#include "MoravecFeatureExtractor.h"
#include "HOGDescriptorExtractor.h"
#include "Matcher.h"

namespace visionNoob
{
	namespace computerVision
	{
		namespace apps
		{
			class PanoramaMaker
			{
			public:
				PanoramaMaker();
				~PanoramaMaker();

			public:
				void getPanoramaImage(cv::OutputArray dst);
				void getMatchingImage(cv::OutputArray dst);
				void getPostProcessedPanoramaImage(cv::OutputArray dst);

				void setImages(cv::InputArray _src1, cv::InputArray _src2);
				void setImages(std::string src1_path, std::string src2_path);
				void compute();

			private:
				void detectKeypoints(bool useOpenCVFunction, bool printLog);
				void calcDescriptors(bool useOpenCVFunction, bool printLog);
				void matchDescriptors(bool useOpenCVFunction, bool printLog);
				void refineMatches(bool printLog);
				void findHomography(bool useOpenCVFunction, bool printLog);
				void stitchImages();
				void postProcess();
				
			private:
				cv::Mat src1;
				cv::Mat src2;
				cv::Mat src1_gray;
				cv::Mat src2_gray;
				cv::Mat panoramaResult;
				cv::Mat panoramaBinaryMask;
				cv::Mat postProcessedResult;

				cv::Mat descriptor1, descriptor2;
				cv::Mat homography;

				std::vector<cv::KeyPoint> keypoints1, keypoints2;
				std::vector<cv::DMatch> matches;
			};
		}
	}
}


