#include <iostream>
#include <regex>
#include <string>
#include <chrono>
#include <map>
#include "Regex.h"

static int test1(){

    // std::regex reg1{R"((\d{3}\*{4}\d{4})的动态行程卡)"};
    std::regex reg1{R"((.*)的动态行程卡)"};
    std::string str1{"159****5724的动态行程卡"};

    std::smatch res1;
    if(std::regex_match(str1, res1, reg1)){
        std::cout << "res1[0]: " << res1[0].str() << std::endl;
        std::cout << "res1[1]: " << res1[1].str() << std::endl;
    }

    std::regex reg2{R"(更新于:{0,1}\s*(\d{4}.\d{2}.\d{2})\s*(\d{2}:\d{2}:\d{2}))"};
    std::string str2{"更新于:2022.11.01 20:19:28"};

    std::smatch res2;
    if(std::regex_match(str2, res2, reg2)){
        std::cout << "res2[0]: " << res2[0].str() << std::endl;
        std::cout << "res2[1]: " << res2[1].str() << std::endl;
        std::cout << "res2[2]: " << res2[2].str() << std::endl;
    }


    std::regex reg3{R"(您于前(\d+)天内到达或途经:{0,1}\s*(.+)(\(.*\)))"};
    std::string str3{"您于前14天内到达或途经: 浙江省杭州市*,北京市,重庆市*(注: *表示当前该城市存在中风险或高风险地区, 并不表示用户实际到达过这些中高风险地区。)"};

    std::smatch res3;
    if(std::regex_match(str3, res3, reg3)){
        std::cout << "res3[0]: " << res3[0].str() << std::endl;
        std::cout << "res3[1]: " << res3[1].str() << std::endl;
        std::cout << "res3[2]: " << res3[2].str() << std::endl;
        std::cout << "res3[3]: " << res3[3].str() << std::endl;
        std::cout << "res3[4]: " << res3[4].str() << std::endl;
        std::cout << "res3[5]: " << res3[5].str() << std::endl;
    }

    std::cout << "#######################################" << std::endl;

    const std::vector<std::regex> reg_items{
        std::regex{R"((.*)的动态行程卡)"},
        std::regex{R"(更新于:{0,1}\s*(\d{4}.\d{2}.\d{2})\s*(\d{2}:\d{2}:\d{2}))"},
        std::regex{R"(您于前(\d+)天内到达或途经:{0,1}\s*(.+)(\(.*\)))"}
    };

    std::vector<std::string> strs{
        std::string {"159****5724的动态行程卡"},
        std::string {"更新于:2022.11.01 20:19:28"},
        std::string {"您于前14天内到达或途经: 浙江省杭州市*,北京市,重庆市*(注: *表示当前该城市存在中风险或高风险地区, 并不表示用户实际到达过这些中高风险地区。)"}
    };

    std::map<std::string, std::string> msg;
    for (size_t i = 0; i < strs.size(); i++)
    {
        switch(i){
            case 0:{
                std::smatch res;
                if(std::regex_match(strs[0], res, reg_items[0])){
                    msg["phone_no"] = res[1].str();
                }
                break;
            }
            case 1:{
                std::smatch res;
                if(std::regex_match(strs[1], res, reg_items[1])){
                    msg["date"] = res[1].str();
                    msg["time"] = res[2].str();
                }
                break;
            }
            case 2:{
                std::smatch res;
                if(std::regex_match(strs[2], res, reg_items[2])){
                    msg["waypoint"] = res[2].str();
                }
            }
        }
    }

    for(auto& item : msg){
        std::cout << item.first << "\t" << item.second << std::endl;
    }
    

    return 0;
}

