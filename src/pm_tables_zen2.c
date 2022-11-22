/**
 * Ryzen SMU Userspace Sensor Monitor
 * Copyright (C) 2021
 *    Florian Huehn <hattedsquirrel@gmail.com> (https://hattedsquirrel.net)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

/**
 * This file contains the mapping of every known PM Table version
 **/

#include "pm_tables.h"
#include "pm_tables_helpers.h"

void pm_table_0x240903(pm_table *pmt, void* base_addr) {
    // Order of elements extracted from
    // https://gitlab.com/leogx9r/ryzen_smu/-/blob/master/userspace/monitor_cpu.c
    // Credit to Leonardo Gates <leogatesx9r@protonmail.com> under GPL V3
    //
    // Could not test myself, as I dont have the hardware. But it should work just fine.
    // Ryzen 3700X / 3800X

    pmt->version = 0x240903;
    pmt->max_cores = 8; //Number of cores supported by this PM table version
    pmt->zen_version = 2; //Zen2

    pmt->PPT_LIMIT                  = pm_element( 0);
    pmt->PPT_VALUE                  = pm_element( 1);
    pmt->TDC_LIMIT                  = pm_element( 2);
    pmt->TDC_VALUE                  = pm_element( 3);
    pmt->THM_LIMIT                  = pm_element( 4);
    pmt->THM_VALUE                  = pm_element( 5);
    pmt->FIT_LIMIT                  = pm_element( 6);
    pmt->FIT_VALUE                  = pm_element( 7);
    pmt->EDC_LIMIT                  = pm_element( 8);
    pmt->EDC_VALUE                  = pm_element( 9);
    pmt->VID_LIMIT                  = pm_element(10);
    pmt->VID_VALUE                  = pm_element(11);

    pmt->PPT_WC                     = pm_element(12);
    pmt->PPT_ACTUAL                 = pm_element(13);
    pmt->TDC_WC                     = pm_element(14);
    pmt->TDC_ACTUAL                 = pm_element(15);
    pmt->THM_WC                     = pm_element(16);
    pmt->THM_ACTUAL                 = pm_element(17);
    pmt->FIT_WC                     = pm_element(18);
    pmt->FIT_ACTUAL                 = pm_element(19);
    pmt->EDC_WC                     = pm_element(20);
    pmt->EDC_ACTUAL                 = pm_element(21);
    pmt->VID_WC                     = pm_element(22);
    pmt->VID_ACTUAL                 = pm_element(23);

    pmt->VDDCR_CPU_POWER            = pm_element(24);
    pmt->VDDCR_SOC_POWER            = pm_element(25);
    pmt->VDDIO_MEM_POWER            = pm_element(26);
    pmt->VDD18_POWER                = pm_element(27);
    pmt->ROC_POWER                  = pm_element(28);
    pmt->SOCKET_POWER               = pm_element(29);
    //pmt->PACKAGE_POWER   = pm_element(29); //PACKAGE_POWER does not exist in this table. It
                                           // *should* be somewhat similar to SOCKET_POWER.
                                           // However, since we show both fields in the output
                                           // there is no use in having it show the exact same
                                           // value two times. So don't set it.

    pmt->PPT_FREQUENCY              = pm_element(30);
    pmt->TDC_FREQUENCY              = pm_element(31);
    pmt->THM_FREQUENCY              = pm_element(32);
    pmt->PROCHOT_FREQUENCY          = pm_element(33);
    pmt->VOLTAGE_FREQUENCY          = pm_element(34);
    pmt->CCA_FREQUENCY              = pm_element(35);

    pmt->FIT_VOLTAGE                = pm_element(36);
    pmt->FIT_PRE_VOLTAGE            = pm_element(37);
    pmt->LATCHUP_VOLTAGE            = pm_element(38);
    pmt->CPU_SET_VOLTAGE            = pm_element(39);
    pmt->CPU_TELEMETRY_VOLTAGE      = pm_element(40);
    pmt->CPU_TELEMETRY_CURRENT      = pm_element(41);
    pmt->CPU_TELEMETRY_POWER        = pm_element(42);
    //CPU_TELEMETRY_POWER_ALT         = pm_element(43);
    pmt->SOC_SET_VOLTAGE            = pm_element(44);
    pmt->SOC_TELEMETRY_VOLTAGE      = pm_element(45);
    pmt->SOC_TELEMETRY_CURRENT      = pm_element(46);
    pmt->SOC_TELEMETRY_POWER        = pm_element(47);

    pmt->FCLK_FREQ                  = pm_element(48);
    pmt->FCLK_FREQ_EFF              = pm_element(49);
    pmt->UCLK_FREQ                  = pm_element(50);
    pmt->MEMCLK_FREQ                = pm_element(51);
    pmt->FCLK_DRAM_SETPOINT         = pm_element(52);
    pmt->FCLK_DRAM_BUSY             = pm_element(53);
    pmt->FCLK_GMI_SETPOINT          = pm_element(54);
    pmt->FCLK_GMI_BUSY              = pm_element(55);
    pmt->FCLK_IOHC_SETPOINT         = pm_element(56);
    pmt->FCLK_IOHC_BUSY             = pm_element(57);
    pmt->FCLK_XGMI_SETPOINT         = pm_element(58);
    pmt->FCLK_XGMI_BUSY             = pm_element(59);

    pmt->CCM_READS                  = pm_element(60);
    pmt->CCM_WRITES                 = pm_element(61);
    pmt->IOMS                       = pm_element(62);
    pmt->XGMI                       = pm_element(63);
    pmt->CS_UMC_READS               = pm_element(64);
    pmt->CS_UMC_WRITES              = pm_element(65);
    assign_pm_elements_4(pmt->FCLK_RESIDENCY,     66,  67,  68,  69);
    assign_pm_elements_4(pmt->FCLK_FREQ_TABLE,    70,  71,  72,  73);
    assign_pm_elements_4(pmt->UCLK_FREQ_TABLE,    74,  75,  76,  77);
    assign_pm_elements_4(pmt->MEMCLK_FREQ_TABLE,  78,  79,  80,  81);
    assign_pm_elements_4(pmt->FCLK_VOLTAGE,       82,  83,  84,  85);

    assign_pm_elements_4(pmt->LCLK_SETPOINT,  86,  92,  98, 104);
    assign_pm_elements_4(pmt->LCLK_BUSY,      87,  93,  99, 105);
    assign_pm_elements_4(pmt->LCLK_FREQ,      88,  94, 100, 106);
    assign_pm_elements_4(pmt->LCLK_FREQ_EFF,  89,  95, 101, 107);
    assign_pm_elements_4(pmt->LCLK_MAX_DPM,   90,  96, 102, 108);
    assign_pm_elements_4(pmt->LCLK_MIN_DPM,   91,  97, 103, 109);

    pmt->XGMI_SETPOINT              = pm_element(110);
    pmt->XGMI_BUSY                  = pm_element(111);
    pmt->XGMI_LANE_WIDTH            = pm_element(112);
    pmt->XGMI_DATA_RATE             = pm_element(113);

    pmt->SOC_POWER                  = pm_element(114);
    pmt->SOC_TEMP                   = pm_element(115);
    pmt->DDR_VDDP_POWER             = pm_element(116);
    pmt->DDR_VDDIO_MEM_POWER        = pm_element(117);
    pmt->GMI2_VDDG_POWER            = pm_element(118);
    pmt->IO_VDDCR_SOC_POWER         = pm_element(119);
    pmt->IOD_VDDIO_MEM_POWER        = pm_element(120);
    pmt->IO_VDD18_POWER             = pm_element(121);
    pmt->TDP                        = pm_element(122);
    pmt->DETERMINISM                = pm_element(123);
    pmt->V_VDDM                     = pm_element(124);
    pmt->V_VDDP                     = pm_element(125);
    pmt->V_VDDG                     = pm_element(126);

    pmt->PEAK_TEMP                  = pm_element(127);
    pmt->PEAK_VOLTAGE               = pm_element(128);
    pmt->AVG_CORE_COUNT             = pm_element(129);
    pmt->CCLK_LIMIT                 = pm_element(130);
    pmt->MAX_SOC_VOLTAGE            = pm_element(131);
    pmt->DC_BTC                     = pm_element(132);
    //pmt->PACKAGE_POWER              = pm_element(xxx); //Does not exist. Use SOCKET_POWER
    pmt->CSTATE_BOOST               = pm_element(133);
    pmt->PROCHOT                    = pm_element(134);
    pmt->PC6                        = pm_element(135);
    pmt->PWM                        = pm_element(136);

    pmt->SOCCLK                     = pm_element(137);
    pmt->SHUBCLK                    = pm_element(138);
    pmt->MP0CLK                     = pm_element(139);
    pmt->MP1CLK                     = pm_element(140);
    pmt->MP5CLK                     = pm_element(141);
    pmt->SMNCLK                     = pm_element(142);
    pmt->TWIXCLK                    = pm_element(143);
    pmt->WAFLCLK                    = pm_element(144);

    pmt->DPM_BUSY                   = pm_element(145);
    pmt->MP1_BUSY                   = pm_element(146);

    assign_pm_elements_8_consec(pmt->CORE_POWER       , 147);
    assign_pm_elements_8_consec(pmt->CORE_VOLTAGE     , 155);
    assign_pm_elements_8_consec(pmt->CORE_TEMP        , 163);
    assign_pm_elements_8_consec(pmt->CORE_FIT         , 171);
    assign_pm_elements_8_consec(pmt->CORE_IDDMAX      , 179);
    assign_pm_elements_8_consec(pmt->CORE_FREQ        , 187);
    assign_pm_elements_8_consec(pmt->CORE_FREQEFF     , 195);
    assign_pm_elements_8_consec(pmt->CORE_C0          , 203);
    assign_pm_elements_8_consec(pmt->CORE_CC1         , 211);
    assign_pm_elements_8_consec(pmt->CORE_CC6         , 219);
    assign_pm_elements_8_consec(pmt->CORE_CKS_FDD     , 227);
    assign_pm_elements_8_consec(pmt->CORE_CI_FDD      , 235);
    assign_pm_elements_8_consec(pmt->CORE_IRM         , 243);
    assign_pm_elements_8_consec(pmt->CORE_PSTATE      , 251);
    assign_pm_elements_8_consec(pmt->CORE_FREQ_LIM_MAX, 259);
    assign_pm_elements_8_consec(pmt->CORE_FREQ_LIM_MIN, 267);
    assign_pm_elements_8_consec(pmt->CORE_SC_LIMIT    , 275);
    assign_pm_elements_8_consec(pmt->CORE_SC_CAC      , 283);
    assign_pm_elements_8_consec(pmt->CORE_SC_RESIDENCY, 291);

    assign_pm_elements_2(pmt->L3_LOGIC_POWER   , 299, 300);
    assign_pm_elements_2(pmt->L3_VDDM_POWER    , 301, 302);
    assign_pm_elements_2(pmt->L3_TEMP          , 303, 304);
    assign_pm_elements_2(pmt->L3_FIT           , 305, 306);
    assign_pm_elements_2(pmt->L3_IDDMAX        , 307, 308);
    assign_pm_elements_2(pmt->L3_FREQ          , 309, 310);
    assign_pm_elements_2(pmt->L3_CKS_FDD       , 311, 312);
    assign_pm_elements_2(pmt->L3_CCA_THRESHOLD , 313, 314);
    assign_pm_elements_2(pmt->L3_CCA_CAC       , 315, 316);
    assign_pm_elements_2(pmt->L3_CCA_ACTIVATION, 317, 318);
    assign_pm_elements_2(pmt->L3_EDC_LIMIT     , 319, 320);
    assign_pm_elements_2(pmt->L3_EDC_CAC       , 321, 322);
    assign_pm_elements_2(pmt->L3_EDC_RESIDENCY , 323, 324);
    pmt->MP5_BUSY[0] = pm_element(325);

    pmt->min_size = 326*4; //(Highest element we access + 1)*4.
                           //Needed to avoid illegal memory access
}

