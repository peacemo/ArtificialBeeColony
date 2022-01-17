#include <string>  
#include <cstdio>
#include "json.hpp"
#include <iostream>  
#include "headers/head.h"
#include <fstream>  
using namespace std;
using json = nlohmann::json;

int creat_json_file(){
json j1 = {
	{"version",0.2},
	{"system","Dynamitic_Digitaltwin"},
	{"stage","ResponseDeduction"},
	{"type","Dynamitic"},
	{"time",5000},
	{"runTime",0},
	{"data",
	{
		{"responseCode",101},
		{"userName","admin"},
		{"planNames", 
		{
			{
			{"planName", "产线编辑方案名1"},
			{"belong", 0},
			{"optimizationNames", 
				{
					{
						{"optimizationName", "优化方案1"},
						{"planStatus", "inLine"}, 
						{"Progress", 0} 
					}
					,
					{
						{"optimizationName", "优化方案2"},
						{"planStatus", "inLine"}, 
						{"Progress", 0}
					}
				}
			}
			},
			{
			{"planName", "产线编辑方案名2"},
			{"belong", 0}, 
			{"optimizationNames",
				{
				{
					{"optimizationName", "优化方案1"},
					{"planStatus", "inLine"}, 
					{"Progress", 0} 
				},
				{
					{"optimizationName", "优化方案2"},
					{"planStatus", "inLine"}, 
					{"Progress", 0}
				}
				}
			}
			}
				
		}
			},
		{"taskContent", 
		{
			{"loadPointTask", 
			{
				{
				{"taskNumber", lpt[0].taskNumber}, 
				{"equipmentName", "上货点1"},
				{"loadPosition", { -18.51, 0.7, 21.24 }},
				{"assertType", lpt[0].assertType},
				{"assertId", lpt[0].assertId},
				{"target", {-2.967632, 0.7085119, 21.19361}}, 
				{"workStatus", lpt[0].workStatus},
				{"cumulativeTask", lpt[0].cumulativeTask}, 
				{"currentTask", lpt[0].currentTask}, 
				{"equipmentFrequency", lpt[0].equipmentFrequency}, 
				{"maintenanceStatus", lpt[0].maintenanceStatus} 
				},
				{
				{"taskNumber", lpt[1].taskNumber},
				{"equipmentName", "上货点2"},
				{"loadPosition", {-2.950001, 0.7, 19.488}},
				{"assertType", lpt[1].assertType},
				{"assertId", lpt[1].assertId},
				{"target", {  -2.967632, 0.7085119, 21.19361 }}, 
				{"workStatus", lpt[1].workStatus},
				{"totalTask", 0}, 
				{"currentTask", lpt[1].currentTask}, 
				{"equipmentFrequency", lpt[1].equipmentFrequency}, 
				{"maintenanceStatus", lpt[1].maintenanceStatus} 
				}
			}
			},
			{"crossTask", 
			{
				{
				{"taskNumber", ct[0].taskNumber},
				{"crossName", "E区传输线46"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", ct[0].assertId},
				{"assertType", ct[0].assertType}
				},
				{
				{"taskNumber", ct[1].taskNumber},
				{"crossName", "E区传输线50"},
				{"target", {  0.02536774, 0.7085119, 23.97561}},
				{"assertId", ct[1].assertId},
				{"assertType", ct[1].assertType}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线99"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线56"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线57"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线58"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线60"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线61"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线63"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线64"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线66"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线67"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线69"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线71"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线73"},
				{"target", { 0.03236771, 0.7085119, 21.19361 }},
				{"assertId", 1},
				{"assertType", 0}
				},

			}},

			{"RFIDTask", 
			{
				{"taskNumber", 0},
				{"equipmentName", "RFID"},
				{"workStatus", "运行"},
				{"totalTask", 0}, 
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus", 0}, 
				{"assertId", 1},
				{"targetAssert", 0}
			}},

			{"unpackingMachines", 
			{
				{
				{"taskNumber", 0},
				{"equipmentName", "12号拆叠箱机"},
				{"workStatus", "运行"},
				{"totalTask", 0}, 
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus", 0}, 
				{"targetAssert", 0},
				{"target", { 0, 0, 0 }},
				{"assertId", 1}
				},
				{
				{"taskNumber", 0},
				{"equipmentName", "13号拆叠箱机"},
				{"workStatus", "运行"},
				{"totalTask", 0},
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus", 0}, 
				{"targetAssert", 0},
				{"target", { 0, 0, 0 }},
				{"assertId", 1}
				}
			}},
			{"foldMachines", 
			{
				{
				{"taskNumber", 0},
				{"equipmentName", "1号叠箱机"},
				{"workStatus", "运行"},
				{"totalTask", 0}, 
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus", 0}, 
				{"targetAssert", 0},
				{"target", { 0, 0, 0 }},
				{"currentTaskIndex", 1},
				{"assertId", 1}
				},
				{
				{"taskNumber", 0},
				{"equipmentName", "叠箱机2"},
				{"workStatus", "运行"},
				{"totalTask", 0},
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus", 0}, 
				{"targetAssert", 0},
				{"target", { 0, 0, 0 }},
				{"currentTaskIndex", 1},
				{"assertId", 1}
				}
			}},
			{"stackerMachines", 
			{
				{
				{"taskNumber", 0},
				{"equipmentName", "堆垛机1"},
				{"workStatus", "运行"},
				{"totalTask", 0}, 
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus",0}, 
				{"getPosition", { 0, 0, 0 }}, 
				{"getAssertType1", 0}, 
				{"getAssert1Id", 1},
				{"getDirection1", "A"}, 
				{"getAssertType2", 0}, 
				{"getAssert2Id", 1},
				{"getDirection2", "A"}, 
				{"putPosition", { 0, 0, 0 }}, 
				{"putAssertType1", 0}, 
				{"putDirection1", "A"}, 
				{"putAssertType2", 0}, 
				{"putDirection2", "A"} 
				},
				{
				{"taskNumber", 0},
				{"equipmentName", "堆垛机2"},
				{"workStatus", "运行"},
				{"totalTask", 0}, 
				{"currentTask", 0}, 
				{"equipmentFrequency", 0}, 
				{"maintenanceStatus", 0}, 
				{"getPosition", { 0, 0, 0 }}, 
				{"getAssertType1", 0}, 
				{"getAssert1Id", 1},
				{"getDirection1", "A"}, 
				{"getAssertType2", 0}, 
				{"getAssert2Id", 1},
				{"getDirection2", "A"}, 
				{"putPosition", { 0, 0, 0 }}, 
				{"putAssertType1", 0}, 
				{"putDirection1", "A"}, 
				{"putAssertType2", 0},
				{"putDirection2", "A"}
				}
			}},


			{"UIInfo", 
			{
				{"taskPercent", {
				{"deductionTask", { 0, 0 }},
				{"presentTask", { 0, 0 }} 
				}},
				{"inOutAssertCountInfo", {
				{"移库入库", { 0, 0, 0, 0, 0 }}, 
				{"检定出库", { 0, 0, 0, 0, 0 }},
				{"检定入库", { 0, 0, 0, 0, 0 }},
				{"配送出库", { 0, 0, 0, 0, 0 }},
				{"入库总量", 0},
				{"出库总量", 0}
				}},
				{"stroageInfo", { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 336574 }}, 

				{"productionWarning", {"1排货架已满","10排货架大量闲置","叠相机2号出现拥堵"}}

			}
		}
	}
		
	
	}
	}
	}
};

	ofstream fcout;
	fcout.open("output/json.json",ios::app);
	//fcout<<endl<<","<<endl;
	fcout<<j1.dump(4);
	return 0;
}
int main(){
	creat_json_file();
	system("pause");
	return 0;
}