/*
 * config.h
 *
 *  Created on: 30.07.2020
 *      Author: stancecoke
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define CALIB_GAUGE 1	 		// calibration factor for DMS-Torque, better value not known :-)
#define CALIB_EXT_TORQUE 2000	// calibration factor for DMS-Torque, better value not known :-)
#define CALIB_REGEN 1 			//calibration factor for regen
#define FILTER 4 				//average from 2^x samples

#define THROTTLE_MIN 700
#define THROTTLE_MAX 3600

#define EXT_TORQUE_MIN 700
#define EXT_TORQUE_MAX 3600

#define PAS_TIMEOUT 300

//predefine Display Types
#define DISPLAY_TYPE_KUNTENG (1<<1)							// For use with Kunteng LCD Displays
#define DISPLAY_TYPE_DEBUG (1<<0)							// For ASCII-Output in Debug mode);


//Select display
#define DISPLAY_TYPE DISPLAY_TYPE_DEBUG
#endif /* CONFIG_H_ */