void pm_table_0x240803(pm_table *pmt, void* base_addr) {
    // Ryzen 3950X
    // Could not test myself, as I dont have the hardware. But most values seem reasonable.
    // (Re)constructed using the pm table dumps from 
    // https://github.com/hattedsquirrel/ryzen_monitor/issues/2#

    pmt->version = 0x240803;
    pmt->max_cores = 16; //Number of cores supported by this PM table version
    pmt->max_l3 = 4; //Number of L3 caches supported by this PM table version
    pmt->zen_version = 2; //Zen2

    pmt->PPT_LIMIT                  = pm_element( 0);
    pmt->PPT_VALUE                  = pm_element( 1);
    pmt->TDC_LIMIT                  = pm_element( 2);
    pmt->TDC_VALUE                  = pm_element( 3);
    pmt->THM_LIMIT                  = pm_element( 4);
    pmt->THM_VALUE                  = pm_element( 5);
    pmt->FIT_LIMIT                  = pm_element( 6);
    pmt->FIT_VALUE                  = pm_element( 7);
    pmt->EDC_LIMIT                  = pm_element( 8);
    pmt->EDC_VALUE                  = pm_element( 9);
    pmt->VID_LIMIT                  = pm_element(10);
    pmt->VID_VALUE                  = pm_element(11);

    pmt->PPT_WC                     = pm_element(12);
    pmt->PPT_ACTUAL                 = pm_element(13);
    pmt->TDC_WC                     = pm_element(14);
    pmt->TDC_ACTUAL                 = pm_element(15);
    pmt->THM_WC                     = pm_element(16);
    pmt->THM_ACTUAL                 = pm_element(17);
    pmt->FIT_WC                     = pm_element(18);
    pmt->FIT_ACTUAL                 = pm_element(19);
    pmt->EDC_WC                     = pm_element(20);
    pmt->EDC_ACTUAL                 = pm_element(21);
    pmt->VID_WC                     = pm_element(22);
    pmt->VID_ACTUAL                 = pm_element(23);

    pmt->VDDCR_CPU_POWER            = pm_element(24);
    pmt->VDDCR_SOC_POWER            = pm_element(25);
    pmt->VDDIO_MEM_POWER            = pm_element(26);
    pmt->VDD18_POWER                = pm_element(27);
    pmt->ROC_POWER                  = pm_element(28);
    pmt->SOCKET_POWER               = pm_element(29);
    //pmt->PACKAGE_POWER   = pm_element(29); //PACKAGE_POWER does not exist in this table. It
                                           // *should* be somewhat similar to SOCKET_POWER.
                                           // However, since we show both fields in the output
                                           // there is no use in having it show the exact same
                                           // value two times. So don't set it.

    pmt->PPT_FREQUENCY              = pm_element(30);
    pmt->TDC_FREQUENCY              = pm_element(31);
    pmt->THM_FREQUENCY              = pm_element(32);
    pmt->PROCHOT_FREQUENCY          = pm_element(33);
    pmt->VOLTAGE_FREQUENCY          = pm_element(34);
    pmt->CCA_FREQUENCY              = pm_element(35);

    pmt->FIT_VOLTAGE                = pm_element(37);
    pmt->FIT_PRE_VOLTAGE            = pm_element(38);
    pmt->LATCHUP_VOLTAGE            = pm_element(39);
    pmt->CPU_SET_VOLTAGE            = pm_element(40);
    pmt->CPU_TELEMETRY_VOLTAGE      = pm_element(41);
    pmt->CPU_TELEMETRY_CURRENT      = pm_element(42);
    pmt->CPU_TELEMETRY_POWER        = pm_element(43);
    pmt->SOC_SET_VOLTAGE            = pm_element(44);
    pmt->SOC_TELEMETRY_VOLTAGE      = pm_element(45);
    pmt->SOC_TELEMETRY_CURRENT      = pm_element(46);
    pmt->SOC_TELEMETRY_POWER        = pm_element(47);

    pmt->FCLK_FREQ                  = pm_element(48);
    pmt->FCLK_FREQ_EFF              = pm_element(49);
    pmt->UCLK_FREQ                  = pm_element(50);
    pmt->MEMCLK_FREQ                = pm_element(51);
    pmt->FCLK_DRAM_SETPOINT         = pm_element(52);
    pmt->FCLK_DRAM_BUSY             = pm_element(53);
    pmt->FCLK_GMI_SETPOINT          = pm_element(54);
    pmt->FCLK_GMI_BUSY              = pm_element(55);
    pmt->FCLK_IOHC_SETPOINT         = pm_element(56);
    pmt->FCLK_IOHC_BUSY             = pm_element(57);
    pmt->FCLK_XGMI_SETPOINT         = pm_element(58);
    pmt->FCLK_XGMI_BUSY             = pm_element(59);

    pmt->CCM_READS                  = pm_element(60);
    pmt->CCM_WRITES                 = pm_element(61);
    pmt->IOMS                       = pm_element(62);
    pmt->XGMI                       = pm_element(63);
    pmt->CS_UMC_READS               = pm_element(64);
    pmt->CS_UMC_WRITES              = pm_element(65);
    assign_pm_elements_4(pmt->FCLK_RESIDENCY,     66,  67,  68,  69);
    assign_pm_elements_4(pmt->FCLK_FREQ_TABLE,    70,  71,  72,  73);
    assign_pm_elements_4(pmt->UCLK_FREQ_TABLE,    74,  75,  76,  77);
    assign_pm_elements_4(pmt->MEMCLK_FREQ_TABLE,  78,  79,  80,  81);
    assign_pm_elements_4(pmt->FCLK_VOLTAGE,       82,  83,  84,  85);

    assign_pm_elements_4(pmt->LCLK_SETPOINT,  86,  92,  98, 104);
    assign_pm_elements_4(pmt->LCLK_BUSY,      87,  93,  99, 105);
    assign_pm_elements_4(pmt->LCLK_FREQ,      88,  94, 100, 106);
    assign_pm_elements_4(pmt->LCLK_FREQ_EFF,  89,  95, 101, 107);
    assign_pm_elements_4(pmt->LCLK_MAX_DPM,   90,  96, 102, 108);
    assign_pm_elements_4(pmt->LCLK_MIN_DPM,   91,  97, 103, 109);

    pmt->XGMI_SETPOINT              = pm_element(110);
    pmt->XGMI_BUSY                  = pm_element(111);
    pmt->XGMI_LANE_WIDTH            = pm_element(112);
    pmt->XGMI_DATA_RATE             = pm_element(113);

    pmt->SOC_POWER                  = pm_element(114);
    pmt->SOC_TEMP                   = pm_element(115);
    pmt->DDR_VDDP_POWER             = pm_element(116);
    pmt->DDR_VDDIO_MEM_POWER        = pm_element(117);
    pmt->GMI2_VDDG_POWER            = pm_element(118);
    pmt->IO_VDDCR_SOC_POWER         = pm_element(119);
    pmt->IOD_VDDIO_MEM_POWER        = pm_element(120);
    pmt->IO_VDD18_POWER             = pm_element(121);
    pmt->TDP                        = pm_element(122);
    pmt->DETERMINISM                = pm_element(123);
    pmt->V_VDDM                     = pm_element(124);
    pmt->V_VDDP                     = pm_element(125);
    pmt->V_VDDG                     = pm_element(126);

    pmt->PEAK_TEMP                  = pm_element(127);
    pmt->PEAK_VOLTAGE               = pm_element(128);
    pmt->AVG_CORE_COUNT             = pm_element(129);
    pmt->CCLK_LIMIT                 = pm_element(130);
    pmt->MAX_SOC_VOLTAGE            = pm_element(131);
    pmt->DC_BTC                     = pm_element(132);
    //pmt->PACKAGE_POWER              = pm_element(xxx); //Does not exist. Use SOCKET_POWER
    pmt->CSTATE_BOOST               = pm_element(133);
    pmt->PROCHOT                    = pm_element(134);
    pmt->PC6                        = pm_element(135);
    pmt->PWM                        = pm_element(136);

    pmt->SOCCLK                     = pm_element(137); //elem 137 -> 457.14
    pmt->SHUBCLK                    = pm_element(138); //elem 138 -> 457.14
    pmt->MP0CLK                     = pm_element(139); //elem 139 -> 457.14
    pmt->MP1CLK                     = pm_element(140); //elem 140 -> 457.14
    pmt->MP5CLK                     = pm_element(141); //elem 141 -> 400.00
    pmt->SMNCLK                     = pm_element(142); //elem 142 -> 500.00
    pmt->TWIXCLK                    = pm_element(143); //elem 143 -> 400.00
    pmt->WAFLCLK                    = pm_element(144);

    pmt->DPM_BUSY                   = pm_element(145);
    pmt->MP1_BUSY                   = pm_element(146);

    assign_pm_elements_16_consec(pmt->CORE_POWER       , 147);
    assign_pm_elements_16_consec(pmt->CORE_VOLTAGE     , 163);
    assign_pm_elements_16_consec(pmt->CORE_TEMP        , 179);
    assign_pm_elements_16_consec(pmt->CORE_FIT         , 195);
    assign_pm_elements_16_consec(pmt->CORE_IDDMAX      , 211);
    assign_pm_elements_16_consec(pmt->CORE_FREQ        , 227);
    assign_pm_elements_16_consec(pmt->CORE_FREQEFF     , 243);
    assign_pm_elements_16_consec(pmt->CORE_C0          , 259);
    assign_pm_elements_16_consec(pmt->CORE_CC1         , 275);
    assign_pm_elements_16_consec(pmt->CORE_CC6         , 291);
    assign_pm_elements_16_consec(pmt->CORE_CKS_FDD     , 307);
    assign_pm_elements_16_consec(pmt->CORE_CI_FDD      , 323);
    assign_pm_elements_16_consec(pmt->CORE_IRM         , 339);
    assign_pm_elements_16_consec(pmt->CORE_PSTATE      , 355);
    assign_pm_elements_16_consec(pmt->CORE_FREQ_LIM_MAX, 371);
    assign_pm_elements_16_consec(pmt->CORE_FREQ_LIM_MIN, 387);
    assign_pm_elements_16_consec(pmt->CORE_SC_LIMIT    , 403);
    assign_pm_elements_16_consec(pmt->CORE_SC_CAC      , 419);
    assign_pm_elements_16_consec(pmt->CORE_SC_RESIDENCY, 435);

    assign_pm_elements_4_consec(pmt->L3_LOGIC_POWER   , 451);
    assign_pm_elements_4_consec(pmt->L3_VDDM_POWER    , 455);
    assign_pm_elements_4_consec(pmt->L3_TEMP          , 459);
    assign_pm_elements_4_consec(pmt->L3_FIT           , 463);
    assign_pm_elements_4_consec(pmt->L3_IDDMAX        , 467);
    assign_pm_elements_4_consec(pmt->L3_FREQ          , 471);
    assign_pm_elements_4_consec(pmt->L3_CKS_FDD       , 475);
    assign_pm_elements_4_consec(pmt->L3_CCA_THRESHOLD , 479);
    assign_pm_elements_4_consec(pmt->L3_CCA_CAC       , 483);
    assign_pm_elements_4_consec(pmt->L3_CCA_ACTIVATION, 487);
    assign_pm_elements_4_consec(pmt->L3_EDC_LIMIT     , 491);
    assign_pm_elements_4_consec(pmt->L3_EDC_CAC       , 495);
    assign_pm_elements_4_consec(pmt->L3_EDC_RESIDENCY , 499);
    assign_pm_elements_2(pmt->MP5_BUSY, 503, 504);

    pmt->min_size = 505*4; //(Highest element we access + 1)*4.
                           //Needed to avoid illegal memory access
}
