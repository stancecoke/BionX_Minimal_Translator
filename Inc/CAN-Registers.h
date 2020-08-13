#ifndef CANregisters_h
#define CANregisters_h

// NodeId and register for slave mode
#define ID_CONSOLE                  0x08
//#define ID_CONSOLE_MASTER           0x48
#define REG_CONSOLE_STATUS_SLAVE    0xD1

#define ID_BATTERY                  0x10
#define REG_BATTERY_CONFIG_SHUTDOWN 0x25

#define ID_MOTOR                    0x20


/**
{ Copyright (C) 2013 Thorsten Schmidt (tschmidt@ts-soft.de)              }
{     www.ts-soft.de                                                     }
{                                                                        }
{ This program is free software; you can redistribute it and/or modify   }
{ it under the terms of the GNU General Public License as published by   }
{ the Free Software Foundation; either version 2 of the License, or      }
{ (at your option) any later version.                                    }
{                                                                        }
{ This program is distributed in the hope that it will be useful,        }
{ but WITHOUT ANY WARRANTY; without even the implied warranty of         }
{ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          }
{ GNU General Public License for more details.                           }
{                                                                        }
{ You should have received a copy of the GNU General Public License      }
{ along with this program; if not, write to the Free Software            }
{ Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.              }
{                                                                        }
{ Portions of this software are taken and adapted from BigXionFlasher    }
{ published by Thomas König <info@bigxionflasher.org>                    } 
 */

/*
*Constants took from BionX.pas v0.90 (WinGui Bikeinfo)
*/
//const
// allVersions : TVersionInfo = ( sw_since : 0 sw_until : 255 sub_since : 0 sub_until : 255 hw_since : 0 hw_until : 255 )



#define UNLIMITED_SPEED_VALUE                                  70 //Km/h
// UNLIMITED_MIN_SPEED_VALUE                                   30 //Km/h
#define UNLIMITED_THROTTLE_SPEED_VALUE                         70 //Km/h

#define SPEED_FACTOR                                           0.1
#define DISTANCE_FACTOR                                        0.1
#define SENESORGAIN_FACTOR                                     0.1
#define ASSIST_FACTOR                                          1.5625
#define VOLTAGE_FACTOR                                         0.001
#define CURRENT_FACTOR                                         0.001
#define NORMALIZED_VOLTAGE_OFFSET                              20.8333
#define NORMALIZED_VOLTAGE_FAKTOR                              0.416667

//abbreviations:
//  SOC = State Of Charge
//  LMD = Last Measured Discharge
//  NIP = ?

//----  Console
#define ID_CONSOLE_MASTER                                      0x08 //(CAN ID in master mode)
#define ID_CONSOLE_SLAVE                                       0x48 //(CAN ID in slave mode)
#define ID_CONSOLE_RESPONSE                                    0x58
#define ID_BIB                                                 0x58

//Reg 0..79 unused

#define REG_CONSOLE_STATISTIC_DIST_HI                          0x50 //[factor:0.1]
#define REG_CONSOLE_STATISTIC_DIST_LO                          0x51
#define REG_CONSOLE_STATISTIC_AVGSPEED_HI                      0x52 //[factor:0.1]
#define REG_CONSOLE_STATISTIC_AVGSPEED_LO                      0x53

//Reg 84..99 unused

#define REG_CONSOLE_STATISTIC_ODOMETER_HIHI                    0x64 //Odometer [unit:km, faktor:0.1]
#define REG_CONSOLE_STATISTIC_ODOMETER_HILO                    0x65 //!!! reverse byte order on writing !!!
#define REG_CONSOLE_STATISTIC_ODOMOTER_LOHI                    0x66
#define REG_CONSOLE_STATISTIC_ODOMETER_LOLO                    0x67

#define REG_CONSOLE_PREFERENCE_NIP_HIHI                        0x68 //-
#define REG_CONSOLE_PREFERENCE_NIP_HILO                        0x69
#define REG_CONSOLE_PREFERENCE_NIP_LOHI                        0x6A
#define REG_CONSOLE_PREFERENCE_NIP_LOLO                        0x6B
#define REG_CONSOLE_THROTTLE_CALIBRATED                        0x6C //throttle calibration performed
#define REG_CONSOLE_STATISTIC_CHRONO_SECOND                    0x6D //trip time seconds
#define REG_CONSOLE_STATISTIC_CHRONO_MINUTE                    0x6E //trip time minutes
#define REG_CONSOLE_STATISTIC_CHRONO_HOUR                      0x6F //trip time hours
#define REG_CONSOLE_PREFERENCE_LCD_CONTRAST                    0x70 //LCD contrast
#define REG_CONSOLE_SN_LOCATION                                0x71 //location
#define REG_CONSOLE_SN_YEAR                                    0x72 //mfd year
#define REG_CONSOLE_SN_MONTH                                   0x73 //mfd month
#define REG_CONSOLE_SN_DAY                                     0x74 //mfd day

#define REG_CONSOLE_SN_PN_HI                                   0x75 //product number
#define REG_CONSOLE_SN_PN_LO                                   0x76
#define REG_CONSOLE_SN_ITEM_HI                                 0x77 //serial number
#define REG_CONSOLE_SN_ITEM_LO                                 0x78

//Reg 121 unused

#define REG_CONSOLE_ASSIST_GAUGE_JOINT                         0x7A //gauge joint [range:0..11]
#define REG_CONSOLE_THROTTLE_MIN_HI                            0x7B //throttle min actor value
#define REG_CONSOLE_THROTTLE_MIN_LO                            0x7C
#define REG_CONSOLE_THROTTLE_MAX_HI                            0x7D //throttle max actor value
#define REG_CONSOLE_THROTTLE_MAX_LO                            0x7E

//Reg 127 unused

#define REG_CONSOLE_PREFERENCE_LIGHT_ON_AT_START               0x80 //LightOnAtStart Indicate if the accessory shall be enabled when turning the bike on. 0-No, 1-Yes

#define REG_CONSOLE_GEOMETRY_CIRC_HI                           0x81 //Circumference of the rear wheel [mm]
#define REG_CONSOLE_GEOMETRY_CIRC_LO                           0x82

#define REG_CONSOLE_ASSIST_MAXSPEED_FLAG                       0x83 //Indicates that there is an upper speed limit where the motor is allowed to assist
#define REG_CONSOLE_ASSIST_MAXSPEED_HI                         0x84 //Maximum speed for which the motor can assist. This is irrelevant if maxSpeedFlag is not set [unit:km/h, range:1..??, factor:0.1] (Code 3773)
#define REG_CONSOLE_ASSIST_MAXSPEED_LO                         0x85

#define REG_CONSOLE_THROTTLE_MAXSPEED_FLAG                     0x86 //throttle max speed flag
#define REG_CONSOLE_THROTTLE_MAXSPEED_HI                       0x87 //throttle max speed MSB [unit:km/h, factor:0.1] Code 3775
#define REG_CONSOLE_THROTTLE_MAXSPEED_LO                       0x88
#define REG_CONSOLE_ASSIST_MINSPEED_FLAG                       0x89 //min speed flag
#define REG_CONSOLE_ASSIST_MINSPEED                            0x8A //min speed Code 3776

#define REG_CONSOLE_ASSIST_BRAKE_LEVEL                         0x8B //brake rekuperation level [unit:%, range:0..64, factor:1.5625] Code 2002
#define REG_CONSOLE_PREFERENCE_TRIP_TO_EMPTY_FLAG              0x8C //0:hide, 1:show remaining time/dist PC2003 (no effect anymore?)
#define REG_CONSOLE_PREFERENCE_DISPLAY_UNITS                   0x8D //Indicates unit system to use when displaying units. 0-English, 1-Metric
#define REG_CONSOLE_THROTTLE_ENABLE_ONSTRAIN                   0x8E //Allow throttle over maxSpeed if strain gauge signal detected

