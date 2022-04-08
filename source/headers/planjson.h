#include <string>  
#include <cstdio>
#include "json.hpp"
#include <iostream>  
#include <fstream>  
using namespace std;
using json = nlohmann::json;

//计划
typedef struct OP
{
	float efficiency; // 综合效率
    float line_usage;//线体平均利用率
    float cargo_usage;//立库利用效率
    float ave_work_hour;//日平均工作时长
}originalPlan;

//各个堆垛机的工作时长和加班时长
typedef struct SMWT
{
    int stacker_id;//堆垛机id
    int normal_time;//正常工作时长
    int ex_work_time;//加班工作时长
}SMworkTime;

//每日数据
typedef struct Det
{
    char date[15] = "2022-01-01";//日期
    char type[15] = "module1";//货物类型
    int Det_R = R;//入库数量
    int Det_S = S;//送检数量
    int Det_H = H;//回库数量
    int Det_C = C;//出库数量
    char arrivedBatch[15] = "2621212128223";//到货批次
    char bidBatch[20] = "2020第二批";//招标批次
    char distributionArea[10] = "廊坊";//配送区域
    int handling_capacity;//吞吐量
    int Det_new;//新品数量
    int Det_old;//成品数量
}Detail;

//风险项
typedef struct RISk
{
    char content1[50] = "content1";
    char content2[50] = "content2";
    char content3[50] = "content3";
}Risks;

//检定线体信息
typedef struct LI
{
    char lineName[10] = "line1";
    float useRate;//线体利用率
    char workTime[15] = "28800";//正常工作时长
    char overTime[15] = "0";//加班工作时长

}LineInfo;

//定义 plan 的结构体数组
originalPlan op[] = {
    {128,74,85,585},{128,74,85,585}
};
//定义原计划的堆垛机 结构体数组
SMworkTime plan_smwt[] = {
    {3,7000,996},{4,7000,996},{5,7000,996},{6,7000,996},{7,7000,996},{8,7000,996}
};
//定义优化计划的堆垛机结构体数组
SMworkTime original_smwt[] = {
    {3,7000,996},{4,7000,996},{5,7000,996},{6,7000,996},{7,7000,996},{8,7000,996}
};
//定义原计划的 每天的数据
Detail plan_de[] = {
    {"2022-01-01","module1",R,S,H,C,"2621212128223","2020第二批","廊坊",700,400,350}
};
//定义优化计划 每天的数据
Detail original_de[] = {
    {"2022-01-01","module1",R,S,H,C,"2621212128223","2020第二批","廊坊",700,400,350}
};
//定义原计划的风险项
Risks plan_risk[] = {
    {"content1","content2","content3"}
};
//定义优化计划的风险项
Risks original_risk[] = {
    {"content1","content2","content3"}
};
//定义原计划的检定线体信息
LineInfo plan_li[] = {
    {"line1",0.78,"28800","0"},{"line2",0.78,"28800","0"}
};
//定义优化计划的检定线体信息
LineInfo original_li[] = {
    {"line1",0.78,"28800","0"},{"line2",0.78,"28800","0"}
};

//初始化
void plantInitJson(){
    op[0] = {128,74,85,585};
    op[1] = {128,74,85,585};

    plan_smwt[0] = {3,7000,996};
    plan_smwt[1] = {4,7000,996};
    plan_smwt[2] = {5,7000,996};
    plan_smwt[3] = {6,7000,996};
    plan_smwt[4] = {7,7000,996};
    plan_smwt[5] = {8,7000,996};

    original_smwt[0] = {3,7000,996};
    original_smwt[1] = {4,7000,996};
    original_smwt[2] = {5,7000,996};
    original_smwt[3] = {6,7000,996};
    original_smwt[4] = {7,7000,996};
    original_smwt[5] = {8,7000,996};

    plan_de[0] = {"2022-01-01","module1",R,S,H,C,"2621212128223","2020第二批","廊坊",700,400,350};

    original_de[0] = {"2022-01-01","module1",R,S,H,C,"2621212128223","2020第二批","廊坊",700,400,350};

    plan_risk[0] = {"content1","content2","content3"};

    original_risk[0] = {"content1","content2","content3"};

    plan_li[0] = {"line1",0.78,"28800","0"};
    plan_li[1] = {"line2",0.78,"28800","0"};

    original_li[0] = {"line1",0.78,"21678","0"};
    original_li[1] = {"line1",0.78,"21678","0"};
};

