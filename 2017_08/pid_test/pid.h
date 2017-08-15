#ifndef PID_HEADER_FILE
#define PID_HEADER_FILE

#include <math.h>
#include <iostream>


float micros();

class PID {
    public:
    PID(float kp, float ki, float kd,float min_val,float max_val,int stage) {
        setKp(kp);
        setKi(ki);
        setKd(kd);
        sign = 1;
        
        _min_val = min_val;
        _max_val = max_val;
        _stage = stage;
        _integral = (float*)malloc(stage*sizeof(float));
        for(int i = 0 ; i < stage;i++)
            _integral[i]=0;
            
        init();
    }

    ~PID(){
        free(_integral);
    }

    void init() {
        isFirst = true;
        _old_time = get_time();
        _old_error = 0;
        for(int i = 0 ; i < _stage;i++)
            _integral[i]=0;
    }
    
    void inverse() {
        sign *= -1;
    }

    float output(const float target,const float now_value,float key_value) {
        const float error = target - now_value;
        const float new_time = get_time();
        const float dt = new_time - _old_time;
        const float d_error = isFirst ? 0 : (error - _old_error) / dt;

        const int index = map_constrainX(key_value,_min_val,_max_val,0,_stage-1);

        isFirst = false;
        _integral[index] += error * dt;
        const float ret = _kp * error + _ki * _integral[index] + _kd * d_error;
        
        //std::cout << index<<std::endl;
        
        _old_time = new_time;
        _old_error = error;

        return ret * sign;
    }
    
    float map_constrainX(float x, float in_min, float in_max, int out_min, int out_max){
        int ret = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        if( ret < out_min)ret=out_min;
        else if( ret > out_max ) ret = out_max;
        
        return ret;
    }

    
    void setKp(float kp){
        _kp = kp;
    }
    
    void setKi(float ki){
        _ki = ki;
    }
    
    void setKd(float kd){
        _kd = kd;
    }

private:

    float get_time() {
        return micros() * 1e-6;
    }

    float _kp, _ki, _kd;
    float *_integral;
    float _old_error, _old_time;
    int sign;
    bool isFirst;
    float _min_val,_max_val;
    int _stage;
};

#endif