//Reg 143..159 unused

#define REG_CONSOLE_ASSIST_BRAKE_FLAG                          0xA0 //brage sensor enable 0: brake sensor off, 1: sensor on  Code 2006
#define REG_CONSOLE_ASSIST_BRAKE_POLARITY                      0xA1 //brake sensor type:   0: NO (Normal Open), 1: NC (Normal Closed), 2:0-5 (analog 0..5V), 3:5-0 (analog 5..0V) Code 2006
#define REG_CONSOLE_ASSIST_GAUGE_FILTER                        0xA2 //Torque sensor speed  [range:0..8 (1..4 recommended)] Code 1234

#define REG_CONSOLE_REV_SW                                     0xA3 //software version

#define REG_CONSOLE_ASSIST_GAUGE_GAIN                          0xA4 //sensor gain [range:0.1..4.0, factor:0.1] Code 0007
#define REG_CONSOLE_ASSIST_GAIN_A                              0xA5 //torque sensor extra gain [range:0.1..4.0, factor:0.1] Code 0008a
#define REG_CONSOLE_ASSIST_GAIN_B                              0xA6 //torque sensor extra gain max speed [unit:km/h, range:0.0..25.0, factor:0.1] Code 0008b
#define REG_CONSOLE_SN_TYPE                                    0xA7 //Type of console: 0-EPS, 1-RIDE+, 2-Boost.
#define REG_CONSOLE_PREFERENCE_REGION                          0xA8 //region
#define REG_CONSOLE_PREFERENCE_CONFIGBIT_0                     0xA9 //ConfigBit0
#define REG_CONSOLE_THROTTLE_ENABLE_BOOST_DISPLAY              0xAA //Display the "boost" message or pictogram when it activates
#define REG_CONSOLE_ASSIST_AUTOREGEN_FLAG                      0xAB //Autoregen Flag

//Reg 172 unused                                       //RegenEnabled, yet unused

#define REG_CONSOLE_REV_SUB                                    0xAD //software subversion
#define REG_CONSOLE_PREFERENCE_LIGHT_BUTTON_MODE               0xAE //Indicate the operation of console button "light/power". 0-Click turns bike off, hold toggles accessory 1-Click toggle accessory, hold turns bike off
#define REG_CONSOLE_PREFERENCE_EXPERTMODE                      0xAF //ExpertMode Add new display mode for expert mode (unitl hw 15)

#define REG_CONSOLE_ASSIST_LEVEL_1                             0xB0 //assist level 1 [unit:%, factor:1,5625]
#define REG_CONSOLE_ASSIST_LEVEL_2                             0xB1 //assist level 2 [unit:%, factor:1,5625]
#define REG_CONSOLE_ASSIST_LEVEL_3                             0xB2 //assist level 3 [unit:%, factor:1,5625]
#define REG_CONSOLE_ASSIST_LEVEL_4                             0xB3 //assist level 4 [unit:%, factor:1,5625]
#define REG_CONSOLE_ASSIST_INITLEVEL                           0xB4 //initial assist level [range:0..4]

#define REG_CONSOLE_PREFERENCE_CODES_HIHI                      0xB5 //Codes LSB 0-(3771, 2005)Wheel circumference, 1-(3772)Diagnostic mode, 2-(3773)Max speed, 3-(3774)Overvoltage protection, 4-(3775)Max throttle speed, 5-(3776)Minimum assist speed, 6-(1976)Motor direction, 7-(5000)Deprecated, 8-(2001)metric vs imperial, 9-(2002)Regen value, 10-(2003)Remaining distance, 11-(2004)Clock time, 12-(2006)Brake switch config, 13-(2007)Throttle polarity, 14-(2008)Accessory voltage, 15-(0041)Slave console, 16-(1234)Filter, 17-(1970)Light sensor, 18-(0007)Gauge gain, 19-(0008)Assistance gain, 20-(0009)Gauge joint, 21-(0911)Deprecated, 22-(0001)Console info, 23-(0002)Battery info, 24-(0003)Motor info, 25-(6000)Battery statistics, 26-(0006)Speed gain, 27-Alarm, 28-Time
#define REG_CONSOLE_PREFERENCE_CODES_HILO                      0xB6
#define REG_CONSOLE_PREFERENCE_CODES_LOHI                      0xB7
#define REG_CONSOLE_PREFERENCE_CODES_LOLO                      0xB8
#define REG_CONSOLE_PREFERENCE_CODESRW_HIHI                    0xB9 //CodesRW LSB Same bit as console.preference.codes except for: 28-Mountain mode
#define REG_CONSOLE_PREFERENCE_CODESRW_HILO                    0xBA
#define REG_CONSOLE_PREFERENCE_CODESRW_LOHI                    0xBB
#define REG_CONSOLE_PREFERENCE_CODESRW_LOLO                    0xBC
#define REG_CONSOLE_SN_OEM_HI                                  0xBD //OEM
#define REG_CONSOLE_SN_OEM_LO                                  0xBE
#define REG_CONSOLE_PREFERENCE_THROTTLE_MODE                   0xBF //ThrottleMode Configure the throttle for the menu change mode (until hw 15)
#define REG_CONSOLE_ASSIST_SPEEDGAIN                           0xC0 //[ factor:0,1 ]
#define REG_CONSOLE_SN_PRODUCT_HI                              0xC1 //product
#define REG_CONSOLE_SN_PRODUCT_LO                              0xC2
#define REG_CONSOLE_THROTTLE_BOOST_TRIGGERLEVEL                0xC3 //Boost Trigger Level [unit:%, range:1.5..50, factor:1.5625] Code 3779
#define REG_CONSOLE_PREFERENCE_FLIP_SIDE                       0xC4 //Indicates on what side of the handlebar is located the console. 0-Right, 1-Left Code 2009
#define REG_CONSOLE_CONFIG_TESTMODE                            0xC5 //Writing a 1 to this register allows setting the console in test mode to test the LCD and buttons
#define REG_CONSOLE_CONFIG_TESTMODE_HW14                       0xC3 //Reg C3 with HW14

#define REG_CONSOLE_ASSIST_MOUNTAIN_CAP                        0xC6 //Maximum set point to send to motor when in mountain mode. 0-Disabled [unit:%, range:0..100, faktor:1.5625]
#define REG_CONSOLE_CONFIG_LAST_MODE                           0xC7 //Writing 255 will disable the last mode on display power on, 0 will enable the last mode on display power on
#define CONSOLE_CONFIG_LAST_MODE_ON                            0x00
#define CONSOLE_CONFIG_LAST_MODE_OFF                           0xFF

//Reg 200..207 unused

#define REG_CONSOLE_REV_HW                                     0xD0 //hardware version
#define REG_CONSOLE_STATUS_SLAVE                               0xD1 //Writing a 1 to this register allows going imemdiatly in slave mode, cannot be set to 0

#define REG_CONSOLE_THROTTLE_RAW_HI                            0xD2 //throttle raw position
#define REG_CONSOLE_THROTTLE_RAW_LO                            0xD3
#define REG_CONSOLE_THROTTLE_POSITION                          0xD4 //throttle position [factor:1.5625]

//Reg 213 unused                                           //outdated, formerly used by pref. language
//Reg 214 unused                                           //and boat related. Now no data from regs.

