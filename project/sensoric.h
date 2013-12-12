
#ifndef __SENSORIC_H__
#define __SENSORIC_H__

#define DIRECTION_X (0)
#define DIRECTION_Y (1)
#define DIRECTION_Z (2)

void ReadSensorData();
			   
unsigned char ReadAccelValueRaw(unsigned char direction);
unsigned char ReadSpinValueRaw();

signed int GetCurrentAngle();
				   
signed int ReadAccelValue(unsigned char direction);
signed int ReadSpinValue();

#endif /* __SENSORIC_H__ */
