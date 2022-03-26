#include <string>  
#include <cstdio>
#include "json.hpp"
#include <iostream>  
#include "head.h"
#include <fstream>  
using namespace std;
using json = nlohmann::json;

// 初始化
void init_json(){
	lpt[0] = {0,0,1,"运行",1000,1,5,1};
	lpt[1] = {0,0,1,"运行",1000,1,5,1};
	

	ct[0] = {0,0.03236771,0.7085119,21.19361,1,0};
	ct[1] = {0,0.02536774,0.7085119,23.97561,1,0};
	

	fm[0] = {0,"运行",1,1,1,1,1,0,1};

	sm[0] = {0,0,"3号堆垛机","运行",0,0,0,0,10000,10000,37.49,0,0,'A',0,0,'A',10000,10000,37.49,0,0,'A',0,0,'A',10000,10000,37.49,0,'A',0,'A',10000,10000,37.49,0,'A',0,'A'};
	sm[1] = {0,0,"4号堆垛机","运行",0,0,0,0,10000,10000,41.27,0,0,'A',0,0,'A',10000,10000,41.27,0,0,'A',0,0,'A',10000,10000,41.27,0,'A',0,'A',10000,10000,41.27,0,'A',0,'A'};
	sm[2] = {0,0,"5号堆垛机","运行",0,0,0,0,10000,10000,44.04,0,0,'A',0,0,'A',10000,10000,44.04,0,0,'A',0,0,'A',10000,10000,44.04,0,'A',0,'A',10000,10000,44.04,0,'A',0,'A'};
	sm[3] = {0,0,"6号堆垛机","运行",0,0,0,0,10000,10000,46.74,0,0,'A',0,0,'A',10000,10000,46.74,0,0,'A',0,0,'A',10000,10000,46.74,0,'A',0,'A',10000,10000,46.74,0,'A',0,'A'};
	sm[4] = {0,0,"7号堆垛机","运行",0,0,0,0,10000,10000,49.48,0,0,'A',0,0,'A',10000,10000,49.48,0,0,'A',0,0,'A',10000,10000,49.48,0,'A',0,'A',10000,10000,49.48,0,'A',0,'A'};
	sm[5] = {0,0,"8号堆垛机","运行",0,0,0,0,10000,10000,52.38,0,0,'A',0,0,'A',10000,10000,52.38,0,0,'A',0,0,'A',10000,10000,52.38,0,'A',0,'A',10000,10000,52.38,0,'A',0,'A'};
}


