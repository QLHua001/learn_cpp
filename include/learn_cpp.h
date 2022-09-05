#pragma once
#include <vector>
#include <opencv2/opencv.hpp>

struct Object{
    cv::Rect_<float> rect;
    float prob;
    int label;
};

void memory_storage();

void const_test();

void nms_sorted_bboxes(const std::vector<Object>& sorted_boxes, std::vector<int>& picked, float nms_threshold);