#define REG_CONSOLE_ASSIST_LEVEL_REKUPERATION_3                0xD7 //215 Reku Level 3 [unit:%, factor:1,5625]
#define REG_CONSOLE_ASSIST_LEVEL_REKUPERATION_4                0xD8 //216 Reku Level 4 [unit:%, factor:1,5625]
#define REG_CONSOLE_CONFIG_SERVICE_TIMESTAMP_HI                0xD9 //Day, in battery-relative value, from which console displays "service". 0 to disable the feature
#define REG_CONSOLE_CONFIG_SERVICE_ZIMESTAMP_LO                0xDA
#define REG_CONSOLE_CONFIG_SERVICE_DISTANCE_HI                 0xDB //Odometer value, from which console displays "service". 0 to disable the feature
#define REG_CONSOLE_CONFIG_SERVICE_DISTANCE_LO                 0xDC

//Reg 211 unused

#define REG_CONSOLE_ASSIST_LEVEL_REKUPERATION_1                0xDE //Reku Level 1 [unit:%, factor:1,5625]
#define REG_CONSOLE_ASSIST_LEVEL_REKUPERATION_2                0xDF //Reku level 2 [unit:%, factor:1,5625]

//Reg 224..255 unused
//----  /Console

//----  Battery
#define ID_BATTERY                                             0x10

#define ID_BATTERY_RESPONSE                                    0x08
#define REG_BATTERY_CONFIG_ALLOW_BUCKCHARGING_ON_BIKE          0x12 //Specifies if the battery can recharge in buck mode even on a bike. Make sure it is IMPOSSIBLE to have an accessory output before setting this to 1. 0: Disallow, 1: Allow
#define REG_BATTERY_STATUS_CHARGER_MANAGER_STATUS              0x13 //Gives state of charging Mef: 0-Off, 1-Stand-by, 2-Charger, 3-Accessory, 4-Vdcin sense, 5-Overtemp, 6-Charge done, 7-Buck failed
#define REG_BATTERY_CONFIG_WAKE_ON_POWERVOLTAGE                0x14 //Specifies if the battery should wake up automatically when a voltage is present on the vPower. A value of 0 disables the feature

#define REG_BATTERY_CONFIG_SLA_CONSTANT_A                      0x15 //++++ Boat related (SOC estimator)
#define REG_BATTERY_CONFIG_SLA_CONSTANT_B                      0x16 //++++ Boat related (SOC estimator)
#define REG_BATTERY_CONFIG_SLA_CONSTANT_C                      0x15 //++++ Boat related (SOC estimator)

#define REG_BATTERY_REV_SUB                                    0x18 //software subversion

#define REG_BATTERY_CONFIG_SLA_CONSTANT_D                      0x15 //++++ Boat related (SOC estimator)

#define REG_BATTERY_RTC_LAST_VALID_TIMESTAMP_HIHI              0x19 //Indicates last valid battery time. This read-only register is set to rtc.time when written and then refresh each 34 minutes
#define REG_BATTERY_RTC_LAST_VALID_TIMESTAMP_HILO              0x1A
#define REG_BATTERY_RTC_LAST_VALID_TIMESTAMP_LOHI              0x1B
#define REG_BATTERY_RTC_LAST_VALID_TIMESTAMP_LOLO              0x1C

#define REG_BATTERY_STATUS_FLAGS_HI                            0x1D //Alert status bits: 0-Vctrl (code 20), 1-Precharge (code 21 and 67), 2-Relay (code 22), 3-BMS (code 23), 4-DCDC (code 28), 6-GG out of range temperature, 7-battery pack out of range temperature, 8-balancer overvolt (code 62), 9-Balancer undervolt (code 61), 10-Pack problem (code 63), 11-Accessory overcurrent (code 60), 12-Electronic fuse (code 66), 13-Balancer plug not connected, 14- +5v short(lached)

#define REG_BATTERY_STATUS_CELLPACK_CURRENT_HI                 0x1E //Reading battery current by a shunt resistor. No delay, no calibration compared to battery.gg.ai [unit:A, factor:0.001]
#define REG_BATTERY_STATUS_CELLPACK_CURRENT_LO                 0x1F //!!! signed !!!

#define REG_BATTERY_CONFIG_POWER_VOLTAGE_ENABLE                0x21 //- ??? Enable/Disable vPower ???

#define REG_BATTERY_CONFIG_ACCESSORY_ENABLED                   0x22 //-

#define REG_BATTERY_CONFIG_SHUTDOWN                            0x25 //write 1 to shutdwon system

#define REG_BATTERY_CONFIG_CONTROL_VOLTAGE_ENABLE              0x26 //Enable/Disable vControl

#define REG_BATTERY_CONFIG_ACCESSORY_VOLTAGE                   0x28 //- until hw 52 [unit:V, factor:6]
                                                                //  since hw 60 [unit:V, factor:0.1]

#define REG_BATTERY_CONFIG_CAP_SENSE_MODE                      0x29 //Controls the mode of operation of the SoC level indicator. 0: Inactive, 1: Touch detect when the battery is OFF, 2: Touch detect when OFF and SoC indication when battery is ON. 3: red and blue colors . 4: 5levels SoC

#define REG_BATTERY_CONFIG_COMMUNICATION_MODE                  0x2A //Determines how the battery communicates. To change the value, we must first write 0xaa to this register and then write 1 to switch to I2C or 2 to switch to CAN
#define BATTERY_CONFIG_COMMUNICATION_MODE_KEY                  0xAA

#define REG_BATTERY_STATUS_ESTIMATED_SOC                       0x30 //Return an estimated value of SOC based on battery voltage. Only works with LiIon battery [unit:%]

#define REG_BATTERY_STATUS_BATTERY_VOLTAGE_NORMALIZED          0x32 //Battery voltage normalized with 3.7V/cell. status.vBattInternal it used in Rev 104 and less otherwise status.vBatt [unit:V, factor:0.416667, offset:20.8333]
#define REG_BATTERY_STATISTIC_BATTERY_AVGVOLTAGE_NORMALIZED    0x33 //Average battery voltage read during 50s based on battery.status.vBatt, in percentage of its nominal voltage [unit:V, factor:0.416667, offset:20.8333]

#define REG_BATTERY_CONFIG_SHIPMODE                            0x37 //Determines if the battery is to go in ship mode (only external power can wake it) upon its next shutdown. We need to first write 0xaa and then the desired value to set the value. 0-Normal mode, 1-Ship mode
#define BATTERY_CONFIG_SHIPMODE_KEY                            0xAA

#define REG_BATTERY_REV_HW                                     0x3B //hardware version
#define REG_BATTERY_REV_SW                                     0x3C //software versin

#define REG_BATTERY_CONFIG_TYPE                                0x3D //-

#define REG_BATTERY_REV_BOM                                    0x41 //Identification of printed circuit board bill of material version. 1: All smc6.2 and SMC#6.3r1. 8: SMC#6.3r4

#define REG_BATTERY_CONFIG_TAILLAMP_INTENSITY                  0x43 //Controls the intensity of the tail Lamp. 0: OFF. 1-100%: On

#define REG_BATTERY_CONFIG_ACCESSORY_MOUNTED                   0x44 //-

#define REG_BATTERY_CONFIG_BATTINT_VOLTAGE_ENABLE              0x45 //Enable/Disable vBattInt

#define REG_BATTERY_CONFIG_DIAG                                0x46 //-

#define REG_BATTERY_CONFIG_FORCE_DONE                          0x47 //++++ Setting this register to 0x45 will force SOC to 100%
#define BATTERY_CONFIG_FORCE_DONE                              0x45

#define REG_BATTERY_STATISTIC_RESETS_HI                        0x48 //reset counter
#define REG_BATTERY_STATISTIC_RESETS_LO                        0x49

#define REG_BATTERY_STATUS_INTERNAL_BATTERY_VOLTAGE_HI         0x4A //Reading of vBattInternal [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_INTERNAL_BATTERY_VOLTAGE_LO         0x4B

