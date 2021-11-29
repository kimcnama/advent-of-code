//
// Created by kieran McNamara on 28/11/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day2/gift_wrap_dim.h"
#include "../../inc/day2/wrapping_order.h"
#include "../../inc/day2/gift_ribbon_wrap.h"
#include "../../inc/day2/wrapping_order_ribbon.h"

using namespace std;

uint32_t AddPresents(WrappingOrder* wrappingOrder) {
    ifstream file("../../../2015/test/day2/test_data.in.txt");
    string str_line;
    string str_temp;

    uint32_t u32_len;
    string str_len;

    uint32_t u32_width;
    string str_width;

    uint32_t u32_height;
    string str_height;

    uint32_t u32_numInputs = 0;

    while (getline(file, str_line)) {

        cout << str_line << endl;

        str_len = str_line.substr(0, str_line.find_first_of('x'));
        str_temp = str_line.substr(str_line.find_first_of('x') + 1);

        str_width = str_temp.substr(0, str_temp.find_first_of('x'));

        str_height = str_temp.substr(str_temp.find_first_of('x') + 1);

        u32_len = (uint32_t)atoi(str_len.c_str());
        u32_width = (uint32_t)atoi(str_width.c_str());
        u32_height = (uint32_t)atoi(str_height.c_str());

        cout << u32_len << " x " << u32_width << " x " << u32_height << endl;

        wrappingOrder->AddOrder(u32_len, u32_width, u32_height);
        ++u32_numInputs;
    }
    return u32_numInputs;
}

uint32_t AddPresents(WrappingOrderRibbon* wrappingOrder) {
    ifstream file("../../../2015/test/day2/test_data.in.txt");
    string str_line;
    string str_temp;

    uint32_t u32_len;
    string str_len;

    uint32_t u32_width;
    string str_width;

    uint32_t u32_height;
    string str_height;

    uint32_t u32_numInputs = 0;

    while (getline(file, str_line)) {

        cout << str_line << endl;

        str_len = str_line.substr(0, str_line.find_first_of('x'));
        str_temp = str_line.substr(str_line.find_first_of('x') + 1);

        str_width = str_temp.substr(0, str_temp.find_first_of('x'));

        str_height = str_temp.substr(str_temp.find_first_of('x') + 1);

        u32_len = (uint32_t)atoi(str_len.c_str());
        u32_width = (uint32_t)atoi(str_width.c_str());
        u32_height = (uint32_t)atoi(str_height.c_str());

        cout << u32_len << " x " << u32_width << " x " << u32_height << endl;

        wrappingOrder->AddOrder(u32_len, u32_width, u32_height);
        ++u32_numInputs;
    }
    return u32_numInputs;
}

TEST(GiftWrapDimTests, SanityTests) {
    auto gift = GiftWrapDim();
    ASSERT_TRUE(gift.GetWrappingReq() == 0);
    gift.SetParams(2, 3, 4);
    ASSERT_TRUE(gift.GetWrappingReq() == 58);
    gift.SetParams(1, 1, 10);
    ASSERT_TRUE(gift.GetWrappingReq() == 43);
    gift.SetParams(0, 0, 0);
    ASSERT_TRUE(gift.GetWrappingReq() == 0);
}

TEST(WrappingOrderTests, SanityTests) {
    auto wrappingOrder = WrappingOrder();
    ASSERT_TRUE(wrappingOrder.GetWrappingPaperReq() == 0);
    wrappingOrder.CalcWrappingPaperReq();
    ASSERT_TRUE(wrappingOrder.GetWrappingPaperReq() == 0);

    uint32_t totExpectedWrapping = 58;
    wrappingOrder.AddOrder(2, 3, 4);
    wrappingOrder.CalcWrappingPaperReq();
    ASSERT_TRUE(wrappingOrder.GetWrappingPaperReq() == totExpectedWrapping);

    totExpectedWrapping += 43;
    wrappingOrder.AddOrder(1, 1, 10);
    wrappingOrder.CalcWrappingPaperReq();
    ASSERT_TRUE(wrappingOrder.GetWrappingPaperReq() == totExpectedWrapping);
}

TEST(WrappingOrderTests, InputTestPart1) {

    auto wrappingOrder = WrappingOrder();

    uint32_t u32_numInputs = AddPresents(&wrappingOrder);
    wrappingOrder.CalcWrappingPaperReq();
    cout << "Number of inputs: " << u32_numInputs << endl;
    cout << endl << "Answer: " << wrappingOrder.GetWrappingPaperReq() << endl;

    ASSERT_TRUE(u32_numInputs == 1000);
    ASSERT_TRUE(wrappingOrder.GetWrappingPaperReq() == 1588178);
}

TEST(RibbonWrapTests, SanityTests) {

    auto ribbonWrap = GiftRibbonWrapped();
    ASSERT_TRUE(ribbonWrap.GetWrappingReq() == 0);
    ASSERT_TRUE(ribbonWrap.GetRibbonReq() == 0);
    ribbonWrap.SetParams(2, 3, 4);
    ASSERT_TRUE(ribbonWrap.GetWrappingReq() == 58);
    ASSERT_TRUE(ribbonWrap.GetRibbonReq() == 34);
    ribbonWrap.SetParams(1, 1, 10);
    ASSERT_TRUE(ribbonWrap.GetWrappingReq() == 43);
    ASSERT_TRUE(ribbonWrap.GetRibbonReq() == 14);
}

TEST(RibbonWrapTests, InputTest) {

    auto wrappingOrder = WrappingOrderRibbon();

    uint32_t u32_numInputs = AddPresents(&wrappingOrder);
    wrappingOrder.CalcRibbonReq();
    cout << "Number of inputs: " << u32_numInputs << endl;
    cout << endl << "Answer: " << wrappingOrder.GetRibbonReq() << endl;

    ASSERT_TRUE(u32_numInputs == 1000);
    ASSERT_TRUE(wrappingOrder.GetRibbonReq() == 3783758);
}
