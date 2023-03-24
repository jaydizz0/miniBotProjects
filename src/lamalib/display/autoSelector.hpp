#pragma once

#include "display/lvgl.h"
#include <vector>
#include <string>

namespace lamaLib {

//Simple style stucture
typedef struct {
    lv_color_t mainColour;
    lv_color_t gradientColour;
    lv_color_t textColour;
}t_style;

//Auton structure
typedef struct {
    std::string name;
    std::string description;
    int tabContainer = 0;
    void (*callback)() = nullptr;
    lv_obj_t *btnObj = nullptr;
    lv_obj_t *lblObj = nullptr;
}t_auto;

//Tab structure
typedef struct {
    std::string name;
    t_style btnStyle;
    t_style pressedStyle;
    t_style selectedStyle;
    lv_obj_t *tabObj = nullptr;
    int x = 0;
    int y = 20;
    int count = 0;
}t_atab;

//Style structure:
typedef struct {
    lv_style_t autonStyle;
    lv_style_t pressedStyle;
    lv_style_t selectedStyle;
}t_tabStyle;

class AutoSelector {
    private:
        //Vectors to store tabs and buttons for autons
        static std::vector<t_auto> m_autonbtns;
        static std::vector<t_atab> m_autontabs;

        //Track which button is currently selected
        static int m_selectedBtn;

        //Style objects
        static std::vector<t_tabStyle> m_Styles;
        static lv_style_t m_errorStyle;
        static lv_style_t m_descriptionStyle;

        //Description object and label
        static lv_obj_t *m_desObj;
        static lv_obj_t *m_deslbl;

        //Tab container which houses all the tabs
        static lv_obj_t *m_tabContainer;

        /**
         * @brief Catch button pressed event. Changes the style of the previous and newly selected button
         *      Updates the m_selectedBtn variable and description
         * @param button The button being pressed
         * @return lv_res_t
         */
        static lv_res_t btnSelected(lv_obj_t *button);

        /**
         * @brief Converts the simiplist t_style structure to the lvgl stule structure lv_style_t
         * 
         * @param style The t_style structure to convert
         * @param copy The base style to apply the t_style to
         * @return lv_style_t 
         */
        lv_style_t generateStyle(t_style style, lv_style_t *copy);

        /**
         * @brief Load styles into auton object
         * 
         * @param obj The object to load the styles into
         * @param style Main style
         * @param pressedStyle Pressed style
         */
        static void setStyle(lv_obj_t *obj, lv_style_t *style, lv_style_t *pressedStyle);
    
    public:
        /**
         * @brief Construct a new Auto Selector object
         * 
         * @param tabs List of tabs {name, base style, pressed style, selected style}
         * @param autons List of autons {name (13 length), description (52 length), tab number, function to call}
         */
        AutoSelector(std::vector<t_atab> tabs, std::vector<t_auto> autons);

        /**
         * @brief Draw the auto selector
         * 
         */
        void render();

        /**
         * @brief Run the function of the selected autonomous
         * 
         * @return int 0 - error occured (no selected auton, no function provided); 1 - success
         */
        int runSelectedAuto();
};

}//nameapce lamaLib