#define REG_BATTERY_STATUS_CONSOLE_VOLTAGE_HI                  0x4C //Reading of vConsole (voltage applied to console) [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_CONSOLE_VOLTAGE_LO                  0x4D

#define REG_BATTERY_STATUS_12V_VOLTAGE_HI                      0x4E //Reading of internal 12V [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_12V_VOLTAGE_LO                      0x4F

#define REG_BATTERY_CONFIG_NOMINAL_BATTERY_VOLTAGE             0x50 //Battery system nominal voltage

#define REG_BATTERY_TIMER_POWER_HI                             0x51 //Time before the power output shuts down [unit:s]
#define REG_BATTERY_TIMER_POWER_LO                             0x52
#define REG_BATTERY_TIMER_ACCESSORY_HI                         0x53 //Time before the accessory voltage shuts down [unit:s]
#define REG_BATTERY_TIMER_ACCESSORY_LO                         0x54
#define REG_BATTERY_TIMER_PRECHARGE                            0x55 //Time allowed to precharge the motor, before enabling full power [unit:s]
#define REG_BATTERY_TIMER_SHUTDOWN_HI                          0x56 //Time of inactivity before the system shuts down [unit:s]
#define REG_BATTERY_TIMER_SHUTDOWN_LO                          0x57

#define REG_BATTERY_SN_LOCATION                                0x5B //location

#define REG_BATTERY_STATUS_ACCESSORY_VOLTAGE_HI                0x5E //Reading of vAccessory [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_ACCESSORY_VOLTAGE_LO                0x5F

#define REG_BATTERY_STATUS_CHARGE_LEVEL                        0x61 //Batterylevel [unit:%, factor:6.6667]
#define REG_BATTERY_CELLMON_BALANCER_ENABLED                   0x65 //

#define REG_BATTERY_STATUS_TEMPERATURE_SENSOR_1                0x66 //[unit:C]
#define REG_BATTERY_STATUS_TEMPERATURE_SENSOR_2                0x67 //!!! signed !!!
#define REG_BATTERY_STATUS_TEMPERATURE_SENSOR_3                0x68
#define REG_BATTERY_STATUS_TEMPERATURE_SENSOR_4                0x69

#define REG_BATTERY_SN_CELLPACK_HI                             0x6A //serial number cellpack
#define REG_BATTERY_SN_CELLPACK_LO                             0x6B

#define REG_BATTERY_CELLMON_CHANNEL_ADDRESS                    0x6C //gateway to cell monitor write address here
#define REG_BATTERY_CELLMON_CHANNELDATA_HI                     0x6D //and read 16 bit voltages here
#define REG_BATTERY_CELLMON_CHANNELDATA_LO                     0x6E //and here

#define REG_BATTERY_CELLMON_CALIBRATION_DATA_LO                0x6F //cell calibration data, select cell via #define REG_BATTERY_CELLMON_CHANNEL register
                                                                  	//since hw 60, sw 103 16 bit values are provided, see #define REG_BATTERY_CALIBRATION_DATA_HI below
#define REG_BATTERY_PROTECT_UNLOCK                             0x71
#define BATTERY_PROTECT_LOCK_KEY                               0x00
#define BATTERY_PROTECT_UNLOCK_KEY                             0xAA

#define REG_BATTERY_SN_YEAR                                    0x72 //mfd. year
#define REG_BATTERY_SN_MONTH                                   0x73 //mfd. month
#define REG_BATTERY_SN_DAY                                     0x74 //mfd day

#define REG_BATTERY_SN_PN_HI                                   0x75 //part number
#define REG_BATTERY_SN_PN_LO                                   0x76
#define REG_BATTERY_SN_ITEM_HI                                 0x77 //serial number
#define REG_BATTERY_SN_ITEM_LO                                 0x78

#define REG_BATTERY_CELLMON_CALIBRATION_DATA_HI                0x7C //refer #define REG_BATTERY_CALIBRATION_DATA_LO above

#define REG_BATTERY_STATUS_POWERON_RESET_COUNT                 0x7D //Return how many time main microcontroller hardly reset

#define REG_BATTERY_CONFIG_AUTOSWITCH_COMMUNICATION            0x7E //++++ Allow to switch communication mode without shutdown. Write 0xAA, then 0x01. Comm. mode switches. Communicate with desired comm. mode before 5s (100ms min) to validate. Write 0 to desactivate
#define BATTERY_CONFIG_AUTOSWITCH_COMMUNICATION_KEY            0xAA

#define REG_BATTERY_BRIGDE_CHARGER_ADDR                        0x85 //gateway to charger write address here (needs unlocking)
#define REG_BATTERY_BRIGDE_CHARGER_DATA                        0x86 //and read data here

#define REG_BATTERY_STATUS_LEDS                                0x87 //-

#define REG_BATTERY_STATISTIC_CHARGETIME_MEAN_HI               0x8A //-
#define REG_BATTERY_STATISTIC_CHARGETIME_MEAN_LO               0x8B //-
#define REG_BATTERY_STATISTIC_CHARGETIME_WORST_HI              0x8C //-
#define REG_BATTERY_STATISTIC_CHARGETIME_WORST_LO              0x8D //-

#define REG_BATTERY_STATISTIC_BATTERY_CYCLES_HI                0x8E //- battery charge cycles
#define REG_BATTERY_STATISTIC_BATTERY_CYCLES_LO                0x8F //-

#define REG_BATTERY_STATISTIC_RTC_RESYNC                       0x90 //-
#define REG_BATTERY_STATISTIC_LMD_ADAPT                        0x91 //-

#define REG_BATTERY_STATISTIC_BATTERY_FULL_CYCLES_HI           0x92 //- battery full charge cycles
#define REG_BATTERY_STATISTIC_BATTERY_FULL_CYCLES_LO           0x93 //-

#define REG_BATTERY_STATISTIC_POWER_CYCLES_HI                  0x96 //Power on cycles
#define REG_BATTERY_STATISTIC_POWER_CYCLES_LO                  0x97 //-

#define REG_BATTERY_STATISTIC_BATTERY_MAX_VOLTAGE              0x98 //Maximum voltage ever seen by the battery, in percentage of its nominal voltage [unit:%, factor:0.416667, offset:20.8333]
#define REG_BATTERY_STATISTIC_BATTERY_MIN_VOLTAGE              0x99 //Minimum voltage ever seen by the battery, in percentage of its nominal voltage [unit:%, factor:0.416667, offset:20.8333]

#define REG_BATTERY_STATUS_DCIN_VOLTAGE_HI                     0x9A //Reading of external power supply voltage [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_DCIN_VOLTAGE_LO                     0x9B

#define REG_BATTERY_STATISTIC_TEMPERATURE_MAX                  0x9C //- !!! signed !!!
#define REG_BATTERY_STATISTIC_TEMPERATURE_MIN                  0x9D //- !!! signed !!!

#define REG_BATTERY_STATISTIC_CONTROL_VOLTAGE_SHORTS           0x9E //until hw 52, now via I2C bridge

#define REG_BATTERY_STATISTIC_WATCHDOG_RESET_COUNT             0x9F //Return how many time watchdog reset trigged
#define REG_BATTERY_STATUS_RESET_WDT                           0x9F //- same as above?

#define REG_BATTERY_RTC_CTRL                                   0xA0 //-

#define REG_BATTERY_RTC_TIME_HIHI                              0xA1 //Indicates current battery time in seconds. Its value is normally relative to assembly time
#define REG_BATTERY_RTC_TIME_HILO                              0xA2
#define REG_BATTERY_RTC_TIME_LOHI                              0xA3
#define REG_BATTERY_RTC_TIME_LOLO                              0xA4

