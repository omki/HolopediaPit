/**
 * $Id: $
 *
 * @brief Red Pitaya Applications library common module interface
 *
 * @Author Luka Golinar, RedPitaya
 *
 * (c) Red Pitaya  http://www.redpitaya.com
 *
 * This part of code is written in C programming language.
 * Please visit http://en.wikipedia.org/wiki/C_(programming_language)
 * for more details on the language used herein.
 */

 #ifndef UTILS_H_
 #define UTILS_H_


#include <sys/syslog.h>
#include "redpitaya/rp.h"

#define RP_LOG(...){ \
	syslog(__VA_ARGS__); \
}

#define EXEC_CHECK(x){ \
 		int retval = (x); \
 		if(retval != RP_OK) { \
 			RP_LOG(LOG_INFO, "Execution error.\n"); \
 			return retval; \
 		} \
}


float vectorMax(float *data, int size);
float vectorApprox(float *data, int size, float approx_val, bool min);
float trapezoidalApprox(double *data, float t, int size);
float vectorMean(float *data, int steps);
float **multiDimensionVector(int second_dimenson);
int set_IIC_Shunt(int k);

int lcr_checkRShunt(float z_ampl, double r_shunt, int *new_shunt);

void lcr_getDecimationValue(float frequency,
						rp_acq_decimation_t *api_dec,
						int *dec_val);

#endif //UTILS_H_