static int test2(){
    printf("=== test2 ===\n");
    
    std::regex reg1{R"(((\d{2})-(\d{2}))|(\d{2}:\d{2}:\d{2})|(健康码))"};
    std::string str1{"11-02"};
    // std::string str1{"12:35:49"};
    // std::string str1{"健康码"};
    std::smatch res1;
    if(std::regex_match(str1, res1, reg1)){
        for (size_t i = 0; i < res1.size(); i++)
        {
            std::cout << i << ": " << res1[i] << std::endl;
        }
        
    }else{
        std::cout << "match fail!" << std::endl;
    }

    std::cout << "#########################################" << std::endl;

    //! 每组6个元素
    //! #1(粤,苏) (\s*)(\d{2})-(\d{2})\s*(\d{2}):(\d{2}):(\d{2})        //!"11-01 20:18:59"
    //! #2(闽,赣) (\s*\d{4})-(\d{2})-(\d{2})\s*(\d{2}):(\d{2}):(\d{2})  //!"2022-01-25 10:09:40"
    //! #3(浙1)   (\s*)(\d+)月(\d+)日(\s*)(\s*)(\s*)                    //!"5月29日"
    //! #4(浙2)   (\s*)(\s*)(\s*)(\d{2}):(\d{2}):(\d{2})                //!"23:43:37"
    //! #5(浙3)   (\s*)(\d+)月(\d+)日\s*(\d{2}):(\d{2}):(\d{2})         //!"5月29日 23:43:37"
    for (size_t i = 0; i < 100; i++)
    {
        auto stime = std::chrono::steady_clock::now();
        std::regex reg2{R"(((\s*)(\d{2})-(\d{2})\s*(\d{2}):(\d{2}):(\d{2}))|((\s*\d{4})-(\d{2})-(\d{2})\s*(\d{2}):(\d{2}):(\d{2}))|((\s*)(\d+)月(\d+)日(\s*)(\s*)(\s*))|((\s*)(\s*)(\s*)(\d{2}):(\d{2}):(\d{2}))|((\s*)(\d+)月(\d+)日\s*(\d{2}):(\d{2}):(\d{2})))"};
        // std::string str2{"11-01 20:18:59"};
        // std::string str2{"2022-01-25 10:09:40"};
        // std::string str2{"5月29日"};
        // std::string str2{"23:43:37"};
        std::string str2{"5月29日 23:43:37"};
        std::smatch res2;
        if(std::regex_match(str2, res2, reg2)){
            for (size_t i = 0; i < res2.size(); i++)
            {
                std::cout << i << ": " << res2[i] << std::endl;
            }

            std::cout << "************************" << std::endl;

            for (size_t i = 1; i < res2.size(); i += 7)
            {
                if(res2[i].str() != ""){
                    for (size_t j = 1; j <= 6; j++)
                    {
                        std::cout << res2[i+j] << std::endl;
                    }
                    break;
                }
            }
        }else{
            std::cout << "match fail!" << std::endl;
        }
        auto etime = std::chrono::steady_clock::now();
        std::cout << "match time: " << std::chrono::duration_cast<std::chrono::milliseconds>(etime-stime).count() << " ms" << std::endl;
    }


    std::cout << "#########################################" << std::endl;
    // 3
    //! 每组1个元素
    //! #1 (.+)健康码
    //! #2 (.+)康码
    //! #3 (.+)通码
    std::regex reg3{R"(((.+)健康码)|((.+)康码)|((.+)通码))"};
    std::string str3{"杭州健康码"};
    // std::string str3{"粤康码"};
    // std::string str3{"赣通码"};
    std::smatch res3;
    if(std::regex_match(str3, res3, reg3)){
        for (size_t i = 0; i < res3.size(); i++)
        {
            std::cout << i << ": " << res3[i] << std::endl;
        }

        std::cout << "************************" << std::endl;

        for (size_t i = 1; i < res3.size(); i += 2)
        {
            if(res3[i].str() != ""){
                std::cout << "健康码所属地区: " << res3[i+1] << std::endl;
                break;
            }
        } 
    }else{
        std::cout << "match fail!" << std::endl;
    }

    return 0;
}

void Regex::Regex_Test(){
    printf("===Regex_Test===\n");

    // test1();

    test2();
}