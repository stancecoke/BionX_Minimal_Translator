/*
 * config.h
 *
 *  Created on: 30.07.2020
 *      Author: stancecoke
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define CALIB_GAUGE 1	 		// calibration factor for DMS-Torque, better value not known :-)
#define CALIB_EXT_TORQUE 3	// calibration factor for DMS-Torque, better value not known :-)
#define CALIB_REGEN 64 			//calibration factor for regen


#define THROTTLE_MIN 640
#define THROTTLE_MAX 3450

#define EXT_TORQUE_MIN 1190
#define EXT_TORQUE_MAX 2400

#define PAS_TIMEOUT 300

//predefine Display Types
#define DISPLAY_TYPE_KUNTENG (1<<1)							// For use with Kunteng LCD Displays
#define DISPLAY_TYPE_DEBUG (1<<0)							// For ASCII-Output in Debug mode);

#define P_FACTOR 0.001
#define I_FACTOR 0.0001

//Select display
#define DISPLAY_TYPE DISPLAY_TYPE_KUNTENG
#endif /* CONFIG_H_ */
