#ifndef SGL_SCOPE_H
#define SGL_SCOPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sgl_core.h>
#include <sgl_draw.h>
#include <sgl_math.h>
#include <sgl_log.h>
#include <sgl_mm.h>
#include <sgl_cfgfix.h>
#include <string.h>

// 示波器数据结构
#define SCOPE_DATA_SIZE 200

typedef struct {
    sgl_obj_t obj;
    uint16_t data[SCOPE_DATA_SIZE]; // 单通道数据
    sgl_color_t waveform_color;  // 波形颜色
    sgl_color_t bg_color;  // 背景色
    sgl_color_t grid_color; // 网格线颜色
    sgl_color_t border_color; // 边框颜色
    sgl_color_t outer_border_color; // 外边框颜色
    uint16_t min_value;    // 数据最小值
    uint16_t max_value;    // 数据最大值
    uint16_t running_min;  // 运行时最小值
    uint16_t running_max;  // 运行时最大值
    uint8_t auto_scale;    // 是否自动调整比例
    uint8_t line_width;    // 波形线条宽度
    uint8_t data_count;    // 已存储的数据点数量
    uint8_t max_display_points; // 最大显示点数
    uint8_t show_y_labels; // 是否显示Y轴标签
    uint8_t alpha;         // 示波器整体透明度
    uint8_t show_outer_border; // 是否显示外边框
    uint8_t grid_style;    // 网格线样式（0-实线，1-虚线）
    const sgl_font_t *y_label_font; // Y轴标签字体
    sgl_color_t y_label_color;     // Y轴标签颜色
    uint8_t current_index; // 当前数据索引
} sgl_scope_t;

// 创建示波器对象
sgl_obj_t* sgl_scope_create(sgl_obj_t* parent);

// 设置示波器数据点
void sgl_scope_set_data(sgl_obj_t* obj, uint16_t value);

// 获取示波器数据点
uint16_t sgl_scope_get_data(sgl_obj_t* obj, int index);

// 设置示波器最大显示点数
void sgl_scope_set_max_display_points(sgl_obj_t* obj, uint8_t max_points);

// 设置示波器波形颜色
void sgl_scope_set_waveform_color(sgl_obj_t* obj, sgl_color_t color);

// 设置示波器背景色
void sgl_scope_set_bg_color(sgl_obj_t* obj, sgl_color_t color);

// 设置示波器网格线颜色
void sgl_scope_set_grid_color(sgl_obj_t* obj, sgl_color_t color);

// 设置示波器显示范围
void sgl_scope_set_range(sgl_obj_t* obj, uint16_t min_value, uint16_t max_value);

// 设置示波器线条宽度
void sgl_scope_set_line_width(sgl_obj_t* obj, uint8_t width);

// 启用/禁用自动缩放
void sgl_scope_enable_auto_scale(sgl_obj_t* obj, uint8_t enable);

// 设置示波器透明度
void sgl_scope_set_alpha(sgl_obj_t* obj, uint8_t alpha);

// 设置是否显示Y轴标签
void sgl_scope_show_y_labels(sgl_obj_t* obj, uint8_t show);

// 设置Y轴标签字体
void sgl_scope_set_y_label_font(sgl_obj_t* obj, const sgl_font_t *font);

// 设置Y轴标签颜色
void sgl_scope_set_y_label_color(sgl_obj_t* obj, sgl_color_t color);

// 设置示波器边框颜色
void sgl_scope_set_border_color(sgl_obj_t* obj, sgl_color_t color);

// 设置示波器外边框颜色
void sgl_scope_set_outer_border_color(sgl_obj_t* obj, sgl_color_t color);

// 设置是否显示外边框
void sgl_scope_show_outer_border(sgl_obj_t* obj, uint8_t show);

// 设置网格线样式（0-实线，1-虚线）
void sgl_scope_set_grid_style(sgl_obj_t* obj, uint8_t style);

#ifdef __cplusplus
}
#endif

#endif // SGL_SCOPE_H