#define REG_BATTERY_RTC_STATUS                                 0xA5 //Describes the status of the RTC: 0-in sync, 1-Write ok, 2-Read ok, 3-Update time, 4-Update ctrl, 5-Osc ok, 7-RTC detected

#define REG_BATTERY_STATUS_BATTERY_VOLTAGE_HI                  0xA6 //Reading of vBatt. Return same value as vCell13 [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_BATTERY_VOLTAGE_LO                  0xA7

#define REG_BATTERY_STATUS_POWER_VOLTAGE_HI                    0xAA //Reading of vPower ("High" voltage applied to motor) [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_POWER_VOLTAGE_LO                    0xAB

#define REG_BATTERY_STATUS_CONTROL_VOLTAGE_HI                  0xAC //Reading of vControl (Control voltage applied to motor) [unit:V, factor:0.001]
#define REG_BATTERY_STATUS_CONTROL_VOLTAGE_LO                  0xAD

#define REG_BATTERY_CONFIG_PACK_SERIAL                         0xAE //no of cells in serial
#define REG_BATTERY_CONFIG_PACK_PARALLEL                       0xAF //no of cells in parallel

#define REG_BATTERY_GASGAGE_DMFSD                              0xB5 //Digital Magnitude Filter and Self Discharge rate

#define REG_BATTERY_CONFIG_ILMD                                0xB9 //- [unit:Ah, factor:0.54835]

#define REG_BATTERY_GASGAGE_SOC                                0xBC //- [unit:%]

#define REG_BATTERY_GASGAGE_AI_HI                              0xD3 //- [unit:A, factor:0.002141]
#define REG_BATTERY_GASGAGE_AI_LO                              0xD4

#define REG_BATTERY_STATISTIC_LMD_HI                           0xD5 //- [unit:Ah, factor:0.002142]
#define REG_BATTERY_STATISTIC_LMD_LO                           0xD6
#define REG_BATTERY_GASGAGE_LMD_HI                             0xD5 //- [unit:Ah, factor:0.002142]
#define REG_BATTERY_GASGAGE_LMD_LO                             0xD6

#define REG_BATTERY_CONFIG_NAC_RADDR_HI                        0xDB //-
#define REG_BATTERY_CONFIG_NAC_RADDR_LO                        0xDC

#define REG_BATTERY_GASGAGE_STATUS_FLAGS                       0xDE //-

#define REG_BATTERY_GASGAGE_VOLTAGE_HI                         0xDF //- [unit:V, factor:0.008]
#define REG_BATTERY_GASGAGE_VOLTAGE_LO                         0xE0

#define REG_BATTERY_GASGAGE_TEMPERATUR_HI                      0xE1 //- [unit:C, factor:0.25, offset:-273]
#define REG_BATTERY_GASGAGE_TEMPERATUR_LO                      0xE2

#define REG_BATTERY_STATISTIC_GGJR_CALIB                       0xEC //-

#define REG_BATTERY_GASGAGE_VOLTAGE_DIVIDER                    0xED //Gas gage external divider value. Indicates how the voltage is divided before reaching the GG. For example, if the battery voltage is 30V and this register is 10, the GG will have 3V at its input [factor:0.1]

#define REG_BATTERY_CONFIG_NAC_HI                              0xE5 //-
#define REG_BATTERY_CONFIG_NAC_LO                              0xE6

#define REG_BATTERY_PROTECT_MODE                               0xE7 //-
#define REG_BATTERY_PROTECT_CONTROL                            0xE8 //-

#define REG_BATTERY_STATUS_FLAGS_LO                            0xF0 //Alert status bits: 0-Vctrl (code 20), 1-Precharge (code 21 and 67), 2-Relay (code 22), 3-BMS (code 23), 4-DCDC (code 28), 6-GG out of range temperature, 7-battery pack out of range temperature, 8-balancer overvolt (code 62), 9-Balancer undervolt (code 61), 10-Pack problem (code 63), 11-Accessory overcurrent (code 60), 12-Electronic fuse (code 66), 13-Balancer plug not connected, 14- +5v short(lached)

#define REG_BATTERY_RTC_LAST_CHARGE_TIMESTAMP_HIHI             0xF2 //Written on boot-up and shutdown, this register indicates when last minimum 10% charge was completed
#define REG_BATTERY_RTC_LAST_CHARGE_TIMESTAMP_HILO             0xF3
#define REG_BATTERY_RTC_LAST_CHARGE_TIMESTAMP_LOHI             0xF4
#define REG_BATTERY_RTC_LAST_CHARGE_TIMESTAMP_LOLO             0xF5

#define REG_BATTERY_STATISTIC_CHARGE_TIMES_CHANNEL             0xF6 //Indicates which charge statistic should be accessed when accessing chargeData. Value can be any value between 1 and 9, 1 being for 10% stat and 9 for 90% stat
#define REG_BATTERY_STATISTIC_CHARGE_TIMES_DATA_HI             0xF7
#define REG_BATTERY_STATISTIC_CHARGE_TIMES_DATA_LO             0xF8

#define REG_BATTERY_CONFIG_MAX_CHARGE_HI                       0xF9 //Maximum regen. current on vPower [unit:A, factor:0.001]
#define REG_BATTERY_CONFIG_MAX_CHARGE_LO                       0xFA

#define REG_BATTERY_CONFIG_MAX_DISCHARGE_HI                    0xFB //Maximum drawn current on vPower [unit:A, factor:0.001]
#define REG_BATTERY_CONFIG_MAX_DISCHARGE_LO                    0xFC

#define REG_BATTERY_CONFIG_CELLCAPACITY_HI                     0xFD //- [unit:Ah, factor:0.001]
#define REG_BATTERY_CONFIG_CELLCAPACITY_LO                     0xFE


#define REG_BATTERY_BRIDGE_I2C_REGADDR_DEVICE                  0x58 //gateway to I2C registers write device (highbyte) here,
#define REG_BATTERY_BRIDGE_I2C_REGADDR_REGISTER                0x70 //register (lowbyte) here
#define REG_BATTERY_BRIDGE_I2C_REGISTER_DATA                   0x60 //and read data here

  //battery i2c bus divices and registers highbyte:device, lowbyte register

#define REG_I2C_CONFIG_CHARGER_VOLTAGE_CALIBRATION_VALUE_HI    0xA007 //Contains voltage calibration value of the charger. This value is written at each charge if bit 0 of _chargerCalibrationSourceFlags is set
#define REG_I2C_CONFIG_CHARGER_VOLTAGE_CALIBRATION_VALUE_LO    0xA008

#define REG_I2C_CONFIG_CHARGER_CURRENT_CALIBRATION_VALUE_HI    0xA009 //Contains current calibration value of the charger. This value is written at each charge if bit 1 of _chargerCalibrationSourceFlags is set
#define REG_I2C_CONFIG_CHARGER_CURRENT_CALIBRATION_VALUE_LO    0xA00A

#define REG_I2C_CONFIG_CHARGER_CALIBRATION_SOURCE_FLAGS        0xA00B //Controls charger calibration values source. 0xFF:Autocalibration value, Bit0 set:Voltage calibration value from EEPROM, Bit1 set:Current calibration from EEPROM

#define REG_I2C_CALIBRATION_3V3_VOLTAGE_HI                     0xA01C //SMC6 ADC reference calibration (nominal value = 3V3) [factor:0.001]
#define REG_I2C_CALIBRATION_3V3_VOLTAGE_LO                     0xA01D

#define REG_I2C_CALIBRATION_CAPSENSE                           0xA030 //Sensitivity of the capsensing detection. 1 is less sensitive, 10 is most sensitive [range:1..10,factor:-0.2, offset:12]

