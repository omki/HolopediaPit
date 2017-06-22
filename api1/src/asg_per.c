#include "asg_per.h"

void rp_asg_per_init (rp_asg_per_t *handle, volatile rp_asg_per_regset_t *regset, double FS, int unsigned buffer_size, int unsigned CWM, int unsigned CWF) {
    handle->regset = regset;
    handle->FS = FS;
    handle->buffer_size = buffer_size;
    handle->CWM = CWM;
    handle->CWF = CWF;
    handle->CW  = CWM+CWF;
}

uint32_t rp_asg_per_get_table_size(rp_asg_per_t *handle) {
    return((handle->regset->cfg_siz + 1) >> handle->CWF);
}

int rp_asg_per_set_table_size(rp_asg_per_t *handle, uint32_t value) {
    if (value <= handle->buffer_size) {
        handle->regset->cfg_siz = (value << handle->CWF) - 1;
        return(0);
    } else {
//        raise ValueError("Waveform table size should not excede buffer size. buffer_size = {}".format(self.buffer_size))
        return(-1);
    }
}

//    @property
//    def frequency (self) -> float:
//        """Periodic signal frequency up to FS/2"""
//        siz = self.regset.per.cfg_siz + 1
//        stp = self.regset.per.cfg_ste + 1
//        return (stp / siz * self.FS)
//
//    @frequency.setter
//    def frequency (self, value: float):
//        if (value < self.FS/2):
//            siz = self.regset.per.cfg_siz + 1
//            self.regset.per.cfg_ste = int(siz * (value / self.FS)) - 1
//        else:
//            raise ValueError("Frequency should be less then half the sample rate. f < FS/2 = {} Hz".format(self.FS/2))
//
//    @property
//    def phase (self) -> float:
//        """Periodic signal phase in angular degrees"""
//        siz = self.regset.per.cfg_siz + 1
//        off = self.regset.per.cfg_off
//        return (off / siz * 360)
//
//    @phase.setter
//    def phase (self, value: float):
//        siz = self.regset.per.cfg_siz + 1
//        self.regset.per.cfg_off = int(siz * (value % 360) / 360)

