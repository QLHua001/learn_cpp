#include <vector>
#include "learn_cpp.h"

static float intersection_area(const Object& obj1, const Object& obj2){
    cv::Rect_<float> inter_rect = obj1.rect & obj2.rect;
    return inter_rect.area();
}

void nms_sorted_bboxes(const std::vector<Object>& sorted_boxes, std::vector<int>& picked, float nms_threshold){
    picked.clear();

    const int count = sorted_boxes.size();

    std::vector<float> areas(count);
    for (size_t i = 0; i < count; i++)
    {
        areas[i] = sorted_boxes[i].rect.area();
    }
    

    for (size_t i = 0; i < count; i++)
    {
        const Object& obj1 = sorted_boxes[i];
        bool keep = true;
        for (size_t j = 0; j < picked.size(); j++)
        {
            const Object& obj2 = sorted_boxes[picked[j]];

            float inter_area = intersection_area(obj1, obj2);
            float union_area = areas[i] + areas[picked[j]] - inter_area;
            if((inter_area / union_area) > nms_threshold){
                keep = false;
            }

        }

        if(keep) picked.push_back(i);
        
    }
    
}