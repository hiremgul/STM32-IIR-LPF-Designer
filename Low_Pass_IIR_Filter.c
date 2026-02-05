/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Low Pass
Filter model: Butterworth
Filter order: 5
Sampling Frequency: 1000 Hz
Cut Frequency: 50.000000 Hz
Coefficents Quantization: float

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000

Z domain Poles
z = 0.760845 + j -0.145308
z = 0.760845 + j 0.145308
z = 0.726543 + j -0.000000
z = 0.868155 + j -0.268275
z = 0.868155 + j 0.268275
***************************************************************/
#define NCoef 5
float iir(float NewSample) {
    float ACoef[NCoef+1] = {
        0.00006248961583259117,
        0.00031244807916295581,
        0.00062489615832591163,
        0.00062489615832591163,
        0.00031244807916295581,
        0.00006248961583259117
    };

    float BCoef[NCoef+1] = {
        1.00000000000000000000,
        -3.98454311961233690000,
        6.43486709027586820000,
        -5.25361517035226730000,
        2.16513290972413230000,
        -0.35992824506355597000
    };

    static float y[NCoef+1]; //output samples
    static float x[NCoef+1]; //input samples
    int n;

    //shift the old samples
    for(n=NCoef; n>0; n--) {
       x[n] = x[n-1];
       y[n] = y[n-1];
    }

    //Calculate the new output
    x[0] = NewSample;
    y[0] = ACoef[0] * x[0];
    for(n=1; n<=NCoef; n++)
        y[0] += ACoef[n] * x[n] - BCoef[n] * y[n];
    
    return y[0];
}
