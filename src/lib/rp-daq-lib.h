#ifndef RP_DAQ_LIB_H
#define RP_DAQ_LIB_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ioctl.h>

#define BASE_FREQUENCY 125000000

extern int mmapfd;
extern volatile uint32_t *slcr, *axi_hp0;
extern volatile void *dac_cfg, *adc_sts, *pdm_cfg, *pdm_sts, *reset_sts, *cfg, *ram, *buf;

#define DAC_MODE_RASTERIZED 1
#define	DAC_MODE_STANDARD   0

#define ADC_MODE_CONTINUOUS 0
#define ADC_MODE_TRIGGERED 1

#define WATCHDOG_OFF 0
#define WATCHDOG_ON 1

#define MASTER_TRIGGER_OFF 0
#define MASTER_TRIGGER_ON 1

extern uint16_t dac_channel_A_modulus[4];
extern uint16_t dac_channel_B_modulus[4];

extern int init();
extern void load_bitstream();
extern bool isMaster();
extern bool isSlave();
extern void setMaster();
extern void setSlave();
extern uint16_t getAmplitude(int, int);
extern int setAmplitude(uint16_t, int, int);
extern double getFrequency(int, int);
extern int setFrequency(double, int, int);
extern int getModulusFactor(int, int);
extern int setModulusFactor(uint32_t, int, int);
extern double getPhase(int, int);
extern int setPhase(double, int, int);
extern int setDACMode(int);
extern int getDACMode();
extern int reconfigureDACModulus(int, int, int);
extern int setPDMRegisterValue(uint64_t);
extern uint64_t getPDMRegisterValue();
extern uint64_t getPDMStatusValue();
extern int setPDMNextValues(uint16_t, uint16_t, uint16_t, uint16_t);
extern int* getPDMNextValues();
extern int setPDMNextValue(uint16_t, int);
extern int setPDMNextValueVolt(float, int);
extern int getPDMNextValue();
extern int getPDMCurrentValue(int);
extern int* getPDMCurrentValues();
extern uint32_t getXADCValue(int);
extern float getXADCValueVolt(int);
extern int setWatchdogMode(int);
extern int setRAMWriterMode(int);
extern int setMasterTrigger(int);
extern int getPeripheralAResetN();
extern int getFourierSynthAResetN();
extern int getPDMAResetN();
extern int getWriteToRAMAResetN();
extern int getXADCAResetN();
extern int getTriggerStatus();
extern int getWatchdogStatus();
extern int getInstantResetStatus();
extern int setDecimation(uint16_t decimation);
extern uint16_t getDecimation();

#endif /* RP_DAQ_LIB_H */
