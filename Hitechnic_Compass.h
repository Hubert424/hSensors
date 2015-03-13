/**
 ******************************************************************************
 * \file    Hitechnic_Compass.h
 * \author  Husarion team
 * \version V0.9
 * \date    2-June-2014
 * \brief   Provides interface for Hitechnic Compass sensor.
 ******************************************************************************
 * \details This file is part of robocore-sensors library.
 *
 * \copyright Copyright (C) 2014 Husarion Sp. z o.o. <husarion.com> - All Rights Reserved.
 * Unauthorized copying of this file and the robocore-sensors library,
 * via any medium is strictly prohibited. Proprietary and confidential.
 *
 * \attention
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */

#ifndef __HITECHNIC_COMPASS_H__
#define __HITECHNIC_COMPASS_H__

#include <hFramework.h>

#define MODE_MEASURING   0x00
#define MODE_CALIBRATION 0x43

namespace hSensors
{
/**
 * @brief Provides interface for Hitechnic Compass sensor.
 */
class Hitechnic_Compass
{
public:
	enum EError { ERROR_OK, ERROR_PROTO };

	/**
	 * @brief Create compass object.
	 * @param i2c - I2C sensor (eg. hSens1.i2c, hSens2.i2c)
	 */
	Hitechnic_Compass(hI2C& i2c);
	Hitechnic_Compass(); //!< Destory compass object.

	void init(); //!< Initialize compass.

	/**
	 * @brief Start calibration mode.
	 * @return error code
	 */
	EError startCalibration();
	/**
	 * @brief Stop calibration mode.
	 * @return error code
	 */
	EError stopCalibration();

	/**
	 * @brief Return current control mode.
	 * @param status - reference to current control mode
	 * - MODE_MEASURING - sensor is in measuring state
	 * - MODE_CALIBRATION - sensor is in calibration mode
	 * @return error code
	 */
	EError getControlMode(uint8_t& status);

	/**
	 * @brief Return current heading.
	 * @param heading - reference to heading value
	 * @return error code
	 */
	EError readHeading(uint16_t& heading);

private:
	hI2C &i2c;
};

}

#endif