void createPlanJson(){
    json j2 = 
    {
        {"version",0.2},
        {"system","Dynamitic_Digitaltwin"},
        {"stage","ResponseReport"},
        {"time","2021-11-19-16-51"},
        {"runTime",0},
        {"data", 
        {
            {"responseCode",-101},
            {"userName","admin"},
            {"reports",
                {
                    {
                    {"planName","nam1"},
                    {"reportContent",
                        {
                        {"original_plan",
                        {
                            {"summary",
                            {
                                {"efficiency",op[0].efficiency},
                                {"line_usage",op[0].line_usage},
                                {"cargo_usage",op[0].cargo_usage},
                                {"ave_work_hour",op[0].ave_work_hour},
                                {"stacker_work_time",
                                    {
                                        {
                                            {"stacker_id",plan_smwt[0].stacker_id},
                                            {"normal_time",plan_smwt[0].normal_time},
                                            {"ex_work_time",plan_smwt[0].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",plan_smwt[1].stacker_id},
                                            {"normal_time",plan_smwt[1].normal_time},
                                            {"ex_work_time",plan_smwt[1].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",plan_smwt[2].stacker_id},
                                            {"normal_time",plan_smwt[2].normal_time},
                                            {"ex_work_time",plan_smwt[2].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",plan_smwt[3].stacker_id},
                                            {"normal_time",plan_smwt[3].normal_time},
                                            {"ex_work_time",plan_smwt[3].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",plan_smwt[4].stacker_id},
                                            {"normal_time",plan_smwt[4].normal_time},
                                            {"ex_work_time",plan_smwt[4].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",plan_smwt[5].stacker_id},
                                            {"normal_time",plan_smwt[5].normal_time},
                                            {"ex_work_time",plan_smwt[5].ex_work_time}
                                        },
                                    } 
                                }
                            }
                            },
                            {"detail",
                            {
                                {
                                {"date",plan_de[0].date},
                                {"modules",
                                    {
                                    {
                                        {"type",plan_de[0].type},
                                        {"R",plan_de[0].Det_R},
                                        {"S",plan_de[0].Det_S},
                                        {"H",plan_de[0].Det_H},
                                        {"C",plan_de[0].Det_C},
                                        {"arrivedBatch",plan_de[0].arrivedBatch},
                                        {"bidBatch",plan_de[0].bidBatch},
                                        {"distributionArea",plan_de[0].distributionArea}
                                    }
                                    }
                                },
                                {"handling_capacity",plan_de[0].handling_capacity},
                                {"cargo_status",
                                    {
                                    {"new",plan_de[0].Det_new},
                                    {"old",plan_de[0].Det_old}
                                    }
                                }
                                }
                            }
                            },
                            {"risks",{plan_risk[0].content1,plan_risk[0].content2,plan_risk[0].content3}},
                                {"lineInfo",
                                    {
                                        {
                                            {"lineName",plan_li[0].lineName},
                                            {"useRate",plan_li[0].useRate},
                                            {"workTime",plan_li[0].workTime},
                                            {"overTime",plan_li[0].overTime}
                                        },
                                        {
                                            {"lineName",plan_li[1].lineName},
                                            {"useRate",plan_li[1].useRate},
                                            {"workTime",plan_li[1].workTime},
                                            {"overTime",plan_li[1].overTime}
                                        }
                                    }
                                }
                        }
                        }
                        }
                    }
                    },//report 数组
                    {
                        {"planName","nam2"},
                    {"reportContent",
                        {
                        {"original_plan",
                        {
                            {"summary",
                            {
                                {"efficiency",op[1].efficiency},
                                {"line_usage",op[1].line_usage},
                                {"cargo_usage",op[1].cargo_usage},
                                {"ave_work_hour",op[1].ave_work_hour},
                                {"stacker_work_time",
                                    {
                                        {
                                            {"stacker_id",original_smwt[0].stacker_id},
                                            {"normal_time",original_smwt[0].normal_time},
                                            {"ex_work_time",original_smwt[0].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",original_smwt[1].stacker_id},
                                            {"normal_time",original_smwt[1].normal_time},
                                            {"ex_work_time",original_smwt[1].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",original_smwt[2].stacker_id},
                                            {"normal_time",original_smwt[2].normal_time},
                                            {"ex_work_time",original_smwt[2].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",original_smwt[3].stacker_id},
                                            {"normal_time",original_smwt[3].normal_time},
                                            {"ex_work_time",original_smwt[3].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",original_smwt[4].stacker_id},
                                            {"normal_time",original_smwt[4].normal_time},
                                            {"ex_work_time",original_smwt[4].ex_work_time}
                                        },
                                        {
                                            {"stacker_id",original_smwt[5].stacker_id},
                                            {"normal_time",original_smwt[5].normal_time},
                                            {"ex_work_time",original_smwt[5].ex_work_time}
                                        },
                                    } 
                                }
                            }
                            },
                            {"detail",
                            {
                                {
                                {"date",original_de[0].date},
                                {"modules",
                                    {
                                    {
                                        {"type",original_de[0].type},
                                        {"R",original_de[0].Det_R},
                                        {"S",original_de[0].Det_S},
                                        {"H",original_de[0].Det_H},
                                        {"C",original_de[0].Det_C},
                                        {"arrivedBatch",original_de[0].arrivedBatch},
                                        {"bidBatch",original_de[0].bidBatch},
                                        {"distributionArea",original_de[0].distributionArea}
                                    }
                                    }
                                },
                                {"handling_capacity",original_de[0].handling_capacity},
                                {"cargo_status",
                                    {
                                    {"new",original_de[0].Det_new},
                                    {"old",original_de[0].Det_old}
                                    }
                                }
                                }
                            }
                            },
                            {"risks",{original_risk[0].content1,original_risk[0].content2,original_risk[0].content3}},
                                {"lineInfo",
                                    {
                                        {
                                            {"lineName",original_li[0].lineName},
                                            {"useRate",original_li[0].useRate},
                                            {"workTime",original_li[0].workTime},
                                            {"overTime",original_li[0].overTime}
                                        },
                                        {
                                            {"lineName",original_li[1].lineName},
                                            {"useRate",original_li[1].useRate},
                                            {"workTime",original_li[1].workTime},
                                            {"overTime",original_li[1].overTime}
                                        }
                                    }
                                }
                        }
                        }
                        }
                    }
                    }
                }
            }
        }
        }        
    };
    // ofstream fcout;
    // fcout.open("output/planjson.json");
	// //fcout.open("output/json.json");
	// fcout<<j2.dump(4);
	// //Sleep(100);
	// fcout.close();
}