#define REG_I2C_CONFIG_MAX_CELL_DELTA_VOLTAGE                  0xA038 //Delta voltage, between the lowest and the highest cell in the pack, over which the balancer is activated. 0.255 means 0.125 [unit:V, range:25..250, factor:0.001]

#define REG_I2C_STATISTIC_LOWVOLTAGE_BUZZER_COUNT_HI           0xA03A //Number of times the buzzer did emit a sound because of a low battery
#define REG_I2C_STATISTIC_LOWVOLTAGE_BUZZER_COUNT_LO           0xA03B

#define REG_I2C_STATISTIC_CELL_DEAD_SHORT_COUNT_HI             0xA04A //Number of times the charging process detected a cell that is dead short
#define REG_I2C_STATISTIC_CELL_DEAD_SHORT_COUNT_LO             0xA04B

#define REG_I2C_STATISTIC_CELL_PARTIAL_SHORT_COUNT_HI          0xA04C //Number of times the charging process detected a cell that is partially short
#define REG_I2C_STATISTIC_CELL_PARTIAL_SHORT_COUNT_LO          0xA04D

#define REG_I2C_STATISTIC_CELLVOLTAGE_COLLAPSE_COUNT_HI        0xA04E //Number of times the charging process detected a cell for which the voltage collapsed
#define REG_I2C_STATISTIC_CELLVOLTAGE_COLLAPSE_COUNT_LO        0xA04F

#define REG_I2C_CONFIG_GASGAGE_TEMPERATURE_MIN                 0xA052 //Temperature of the gaz gauge (board) under which the power gets interrupted. 255 means -30 [unit:C, range:-40..0] !!! signed !!!
#define REG_I2C_CONFIG_GASGAGE_TEMPERATURE_MAX                 0xA053 //Temperature of the gaz gauge (board) over which the power gets interrupted. 255 means 85 [unit:C, range:35..100] !!! signed !!!

#define REG_I2C_CONFIG_PACK_TEMPERATURE_MIN                    0xA054 //Temperature of the cell pack under which the power gets interrupted. 255 means -30 [unit:C, range:-40..0] !!! signed !!!
#define REG_I2C_CONFIG_PACK_TEMPERATURE_MAX                    0xA055 //Temperature of the cell pack over which the power gets interrupted. 255 means 60 [unit:C, range:30..90] !!! signed !!!

#define REG_I2C_STATISTIC_CONTROL_VOLTAGE_SHORTS_HI            0xA057 //Number of times the vControl has been shorted
#define REG_I2C_STATISTIC_CONTROL_VOLTAGE_SHORTS_LO            0xA058

#define REG_I2C_STATISTIC_5V_VOLTAGE_SHORTS_HI                 0xA059 //Number of times the internal 5.5V has been shorted
#define REG_I2C_STATISTIC_5V_VOLTAGE_SHORTS_LO                 0xA05A

#define REG_I2C_CONFIG_DEEPSLEEP_LONG_INACTIVITY_DELAY         0xA05B //Number of days the battery entered deep sleep after inactivity (Default = 60)
#define REG_I2C_CONFIG_DEEPSLEEP_LOW_SOC_DELAY                 0xA05C //Number of days after which the battery automatically goes in deep sleep when its Soc is low (Default = 7)

#define REG_I2C_STATISTIC_DEEPSLEEP_INACTIVITY_COUNT_HI        0xA05D //Number of times the battery entered deep sleep after X days of inactivity (specified in battery.config.deepSleepAfterLongInactivityPeriodDelay)
#define REG_I2C_STATISTIC_DEEPSLEEP_INACTIVITY_COUNT_LO        0xA05E

#define REG_I2C_STATISTIC_DEEPSLEEP_LOW_SOC_COUNT_HI           0xA05F //Number of times the battery entered deep sleep due to SOC less than 10% during X days (specified in battery.config.deepSleepLowSocDelay)
#define REG_I2C_STATISTIC_DEEPSLEEP_LOW_SOC_COUNT_LO           0xA060

#define REG_I2C_STATISTIC_CHARGE_ENERGY_HIHI                   0xA067 //Total energy stored in the battery over its life [ unit:Wh ]
#define REG_I2C_STATISTIC_CHARGE_ENERGY_HILO                   0xA068
#define REG_I2C_STATISTIC_CHARGE_ENERGY_LOHI                   0xA069
#define REG_I2C_STATISTIC_CHARGE_ENERGY_LOLO                   0xA06A

#define REG_I2C_STATISTIC_DISCHARGE_ENERGY_HIHI                0xA06B //Total energy delivered by the battery over its life [ unit:Wh ]
#define REG_I2C_STATISTIC_DISCHARGE_ENERGY_HILO                0xA06C
#define REG_I2C_STATISTIC_DISCHARGE_ENERGY_LOHI                0xA06D
#define REG_I2C_STATISTIC_DISCHARGE_ENERGY_LOLO                0xA06E

#define REG_I2C_STATISTIC_DEEPSLEEP_LOW_VOLTAGE_COUNT_HI       0xA08F //Number of times the battery entered deep sleep due to an average voltage under 2.54V/cell
#define REG_I2C_STATISTIC_DEEPSLEEP_LOW_VOLTAGE_COUNT_LO       0xA090

#define REG_I2C_PCBSN_PN_HI                                    0xA09C //battery pcb part number
#define REG_I2C_PCBSN_PN_LO                                    0xA09D

#define REG_I2C_PCBSN_LOCATION                                 0xA0A0 //battery pcb location
#define REG_I2C_PCBSN_YEAR                                     0xA099 //battery pcb mfd. year
#define REG_I2C_PCBSN_MONTH                                    0xA09A //battery pcb mfd. month
#define REG_I2C_PCBSN_DAY                                      0xA09B //battery pcb mfd. day

#define REG_I2C_PCBSN_ITEM_HI                                  0xA09E //battery pcb serial number
#define REG_I2C_PCBSN_ITEM_LO                                  0xA09F

#define REG_I2C_STATUS_PERMANENT_FAILURE_FLAGS                 0xA0A1 //Having this register set to an non-0xFF or non-zero value indicates this battery shouldn't be used (see /wiki/EepromForTester)
#define REG_I2C_STATUS_TEST_FLAGS_HI                           0xA0FD //Gives battery test information (see /wiki/EepromForTester)
#define REG_I2C_STATUS_TEST_FLAGS_LO                           0xA0FE

#define REG_I2C_REV_SUPERVISOR                                 0xA200 //-

#define REG_I2C_STATUS_CAPSENSE_HI                             0xA203 //battery test "button" sensitivity
#define REG_I2C_STATUS_CAPSENSE_LO                             0xA204
#define REG_I2C_STATUS_CAPSENSE_REFERENCE_HI                   0xA205 //battery test "button" sensitivity reference
#define REG_I2C_STATUS_CAPSENSE_REFERENCE_LO                   0xA206

  //battery cell monitor registers
#define REG_CELLMON_CHANNEL_VOLTAGE_1                          0x01 //[unit:V, factor:0.001]
  //...
#define REG_CELLMON_CHANNEL_VOLTAGE_13                         0x0D //[unit:V, factor:0.001]

#define REG_CELLMON_CELL_VOLTAGE_1                             0x81 //[unit:V, factor:0.001]
  //...                                                      //!!! signed !!!
#define REG_CELLMON_CELL_VOLTAGE_13                            0x8D //[unit:V, factor:0.001]

