/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and 
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may 
 * *    be used to endorse or promote products derived from this software 
 * *    without specific prior written permission.
 * 
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __BSP_CPUFREQ_H__
#define __BSP_CPUFREQ_H__

#ifdef __cplusplus /* __cplusplus */
extern "C"
{
#endif /* __cplusplus */

#include <osl_types.h>
#include "bsp_sram.h"


extern int g_cpufreq_max_profile;
#define DC_RESV								(g_cpufreq_max_profile)
#define BALONG_FREQ_MAX			(DC_RESV - 1)
#define BALONG_FREQ_MIN			(0)

#define CPUFREQ_CUR_PROFILE						(((SRAM_SMALL_SECTIONS * )((unsigned long)SRAM_BASE_ADDR+SRAM_OFFSET_SMALL_SECTIONS))->SRAM_CUR_CPUFREQ_PROFILE)
#define CPUFREQ_MAX_PROFILE_LIMIT			(((SRAM_SMALL_SECTIONS * )((unsigned long)SRAM_BASE_ADDR+SRAM_OFFSET_SMALL_SECTIONS))->SRAM_MAX_CPUFREQ_PROFILE)
#define CPUFREQ_MIN_PROFILE_LIMIT			(((SRAM_SMALL_SECTIONS * )((unsigned long)SRAM_BASE_ADDR+SRAM_OFFSET_SMALL_SECTIONS))->SRAM_MIN_CPUFREQ_PROFILE)
#define CPUFREQ_DOWN_FLAG(core_type)   					(((SRAM_SMALL_SECTIONS * )((unsigned long)SRAM_BASE_ADDR+SRAM_OFFSET_SMALL_SECTIONS))->SRAM_CPUFREQ_DOWN_FLAG[core_type])
#define CPUFREQ_DOWN_PROFILE(core_type)  				 (((SRAM_SMALL_SECTIONS * )((unsigned long)SRAM_BASE_ADDR+SRAM_OFFSET_SMALL_SECTIONS))->SRAM_CPUFREQ_DOWN_PROFILE[core_type])

enum CPUFREQ_ACPU_VOTE_ID
{
    CPUFREQ_VOTE_ID_SPE = 0,
    CPUFREQ_VOTE_ID_DIAG,
    CPUFREQ_VOTE_ID_MAX,
};
int bsp_acpufreq_vote_updata(int qos_id, unsigned int req_value);
enum CPUFREQ_MSG_TYPE{
	CPUFREQ_ADJUST_FREQ = 1,			/*通知M3调频*/
	CPUFREQ_DEBUG_FREQ = 2,			/*用于DEBUG  标记*/
	CPUFREQ_GET_FREQ_FROM_M = 3,		/*获取当前频率*/
	CPUFREQ_SEND_CPUFREQ_FROM_M = 4,			/*M3回复当前频率*/
	CPUFREQ_LOCK_MCORE_ACTION = 5,			/*锁定M3调频*/
    CPUFREQ_SET_DDR_LIMIT = 6,
};
/*哪个核发的消息*/
enum CPUFREQ_SOURCE{
	CPUFREQ_ACORE = 0,
	CPUFREQ_CCORE,
	CPUFREQ_MCORE,
	CPUFREQ_NRCCORE = 7,  //后续和ddr source 统一添加到同一头文件中
};

/*content 低4BIT 上调下调 高4BIT 哪个profile*/
struct cpufreq_msg {
	u32 msg_type;
	u32 source;
	u32 content;
	u32 profile;
};

struct cpufreq_debug_msg {
	u32 msg_type;
	u32 source;
	u32 content;
	u32 target_profile;
	s32 taskid;
	u32 cur_profile;
	u32 cur_load;
};

struct cur_freq{	
    u32 cpu_freq;	
    u32 l2_freq;	
    u32 slow_freq;	
    u32 fast_freq;	
    u32 cur_volt;	
};

enum CPUFREQ_LOG_TYPE{
	CPUFREQ_ICC_LOG,
	CPUFREQ_VOTE_LOG,
};

typedef enum
{
    DFS_PROFILE_UP   = 0,
    DFS_PROFILE_UP_TARGET = 1,
    DFS_PROFILE_DOWN = 2,
    DFS_PROFILE_DOWN_TARGET = 3,
    DFS_PROFILE_DOWN_LIMIT = 4,
    DFS_PROFILE_UP_LIMIT = 5,
    DFS_PROFILE_LOCKFREQ = 0,
    DFS_PROFILE_UNLOCKFREQ = 1,
	DFS_PROFILE_NOCHANGE = 10,
} DFS_PROFILE_STATE_ENUM;



#define DDR_DFS_FREQ4   (1333 * 1000)
#define DDR_DFS_FREQ3  (1066 * 1000)
#define DDR_DFS_FREQ2  (800 * 1000)
#define DDR_DFS_FREQ1  (400 * 1000)
#define DDR_DFS_FREQ0  (266 * 1000)

#define DDR_DFS_MIN_FREQ  DDR_DFS_FREQ0
#define DDR_DFS_MAX_FREQ DDR_DFS_FREQ4



struct cpufreq_query {
	u32 cpu_frequency;
	u32 ddr_frequency;
	u32 sbus_frequency;
	u32 profile;
	u32 using_flag;
};

#define DUMP_EXT_FREQ_SIZE      (0x200)
#define FREQ_DUMP_SIZE       (10)
#define FREQ_DUMP_FLOW_SIZE       (5)
#define FREQ_TEMPP_SIZE     (3)
struct freq_dump_st
{
    u32 cpuload_count;
    u32 cpuload[FREQ_DUMP_SIZE];
    u32 cpu_freq_count;
    u32 cpu_freq_start_time[FREQ_DUMP_FLOW_SIZE];
    u32 cpu_freq_end_time[FREQ_DUMP_FLOW_SIZE];
    u32 cpu_cur_freq[FREQ_DUMP_FLOW_SIZE];
    u32 cpu_dst_freq[FREQ_DUMP_FLOW_SIZE];
    u32 fast_freq_count;
    u32 fast_freq_start_time[FREQ_DUMP_FLOW_SIZE];
    u32 fast_freq_end_time[FREQ_DUMP_FLOW_SIZE];
    u32 fast_cur_freq[FREQ_DUMP_FLOW_SIZE];
    u32 fast_dst_freq[FREQ_DUMP_FLOW_SIZE];
    u32 slow_freq_count;
    u32 slow_freq_start_time[FREQ_DUMP_FLOW_SIZE];
    u32 slow_freq_end_time[FREQ_DUMP_FLOW_SIZE];
    u32 slow_cur_freq[FREQ_DUMP_FLOW_SIZE];
    u32 slow_dst_freq[FREQ_DUMP_FLOW_SIZE];
    u32 vote_info_count;
    u32 vote_info[FREQ_DUMP_SIZE];
    u32 vote_info_time[FREQ_DUMP_SIZE];
    u32 icc_count;
    u32 icc_info[FREQ_DUMP_SIZE];
    u32 icc_info_time[FREQ_DUMP_SIZE];
    u32 temp_prot_icc_time;
    u32 temp_prot_down_time;
    u32 temp_prot_up_time;
    u32 temp_prot_cb_time;
    u32 temp_prot_mark;
    u32 temp_cb_end_time[FREQ_TEMPP_SIZE];
    u32 temp_cb_addr[FREQ_TEMPP_SIZE];
    u32 freq_dump_size;
};

#define CPUFREQ_START_TEMP_PROTECT   (0x5354454D)
#define CPUFREQ_END_TEMP_PROTECT       (0x4550524F)

int cpufreq_init(void);
void cpufreq_set_max_freq(void);
int cpufreq_dfs_set_baseprofile(int baseprofile);
void cpufreq_enter_idle(void);
void cpufreq_exit_idle(void);
int cpufreq_qos_request(int qos_id, unsigned int req_value, int* req_id);
int cpufreq_qos_update(int qos_id, int req_id, unsigned int req_value);
int cpufreq_qos_release(int qos_id, int* req_id);

int bsp_cpufreq_qos_request(int qos_id, unsigned int req_value, int* req_id);
int bsp_cpufreq_qos_release(int qos_id, int* req_id);
int bsp_cpufreq_qos_update(int qos_id, int req_id, unsigned int req_value);
void bsp_cpufreq_set_temp_mark(u32 mark);
u32 bsp_cpufreq_get_temp_protect_mark(void);
struct freq_dump_st * bsp_cpufreq_get_dump_addr(void);

#ifdef __cplusplus /* __cplusplus */
}
#endif /* __cplusplus */

#endif    /*  __BSP_CPUFREQ_H__ */