int creat_json_file(){
json j1 = {
	{"version",0.2},
	{"system","Dynamitic_Digitaltwin"},
	{"stage","ResponseDeduction"},
	{"type","Dynamitic"},
	{"time",times},
	{"runTime",runTime},
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
				{"loadPosition", { 1887.95, 0.7, 21.24 }},
				{"assertType", lpt[0].assertType},
				{"assertId", lpt[0].assertId},
				{"target", {1903.5, 0.71, 21.19}}, 
				{"workStatus", lpt[0].workStatus},
				{"cumulativeTask", lpt[0].cumulativeTask}, 
				{"currentTask", lpt[0].currentTask}, 
				{"outTask",lpt[0].outTask},
				{"equipmentFrequency", lpt[0].equipmentFrequency}, 
				{"maintenanceStatus", lpt[0].maintenanceStatus} 
				},
				{
				{"taskNumber", lpt[1].taskNumber},
				{"equipmentName", "上货点2"},
				{"loadPosition", {1903.51, 0.7, 19.49}},
				{"assertType", lpt[1].assertType},
				{"assertId", lpt[1].assertId},
				{"target", {  1903.5, 0.71, 21.19 }}, 
				{"workStatus", lpt[1].workStatus},
				{"totalTask", 0}, 
				{"currentTask", lpt[1].currentTask}, 
				{"outTask",lpt[1].outTask},
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
				{"target", { 1906.5, 0.71, 21.19 }},
				{"assertId", ct[0].assertId},
				{"assertType", ct[0].assertType}
				},
				{
				{"taskNumber", ct[1].taskNumber},
				{"crossName", "E区传输线50"},
				{"target", {  1906.49, 0.71, 23.98}},
				{"assertId", ct[1].assertId},
				{"assertType", ct[1].assertType}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线99"},
				{"target", { -0.58, 0.71, 52.2 }},
				{"assertId", 1},
				{"assertType", 0}
				},
				{
				{"taskNumber", 0},
				{"crossName", "F区传输线56"},
				{"target", { -0.58, 0.71, 51.27 }},
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
				{"taskNumber", fm[0].taskNumber},
				{"equipmentName", "1号叠箱机"},
				{"workStatus", fm[0].workStatus},
				{"totalTask", fm[0].totalTask}, 
				{"currentTask", fm[0].currentTask}, 
				{"equipmentFrequency", fm[0].equipmentFrequency}, 
				{"maintenanceStatus", fm[0].maintenanceStatus}, 
				{"targetAssert", fm[0].targetAssert},
				{"target", { 1906.5, 0.71, 52.2  }},
				{"currentTaskIndex", fm[0].currentTaskIndex},
				{"assertId", fm[0].assertId}
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
				{"TaskType",sm[0].TaskType},
				{"taskNumber", sm[0].taskNumber},
				{"equipmentName", "3号堆垛机"},
				{"workStatus", "运行"},
				{"totalTask", g1_n}, 
				{"currentTask", sm[0].currentTask}, 
				{"equipmentFrequency", sm[0].equipmentFrequency}, 
				{"maintenanceStatus",sm[0].maintenanceStatus}, 
				{
					"stackerGetItems",{
					{
					{"getPosition", { sm[0].getPosition_x1, sm[0].getPosition_y1, sm[0].getPosition_z1 }}, 
					{"getAssertType1", sm[0].getAssertType1_1}, 
					{"getAssert1Id", sm[0].getAssert1Id_1},
					{"getDirection1", char(sm[0].getDirection1_1)}, 
					{"getAssertType2", sm[0].getAssertType2_1}, 
					{"getAssert2Id", sm[0].getAssert2Id_1},
					{"getDirection2", char(sm[0].getDirection2_1)}
					},
					{
					{"getPosition", { sm[0].getPosition_x2, sm[0].getPosition_y2, sm[0].getPosition_z2 }}, 
					{"getAssertType1", sm[0].getAssertType1_2}, 
					{"getAssert1Id", sm[0].getAssert1Id_2},
					{"getDirection1", char(sm[0].getDirection1_2)}, 
					{"getAssertType2", sm[0].getAssertType2_2}, 
					{"getAssert2Id", sm[0].getAssert2Id_2},
					{"getDirection2", char(sm[0].getDirection2_2)}	
					}
					}
				}
				,
				{
					"statckPutItems",{
						{
							{"putPosition", { sm[0].putPosition_x1, sm[0].putPosition_y1, sm[0].putPosition_z1 }}, 
							{"putAssertType1", sm[0].putAssertType1_1}, 
							{"putDirection1", char(sm[0].putDirection1_1)}, 
							{"putAssertType2", sm[0].putAssertType2_1},
							{"putDirection2", char(sm[0].putDirection2_1)}
						}
						,
						{
							{"putPosition", { sm[0].putPosition_x2, sm[0].putPosition_y2, sm[0].putPosition_z2 }}, 
							{"putAssertType1", sm[0].putAssertType1_2}, 
							{"putDirection1", char(sm[0].putDirection1_2)}, 
							{"putAssertType2", sm[0].putAssertType2_2},
							{"putDirection2", char(sm[0].putDirection2_2)}
						}
					}
				}
				},
				{
				{"TaskType",sm[1].TaskType},
				{"taskNumber", sm[1].taskNumber},
				{"equipmentName", "4号堆垛机"},
				{"workStatus", "运行"},
				{"totalTask", g2_n}, 
				{"currentTask", sm[1].currentTask}, 
				{"equipmentFrequency", sm[1].equipmentFrequency}, 
				{"maintenanceStatus",sm[1].maintenanceStatus}, 
				{
					"stackerGetItems",{
					{
					{"getPosition", { sm[1].getPosition_x1, sm[1].getPosition_y1, sm[1].getPosition_z1 }}, 
					{"getAssertType1", sm[1].getAssertType1_1}, 
					{"getAssert1Id", sm[1].getAssert1Id_1},
					{"getDirection1", char(sm[1].getDirection1_1)}, 
					{"getAssertType2", sm[1].getAssertType2_1}, 
					{"getAssert2Id", sm[1].getAssert2Id_1},
					{"getDirection2", char(sm[1].getDirection2_1)}
					},
					{
					{"getPosition", { sm[1].getPosition_x2, sm[1].getPosition_y2, sm[1].getPosition_z2 }}, 
					{"getAssertType1", sm[1].getAssertType1_2}, 
					{"getAssert1Id", sm[1].getAssert1Id_2},
					{"getDirection1", char(sm[1].getDirection1_2)}, 
					{"getAssertType2", sm[1].getAssertType2_2}, 
					{"getAssert2Id", sm[1].getAssert2Id_2},
					{"getDirection2", char(sm[1].getDirection2_2)}	
					}
					}
				}
				,
				{
					"statckPutItems",{
						{
							{"putPosition", { sm[1].putPosition_x1, sm[1].putPosition_y1, sm[1].putPosition_z1 }}, 
							{"putAssertType1", sm[1].putAssertType1_1}, 
							{"putDirection1", char(sm[1].putDirection1_1)}, 
							{"putAssertType2", sm[1].putAssertType2_1},
							{"putDirection2", char(sm[1].putDirection2_1)}
						}
						,
						{
							{"putPosition", { sm[1].putPosition_x2, sm[1].putPosition_y2, sm[1].putPosition_z2 }}, 
							{"putAssertType1", sm[1].putAssertType1_2}, 
							{"putDirection1", char(sm[1].putDirection1_2)}, 
							{"putAssertType2", sm[1].putAssertType2_2},
							{"putDirection2", char(sm[1].putDirection2_2)}
						}
					}
				}
				},
				{
				{"TaskType",sm[2].TaskType},
				{"taskNumber", sm[2].taskNumber},
				{"equipmentName", "5号堆垛机"},
				{"workStatus", "运行"},
				{"totalTask", g3_n}, 
				{"currentTask", sm[2].currentTask}, 
				{"equipmentFrequency", sm[2].equipmentFrequency}, 
				{"maintenanceStatus",sm[2].maintenanceStatus}, 
				{
					"stackerGetItems",{
					{
					{"getPosition", { sm[2].getPosition_x1, sm[2].getPosition_y1, sm[2].getPosition_z1 }}, 
					{"getAssertType1", sm[2].getAssertType1_1}, 
					{"getAssert1Id", sm[2].getAssert1Id_1},
					{"getDirection1", char(sm[2].getDirection1_1)}, 
					{"getAssertType2", sm[2].getAssertType2_1}, 
					{"getAssert2Id", sm[2].getAssert2Id_1},
					{"getDirection2", char(sm[2].getDirection2_1)}
					},
					{
					{"getPosition", { sm[2].getPosition_x2, sm[2].getPosition_y2, sm[2].getPosition_z2 }}, 
					{"getAssertType1", sm[2].getAssertType1_2}, 
					{"getAssert1Id", sm[2].getAssert1Id_2},
					{"getDirection1", char(sm[2].getDirection1_2)}, 
					{"getAssertType2", sm[2].getAssertType2_2}, 
					{"getAssert2Id", sm[2].getAssert2Id_2},
					{"getDirection2", char(sm[2].getDirection2_2)}	
					}
					}
				}
				,
				{
					"statckPutItems",{
						{
							{"putPosition", { sm[2].putPosition_x1, sm[2].putPosition_y1, sm[2].putPosition_z1 }}, 
							{"putAssertType1", sm[2].putAssertType1_1}, 
							{"putDirection1", char(sm[2].putDirection1_1)}, 
							{"putAssertType2", sm[2].putAssertType2_1},
							{"putDirection2", char(sm[2].putDirection2_1)}
						}
						,
						{
							{"putPosition", { sm[2].putPosition_x2, sm[2].putPosition_y2, sm[2].putPosition_z2 }}, 
							{"putAssertType1", sm[2].putAssertType1_2}, 
							{"putDirection1", char(sm[2].putDirection1_2)}, 
							{"putAssertType2", sm[2].putAssertType2_2},
							{"putDirection2", char(sm[2].putDirection2_2)}
						}
					}
				}
				},
				{
				{"TaskType",sm[3].TaskType},
				{"taskNumber", sm[3].taskNumber},
				{"equipmentName", "6号堆垛机"},
				{"workStatus", "运行"},
				{"totalTask", g4_n}, 
				{"currentTask", sm[3].currentTask}, 
				{"equipmentFrequency", sm[3].equipmentFrequency}, 
				{"maintenanceStatus",sm[3].maintenanceStatus}, 
				{
					"stackerGetItems",{
					{
					{"getPosition", { sm[3].getPosition_x1, sm[3].getPosition_y1, sm[3].getPosition_z1 }}, 
					{"getAssertType1", sm[3].getAssertType1_1}, 
					{"getAssert1Id", sm[3].getAssert1Id_1},
					{"getDirection1", char(sm[3].getDirection1_1)}, 
					{"getAssertType2", sm[3].getAssertType2_1}, 
					{"getAssert2Id", sm[3].getAssert2Id_1},
					{"getDirection2", char(sm[3].getDirection2_1)}
					},
					{
					{"getPosition", { sm[3].getPosition_x2, sm[3].getPosition_y2, sm[3].getPosition_z2 }}, 
					{"getAssertType1", sm[3].getAssertType1_2}, 
					{"getAssert1Id", sm[3].getAssert1Id_2},
					{"getDirection1", char(sm[3].getDirection1_2)}, 
					{"getAssertType2", sm[3].getAssertType2_2}, 
					{"getAssert2Id", sm[3].getAssert2Id_2},
					{"getDirection2", char(sm[3].getDirection2_2)}	
					}
					}
				}
				,
				{
					"statckPutItems",{
						{
							{"putPosition", { sm[3].putPosition_x1, sm[3].putPosition_y1, sm[3].putPosition_z1 }}, 
							{"putAssertType1", sm[3].putAssertType1_1}, 
							{"putDirection1", char(sm[3].putDirection1_1)}, 
							{"putAssertType2", sm[3].putAssertType2_1},
							{"putDirection2", char(sm[3].putDirection2_1)}
						}
						,
						{
							{"putPosition", { sm[3].putPosition_x2, sm[3].putPosition_y2, sm[3].putPosition_z2 }}, 
							{"putAssertType1", sm[3].putAssertType1_2}, 
							{"putDirection1", char(sm[3].putDirection1_2)}, 
							{"putAssertType2", sm[3].putAssertType2_2},
							{"putDirection2", char(sm[3].putDirection2_2)}
						}
					}
				}
				},
				{
				{"TaskType",sm[4].TaskType},
				{"taskNumber", sm[4].taskNumber},
				{"equipmentName", "7号堆垛机"},
				{"workStatus", "运行"},
				{"totalTask", g5_n}, 
				{"currentTask", sm[4].currentTask}, 
				{"equipmentFrequency", sm[4].equipmentFrequency}, 
				{"maintenanceStatus",sm[4].maintenanceStatus}, 
				{
					"stackerGetItems",{
					{
					{"getPosition", { sm[4].getPosition_x1, sm[4].getPosition_y1, sm[4].getPosition_z1 }}, 
					{"getAssertType1", sm[4].getAssertType1_1}, 
					{"getAssert1Id", sm[4].getAssert1Id_1},
					{"getDirection1", char(sm[4].getDirection1_1)}, 
					{"getAssertType2", sm[4].getAssertType2_1}, 
					{"getAssert2Id", sm[4].getAssert2Id_1},
					{"getDirection2", char(sm[4].getDirection2_1)}
					},
					{
					{"getPosition", { sm[4].getPosition_x2, sm[4].getPosition_y2, sm[4].getPosition_z2 }}, 
					{"getAssertType1", sm[4].getAssertType1_2}, 
					{"getAssert1Id", sm[4].getAssert1Id_2},
					{"getDirection1", char(sm[4].getDirection1_2)}, 
					{"getAssertType2", sm[4].getAssertType2_2}, 
					{"getAssert2Id", sm[4].getAssert2Id_2},
					{"getDirection2", char(sm[4].getDirection2_2)}	
					}
					}
				}
				,
				{
					"statckPutItems",{
						{
							{"putPosition", { sm[4].putPosition_x1, sm[4].putPosition_y1, sm[4].putPosition_z1 }}, 
							{"putAssertType1", sm[4].putAssertType1_1}, 
							{"putDirection1", char(sm[4].putDirection1_1)}, 
							{"putAssertType2", sm[4].putAssertType2_1},
							{"putDirection2", char(sm[4].putDirection2_1)}
						}
						,
						{
							{"putPosition", { sm[4].putPosition_x2, sm[4].putPosition_y2, sm[4].putPosition_z2 }}, 
							{"putAssertType1", sm[4].putAssertType1_2}, 
							{"putDirection1", char(sm[4].putDirection1_2)}, 
							{"putAssertType2", sm[4].putAssertType2_2},
							{"putDirection2", char(sm[4].putDirection2_2)}
						}
					}
				}
				},
				{
				{"TaskType",sm[5].TaskType},
				{"taskNumber", sm[5].taskNumber},
				{"equipmentName", "8号堆垛机"},
				{"workStatus", "运行"},
				{"totalTask", g6_n}, 
				{"currentTask", sm[5].currentTask}, 
				{"equipmentFrequency", sm[5].equipmentFrequency}, 
				{"maintenanceStatus",sm[5].maintenanceStatus}, 
				{
					"stackerGetItems",{
					{
					{"getPosition", { sm[5].getPosition_x1, sm[5].getPosition_y1, sm[5].getPosition_z1 }}, 
					{"getAssertType1", sm[5].getAssertType1_1}, 
					{"getAssert1Id", sm[5].getAssert1Id_1},
					{"getDirection1", char(sm[5].getDirection1_1)}, 
					{"getAssertType2", sm[5].getAssertType2_1}, 
					{"getAssert2Id", sm[5].getAssert2Id_1},
					{"getDirection2", char(sm[5].getDirection2_1)}
					},
					{
					{"getPosition", { sm[5].getPosition_x2, sm[5].getPosition_y2, sm[5].getPosition_z2 }}, 
					{"getAssertType1", sm[5].getAssertType1_2}, 
					{"getAssert1Id", sm[5].getAssert1Id_2},
					{"getDirection1", char(sm[5].getDirection1_2)}, 
					{"getAssertType2", sm[5].getAssertType2_2}, 
					{"getAssert2Id", sm[5].getAssert2Id_2},
					{"getDirection2", char(sm[5].getDirection2_2)}	
					}
					}
				}
				,
				{
					"statckPutItems",{
						{
							{"putPosition", { sm[5].putPosition_x1, sm[5].putPosition_y1, sm[5].putPosition_z1 }}, 
							{"putAssertType1", sm[5].putAssertType1_1}, 
							{"putDirection1", char(sm[5].putDirection1_1)}, 
							{"putAssertType2", sm[5].putAssertType2_1},
							{"putDirection2", char(sm[5].putDirection2_1)}
						}
						,
						{
							{"putPosition", { sm[5].putPosition_x2, sm[5].putPosition_y2, sm[5].putPosition_z2 }}, 
							{"putAssertType1", sm[5].putAssertType1_2}, 
							{"putDirection1", char(sm[5].putDirection1_2)}, 
							{"putAssertType2", sm[5].putAssertType2_2},
							{"putDirection2", char(sm[5].putDirection2_2)}
						}
					}
				}
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
	//fcout.open("output/json.json");
	fcout<<"\t"<<j1.dump(4);
	fcout<<endl<<","<<endl;
	//Sleep(100);
	fcout.close();
	return 0;
}
