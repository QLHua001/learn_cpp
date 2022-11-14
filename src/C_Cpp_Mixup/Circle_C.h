#ifndef CIRCLE_C_H
#define CIRCLE_C_H

#ifdef __cplusplus
extern "C" {
#endif

void* Circle_C_New(float radius);
void Circle_C_Delete(void* circle);
float Circle_C_GetArea(void* circle);

#ifdef __cplusplus
}
#endif

#endif