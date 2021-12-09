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

void pm_table_zenp_cpu(pm_table *pmt, void* base_addr) {
    pmt->version = 0x100100; //Made up
    pmt->max_cores = 8; //Number of cores supported by this PM table version
    pmt->max_l3 = 2; //Number of L3 caches supported by this PM table version
    pmt->zen_version = 1; //Zen+

    pmt->PPT_LIMIT       = pm_element( 0);
    pmt->PPT_VALUE       = pm_element( 1);
    pmt->TDC_LIMIT       = pm_element( 2);
    pmt->TDC_VALUE       = pm_element( 3);
    pmt->EDC_LIMIT       = pm_element( 4);
    // 5 might be fast EDC
    pmt->EDC_VALUE       = pm_element( 6);
    pmt->THM_LIMIT       = pm_element( 7);
    pmt->THM_VALUE       = pm_element( 8);
    pmt->FIT_LIMIT       = pm_element( 9);
    pmt->FIT_VALUE       = pm_element(10);
    pmt->TDP             = pm_element(11);
    pmt->CPU_SET_VOLTAGE = pm_element(12);
    pmt->SOC_SET_VOLTAGE = pm_element(13);
    pmt->V_VDDM          = pm_element(14); //probably
    pmt->V_VDDP          = pm_element(15);
    pmt->VDDCR_CPU_POWER = pm_element(16);
    pmt->VDDCR_SOC_POWER = pm_element(17);

    // 18/19 unknown

    pmt->SOCKET_POWER           = pm_element(20);
    pmt->CPU_TELEMETRY_VOLTAGE  = pm_element(21);
    pmt->CPU_TELEMETRY_CURRENT  = pm_element(22);
    pmt->CPU_TELEMETRY_POWER    = pm_element(23);
    pmt->SOC_TELEMETRY_VOLTAGE  = pm_element(24);
    pmt->SOC_TELEMETRY_CURRENT  = pm_element(25);
    pmt->SOC_TELEMETRY_POWER    = pm_element(26);

    // 28 looks like some multipler? fraction part is always .25/.5/.75/.0
    pmt->PEAK_VOLTAGE           = pm_element(28);
    // 29-32 unknown

    pmt->FCLK_FREQ_EFF = pmt->FCLK_FREQ = pmt->UCLK_FREQ = pmt->MEMCLK_FREQ = pm_element(33); // always coupled on Zen/Zen+
    // 33/34/35/36 might be frequency table?
    // 37-39 unknown

    assign_pm_elements_8_consec(pmt->CORE_POWER       , 40);
    // followed by 8 zeroes, probably something not implemented per core
    assign_pm_elements_8_consec(pmt->CORE_VOLTAGE     , 56); // always the same value, might be wrong
    assign_pm_elements_8_consec(pmt->CORE_TEMP        , 64);
    assign_pm_elements_8_consec(pmt->CORE_FIT         , 72);
    assign_pm_elements_8_consec(pmt->CORE_IDDMAX      , 80);
    assign_pm_elements_8_consec(pmt->CORE_FREQ        , 88);
    assign_pm_elements_8_consec(pmt->CORE_FREQEFF     , 96);
    assign_pm_elements_8_consec(pmt->CORE_C0          , 104);
    assign_pm_elements_8_consec(pmt->CORE_CC1         , 112);
    assign_pm_elements_8_consec(pmt->CORE_CC6         , 120);
    assign_pm_elements_8_consec(pmt->CORE_PSTATE      , 128);

    // Copied from Zen2, seems legit.
    assign_pm_elements_2(pmt->L3_LOGIC_POWER   , 136, 137);
    assign_pm_elements_2(pmt->L3_VDDM_POWER    , 138, 139);
    assign_pm_elements_2(pmt->L3_TEMP          , 140, 141);
    assign_pm_elements_2(pmt->L3_FIT           , 142, 143);
    assign_pm_elements_2(pmt->L3_IDDMAX        , 144, 145);
    assign_pm_elements_2(pmt->L3_FREQ          , 146, 147);

    pmt->SOC_TEMP        = pm_element(148); // maybe
    // 149-154 unknown
    // pmt->PACKAGE_POWER          = pm_element(155);
    // 156-160 unknown
    pmt->PEAK_TEMP       = pm_element(161); // fluctuates a lot, might be wrong.
    // 162 seems like percentage of something remaning, goes down from 100

    pmt->min_size = 148*4; //(Highest element we access + 1)*4.
                           //Needed to avoid illegal memory access

    pmt->PC6 = 0; // Package C6 is broken for Zen+ on Linux, probable one of the always 0 entries at 31/32/157/158
}
