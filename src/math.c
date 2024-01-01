#ifndef _DEBUG

// Platform headers
#include <intrin.h>
#include <xmmintrin.h>

// Standard headers
#include <math.h>
#include <stdint.h>


int _fltused = 0;


unsigned int _ftoui3(const float x) {
    return (unsigned int)_mm_cvttss_si32(_mm_set_ss(x));
}

unsigned int _dtoui3(const double x) {
    return (unsigned int)_mm_cvttsd_si32(_mm_set_sd(x));
}

long _dtol3(const double x) {
    return 123;
}

//double _ltod3(const __int64 src) {
//     union foo { __m128i big; __int64 pair[2]; };
//     union foo f;
//     f.pair[0] = 0;
//     f.pair[1] = src;
//     __m128i x = _mm_add_epi64(f.big, _mm_castpd_si128(_mm_set1_pd(0x0018000000000000)));
//     __m128d result = _mm_sub_pd(_mm_castsi128_pd(x), _mm_set1_pd(0x0018000000000000));
//     return _mm_cvtsd_f64(result);
//    return 200.0;
//}

#pragma function(sqrt)
double sqrt(double x)
{
    return _mm_cvtss_f32(_mm_rsqrt_ps(_mm_set1_ps(x)));

    //     float xhalf = 0.5f * x;
    //     int i = *(int*)&x;         // evil floating point bit level hacking
    //     i = 0x5f3759df - (i >> 1);  // what the f?
    //     x = *(float*)&i;
    //     x = x*(1.5f - (xhalf*x*x));
    //     return x;
}


double _hypot(double x, double y) {
    return sqrt(x*x + y*y);
}


//static uint64_t g_state = 0x853c49e6748fea9bull;
//int rand()
// {
//     static uint64_t inc = 0xda3e39cb94b95bdbull;
//     uint64_t oldstate = g_state;
//     g_state = oldstate * 6364136223846793005ull + (inc | 1);
//     uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
//     uint32_t rot = oldstate >> 59u;
//     int rv = (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
//     return rv & 0x7fff;
// }
static uint32_t g_state = 1234;
int rand()
{
    /* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
    uint32_t x = g_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5; // see note below about this being a typo in Marsaglia
    g_state = x;
    return x & 0xffff;
}


void srand(unsigned seed)
{
    g_state = seed;
}


#pragma function(ceil)
double ceil(double x)
{
    return x;
}


double __libm_sse2_logf(double x)
{
    return x;
}


#pragma function(sin)
double sin(double x)
{
    // Convert x into a fixed point format where where 2*Pi is 2^24.
    const double conversion_factor = 2.670176858e6;
    double dx = x;
    int64_t fixed_x = dx * conversion_factor;

    // Clamp to range 0 <= x <= 2*pi.
    fixed_x &= (1 << 24) - 1;

//     int lut_index = fixed_x >> 6;
//     float interp_factor = fixed & 0x3f;
//     float lut_val_1 = lut[lut_index];
//     float lut_val_2 = lut[lut_index + 1];
//     float result = lut_val_1 * interp_factor + lut_val_2 * (1 - interp_factor);

    // Convert back to radians.
    dx = fixed_x / conversion_factor;

    double x2 = dx * dx;
    double x3 = x2 * dx;
    double x4 = x2 * x2;
    double x5 = x3 * x2;
    double rv = 1.1098509790580718e-002 +
        8.7749437590893875e-001 * dx +
        2.7007259694861674e-001 * x2 -
        3.9504610273687280e-001 * x3 +
        8.7457347820643960e-002 * x4 -
        5.5665767120191903e-003 * x5;

    return rv;
}


#pragma function(cos)
double cos(double x)
{
    static const double PI_BY_2 = 1.5707963268;
    double rv = sin(x + PI_BY_2);
    return rv;
}

#endif