#define REG_CELLMON_STATUS_BOMID_VOLTAGE                       0xC8 //Raw voltage of the resistor divider used to identify the revision of the BOM
#define REG_CELLMON_STATUS_PACKID_VOLTAGE                      0xC9 //Raw voltage of the resistor divider used to identify the cell pack
#define REG_CELLMON_STATUS_3V3_VOLTAGE                         0xCA //Internal voltage of the 3.3V derived from the internal 5V [unit:V, factor:0.001]
#define REG_CELLMON_STATUS_5V_VOLTAGE                          0xCB //Internal voltage of the 5(5.5)V derived from the internal 12V [unit:V, factor:0.001]

#define REG_CELLMON_CALIBRATION_1                              0x01 //[unit:%, factor:0.03] !!! signed !!!
  //...                                                      //!!! signed !!!
#define REG_CELLMON_CALIBRATION_13                             0x0D //[unit:%, factor:0.03]

#define REG_CHARGER_STATUS_FLAGS_HI                            0x02 //-
#define REG_CHARGER_STATUS_FLAGS_LO                            0x03 //-

#define REG_CHARGER_MODE                                       0x10 //Indicates the mode of the on-board charger. 0-Low power, 1-Idle, 2-Charging, 3-Accessory output, 5-Calibration, 99-Fault

#define REG_CHARGER_FINAL_VOLTAGE_HI                           0x12 //Set final charge voltage [unit:V, factor:0.01]
#define REG_CHARGER_FINAL_VOLTAGE_LO                           0x13

#define REG_CHARGER_CURRENT_HI                                 0x14 //Set charge current [unit:A, factor:0.001]
#define REG_CHARGER_CURRENT_LO                                 0x15

#define REG_CHARGER_VOLTAGE_CALIBRATION_HI                     0x42 //Multiplier applied on charger voltage reading for its calibration
#define REG_CHARGER_VOLTAGE_CALIBRATION_LO                     0x43

#define REG_CHARGER_CURRENT_CALIBRATION_HI                     0x46 //Multiplier applied on charger current reading for its calibration
#define REG_CHARGER_CURRENT_CALIBRATION_LO                     0x47

#define REG_CHARGER_REV_CHARGER                                0x56 //-
//----  /Battery

//----  Motor
#define ID_MOTOR                                               0x20
#define ID_MOTOR_RESPONSE                                      0x08
#define REG_MOTOR_ASSIST_LEVEL                                 0x09 //[unit:%, range:-100..100, factor:1.5625] !!! signed !!!

#define REG_MOTOR_ASSIST_WALK_LEVEL                            0x0A //Top level when assisting in walk mode [unit:%, factor:1.5625]
#define REG_MOTOR_ASSIST_WALK_SPEED_DECREASE_START             0x0B //Speed from which the motor starts diminishing its assistance when using the "walk mode" [unit:km/h, factor:0.1]
#define REG_MOTOR_ASSIST_WALK_SPEED_DECREASE_END               0x0C //Speed at which the motor gives no more assistance when using the "walk mode" [unit:km/h, factor:0.1]
#define REG_MOTOR_ASSIST_WALK_LEVEL_MAX                        0x0D //Top level when assisting in walk mode [unit:%, factor:1.5625]

#define REG_MOTOR_STATUS_SPEED                                 0x11 //- [unit:rpm, factor:9.091]
#define REG_MOTOR_STATUS_POWER_METER                           0x14 //- [unit:%, factor:1.5625]

#define REG_MOTOR_STATUS_TEMPERATURE                           0x16 //- [unit:C]

#define REG_MOTOR_REV_HW                                       0x19 //hardware version
#define REG_MOTOR_REV_SW                                       0x20 //software version

#define REG_MOTOR_TORQUE_GAUGE_VALUE                           0x21 //- [unit:%, range:0?..100, factor:1.5625]

#define REG_MOTOR_REV_SUB                                      0x22 //software subversion

#define REG_MOTOR_CONFIG_COMMUNICATION_MODE_LO                 0x36 //- 8 bit until sw 83

#define REG_MOTOR_ASSIST_LOWSPEED_RAMP_FLAG                    0x40 //Enables a lower speed ramp. 0: Ramp disabled 1: Ramp enabled

#define REG_MOTOR_ASSIST_DIRECTION                             0x42 //-
#define REG_MOTOR_SN_STATOR_TYPE                               0x43 //-
#define REG_MOTOR_GEOMETRY_CIRC_HI                             0x44
#define REG_MOTOR_GEOMETRY_CIRC_LO                             0x45

#define REG_MOTOR_TORQUE_GAUGE_POLARITY                        0x46 //-

#define REG_MOTOR_STATUS_MAIN                                  0x47 //Indicates the current main status of the motor. 0-Running, 1-NoCommand, 2-Startup, 3-I2CShutOff, 4-AntiBackwardShort, 5-AlarmRegen, 6-AlarmShort, 7-OverSpeedI, 8-OverSpeedV, 9-V12UVP, 10-V12OVP, 11-VPwrUVP, 12-VPwrOVP, 13-OCProtect, 14-BadStatorPN, 15-HallError

#define REG_MOTOR_SN_ITEM_HI                                   0x60 //serial number
#define REG_MOTOR_SN_ITEM_LO                                   0x61
#define REG_MOTOR_SN_PN_HI                                     0x62 //partnumber
#define REG_MOTOR_SN_PN_LO                                     0x63
#define REG_MOTOR_SN_YEAR                                      0x64 //mfd. year
#define REG_MOTOR_SN_MONTH                                     0x65 //mfd. month
#define REG_MOTOR_SN_DAY                                       0x66 //mfd. day

#define REG_MOTOR_SN_OEM_HI                                    0x67 //OEM
#define REG_MOTOR_SN_OEM_LO                                    0x68
#define REG_MOTOR_SN_PRODUCT_HI                                0x69 //product
#define REG_MOTOR_SN_PRODUCT_LO                                0x6A
#define REG_MOTOR_SN_LOCATION                                  0x6B //Location

#define REG_MOTOR_TORQUE_GAUGE_TYPE                            0x6C //-

#define REG_MOTOR_ASSIST_STATOR_PN_HI                          0x6D //-
#define REG_MOTOR_ASSIST_STATOR_PN_LO                          0x6E //

#define REG_MOTOR_STATUS_POWER_VOLTAGE_HI                      0x70 //- [unit:V, factor:0.001]
#define REG_MOTOR_STATUS_POWER_VOLTAGE_LO                      0x71

#define REG_MOTOR_STATUS_12V_VOLTAGE_HI                        0x72 //- [unit:V, factor:0.001]
#define REG_MOTOR_STATUS_12V_VOLTAGE_LO                        0x73

#define REG_MOTOR_STATUS_5V_VOLTAGE_HI                         0x74 //- [unit:V, factor:0.001]
#define REG_MOTOR_STATUS_5V_VOLTAGE_LO                         0x75

#define REG_MOTOR_CONFIG_MAX_DISCHARGE_HI                      0x7A // Maximum drawn current on vPower [unit:A, factor:0.001]
#define REG_MOTOR_CONFIG_MAX_DISCHARGE_LO                      0x7B //

#define REG_MOTOR_CONFIG_MAX_CHARGE_HI                         0x7C //Maximum regen. current on vPower [unit:A, factor:0.001]
#define REG_MOTOR_CONFIG_MAX_CHARGE_LO                         0x7D //

#define REG_MOTOR_STATISTIC_MAX_POWER_VOLTAGE_HI               0x80 //- [unit:V, factor:0.001]
#define REG_MOTOR_STATISTIC_MAX_POWER_VOLTAGE_LO               0x81

#define REG_MOTOR_STATISTIC_MAX_TEMPERATURE_HI                 0x82 //-
#define REG_MOTOR_STATISTIC_MAX_TEMPERATURE_LO                 0x83

#define REG_MOTOR_STATISTIC_ODOMETER_HI                        0x84 //- [unit:km]
#define REG_MOTOR_STATISTIC_ODOMETER_LO                        0x85

