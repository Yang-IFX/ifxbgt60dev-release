/**
* \copyright
* MIT License
*
* Copyright (c) 2020 Infineon Technologies AG
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE
*
* \endcopyright
*
* \author Infineon Technologies AG
*
* \file SDK.h
*
* \brief   Master header file for Radar SDK
*
* \defgroup gr_cat_SDK_base           SDK base
* \defgroup gr_cat_Device_Access      Device Access
* \defgroup gr_cat_Math_Elements      Math Elements
* \defgroup gr_cat_Signal_Processing  Signal Processing
* \defgroup gr_cat_Algorithms         Algorithms
*
*
* @{
*/


#ifndef IFX_RADAR_SDK_H
#define IFX_RADAR_SDK_H

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*
==============================================================================
   1. INCLUDE FILES
==============================================================================
*/

#include "ifxAlgo/2DMTI.h"
#include "ifxAlgo/DBSCAN.h"
#include "ifxAlgo/FFT.h"
#include "ifxAlgo/MTI.h"
#include "ifxAlgo/OSCFAR.h"
#include "ifxAlgo/PreprocessedFFT.h"
#include "ifxAlgo/Window.h"

#include "ifxBase/Complex.h"
#include "ifxBase/Cube.h"
#include "ifxBase/Error.h"
#include "ifxBase/Forward.h"
#include "ifxBase/LA.h"
#include "ifxBase/Log.h"
#include "ifxBase/Math.h"
#include "ifxBase/Matrix.h"
#include "ifxBase/Mem.h"
#include "ifxBase/Types.h"
#include "ifxBase/Vector.h"
#include "ifxRadar/AngleCapon.h"
#include "ifxRadar/AngleMonopulse.h"
#include "ifxRadar/DBF.h"
#include "ifxRadar/DeviceConfig.h"
#include "ifxRadar/DeviceControl.h"
#include "ifxRadar/Frame.h"
#include "ifxRadar/ParamEstimation.h"
#include "ifxRadar/PeakSearch.h"
#include "ifxRadar/PresenceSensing.h"
#include "ifxRadar/RangeAngleImage.h"
#include "ifxRadar/RangeDopplerMap.h"
#include "ifxRadar/RangeSpectrum.h"
#include "ifxRadar/Segmentation.h"
#include "ifxRadar/Util.h"

/*
==============================================================================
   2. DEFINITIONS
==============================================================================
*/


/*
==============================================================================
   3. TYPES
==============================================================================
*/

/*
==============================================================================
   4. FUNCTION PROTOTYPES
==============================================================================
*/

/** @addtogroup gr_cat_SDK_base
  * @{
  */

/** @defgroup gr_sdk SDK
  * @brief SDK version query
  * @{
  */

/**
 * @brief Returns the radar sdk version as a string.
 *        The format is according to semantic versioning v2.0 standard
 *        see https://semver.org/.
 *
 * @return Pointer to the string containing the version.
 */

IFX_DLL_PUBLIC
const char* ifx_radar_sdk_get_version_string(void);

/**
* @brief Returns the radar sdk full version as a string.
*        Following semantic versioning this string will contain
*        pre-release, distance to repository tag and hash code information
*        in the form MAJOR.MINOR.PATCH-PRE_RELEASE+TAG_DISTANCE.HASH_CODE[.META].
*
* @return Pointer to the string containing the full version.
*/
IFX_DLL_PUBLIC
const char* ifx_radar_sdk_get_version_string_full(void);

/**
* @brief Returns the radar sdk version hash as a string.
*
* @return Pointer to the string containing the version hash.
*/
IFX_DLL_PUBLIC
const char* ifx_radar_sdk_get_version_hash(void);

/**
  * @}
  */
 
/**
  * @}
  */ 

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* IFX_RADAR_SDK_H */

/**
* @}
*/