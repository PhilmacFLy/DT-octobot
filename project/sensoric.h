
#ifndef __SENSORIC_H__
#define __SENSORIC_H__

#define DIRECTION_X (0)
#define DIRECTION_Y (1)
#define DIRECTION_Z (2)

void ReadSensorData();

unsigned int ReadAccelValueRaw(unsigned char direction);
signed int ReadAccelValue(unsigned char direction);
signed int ReadSpinAccelValue();

#endif /* __SENSORIC_H__ */