#define REG_MOTOR_STATISTIC_CHRONO_HOURS_HI                    0x86 //- [unit:h]
#define REG_MOTOR_STATISTIC_CHRONO_HOURS_LO                    0x87

#define REG_MOTOR_STATISTIC_CHRONO_SECONDS_HI                  0x88 //- [unit:s]
#define REG_MOTOR_STATISTIC_CHRONO_SECONDS_LO                  0x89

#define REG_MOTOR_PREFERENCE_REGION                            0x8A //-

#define REG_MOTOR_ASSIST_MAXSPEED                              0x8B //- [unit:km/h]
#define REG_MOTOR_ASSIST_DYNAMIC_FLAG                          0x8C //- [range:0..1]

#define REG_MOTOR_CONFIG_PWM_LIMIT_ENABLE                      0x8D //-

#define REG_MOTOR_STATUS_CODES                                 0x92 //Indicates conditions currently detected by motor. Bit 0-Sensor saturation
#define REG_MOTOR_STATUS_CODES_LATCH                           0x93 //Indicates conditions detected by motor since its last power up. See bit description of status.codes


#define REG_MOTOR_PROTECT_UNLOCK                               0xA5 //unlock register write UNLOCK_KEY here before setting protected registers
#define MOTOR_PROTECT_UNLOCK_KEY                               0xAA
#define MOTOR_PROTECT_LOCK_KEY                                 0x00

#define REG_MOTOR_STATISTIC_HALL_DCHS_HI                       0xB0 //-
#define REG_MOTOR_STATISTIC_HALL_DCHS_LO                       0xB1

#define REG_MOTOR_STATISTIC_HALL_TRANS_HI                      0xB2 //-
#define REG_MOTOR_STATISTIC_HALL_TRANS_LO                      0xB3

#define REG_MOTOR_STATISTIC_HALL_RING_HI                       0xB4 //-
#define REG_MOTOR_STATISTIC_HALL_RING_LO                       0xB5

#define REG_MOTOR_STATISTIC_HALL_LOST_HI                       0xB6 //-
#define REG_MOTOR_STATISTIC_HALL_LOST_LO                       0xB7

#define REG_MOTOR_TORQUE_GAUGE_NOISE_HI                        0xC4 //- [unit:%, range:0..100, factor:0.0015259]
#define REG_MOTOR_TORQUE_GAUGE_NOISE_LO                        0xC5

#define REG_MOTOR_TORQUE_GAUGE_DELAY_HI                        0xC6 //- [unit:s, range:0..?, factor:0.001]
#define REG_MOTOR_TORQUE_GAUGE_DELAY_LO                        0xC7

#define REG_MOTOR_TORQUE_GAUGE_SPEED                           0xC8 //- [unit:rpm, range:0..?, factor:9.091]

#define REG_MOTOR_TORQUE_GAUGE_VOLTAGE_HI                      0xC9 //- [unit:V, range:0..5, factor:0.000076295, offset:5]
#define REG_MOTOR_TORQUE_GAUGE_VOLTAGE_LO                      0xCA

#define REG_MOTOR_TORQUE_GAUGE_REFERENCE_HI                    0xCB //- [unit:V, range:0..5, factor:0.000076295, offset:5]
#define REG_MOTOR_TORQUE_GAUGE_REFERENCE_LO                    0xCC

#define REG_MOTOR_CONFIG_COMMUNICATION_MODE_HI                 0xCD //Sets the communication mode. 0 for CAN and 0xca01 for I2C

#define REG_MOTOR_TORQUE_GAUGE_GAIN                            0xCE //- [unit:%, range:0..398, factor:1.5625]

#define REG_MOTOR_TORQUE_GAUGE_MAX_VOLTAGE                     0xE0 //Maximum voltage allowed for the sensor. When the sensor detect a voltage over this value for motor.torque.gaugeMaxVoltageDelay, it assumes an electrical failure and cuts assistance [unit:V, range:0..5, factor:0.019608]
#define REG_MOTOR_TORQUE_GAUGE_MAX_VOLTAGE_DELAY               0xE1 //Time after which a voltage over motor.torque.gaugeMaxVoltage is assumed to be an electrical failure, cutting assistance [unit:s, range:0..25.5, factor:0.1]

#define REG_MOTOR_ASSIST_LEVEL_OFFSLOPE_HI                     0xD0 //Speed at which the assist level set in the motor decreases when the console stops sending requests (when it is removed for example) [unit:%/s, factor:3.05]
#define REG_MOTOR_ASSIST_LEVEL_OFFSLOPE_LO                     0xD1

#define REG_MOTOR_ASSIST_REGEN_INFLEX                          0xD2 //Speed from which regen is not attenuated [unit:rpm, range:5..?, factor:9.091]

#define REG_MOTOR_ASSIST_MAXSPEED_DERATE_DELTA                 0xD3 //Speed before maxSpeed to start derating [unit:rpm, factor:9.091]
//----  /Motor


//----  Sensor
#define ID_SENSOR                                              0x68
#define REG_SENSOR_CONFIG_GAUGE_GAIN_HI                        0x10
#define REG_SENSOR_CONFIG_GAUGE_GAIN_LO                        0x11

#define REG_SENSOR_CONFIG_RAMP_UP_STEPS_HI                     0x12
#define REG_SENSOR_CONFIG_RAMP_UP_STEPS_LO                     0x13

#define REG_SENSOR_CONFIG_DECAY_DELAY_HI                       0x14
#define REG_SENSOR_CONFIG_DECAY_DELAY_LO                       0x15

#define REG_SENSOR_CONFIG_DECAY_STEPS_HI                       0x16
#define REG_SENSOR_CONFIG_DECAY_STEPS_LO                       0x17

#define REG_SENSOR_CONFIG_SPEED_THRESHOLD_HI                   0x18
#define REG_SENSOR_CONFIG_SPEED_THRESHOLD_LO                   0x19

#define REG_SENSOR_CONFIG_RAMP_ACTIVE_OVER_THRESHOLD           0x1A

#define REG_SENSOR_STATUS_TORQUE_VOLTAGE                       0x1B //Torque sensor voltage

#define REG_SENSOR_STATUS_CADENCE                              0x1C //Number of turns per minutes made with the pedals

#define REG_SENSOR_STATUS_OUTPUT_VOLTAGE                       0x1D //Voltage output to the motor's gauge sensor

#define REG_SENSOR_STATUS_PULSE_COUNTER                        0x1E //Pulse counter. Increases when back pedaling and decreases when forward pedaling

#define REG_SENSOR_CONFIG_INPUT_OFFSET                         0x40 //Permit to offset the input value of the torque sensor from +1.64 to -1.65V

#define REG_SENSOR_SN_LOCATION                                 0x71 //Location

#define REG_SENSOR_SN_YEAR                                     0x72 //mfd. year
#define REG_SENSOR_SN_MONTH                                    0x73 //mfd. month
#define REG_SENSOR_SN_DAY                                      0x74 //mfd. day

#define REG_SENSOR_SN_PN_HI                                    0x75 //partnumber
#define REG_SENSOR_SN_PN_LO                                    0x76

#define REG_SENSOR_SN_ITEM_HI                                  0x77 //serial number
#define REG_SENSOR_SN_ITEM_LO                                  0x78

#define REG_SENSOR_REV_HW                                      0x80 //hardware version
#define REG_SENSOR_REV_SW                                      0x81 //software version

#define REG_SENSOR_CONFIG_MODE                                 0x82 //0-Thune, 1-Fag

#define REG_SENSOR_REV_SUB                                     0x83 //software subversion
//----  /Sensor

#endif
