#include "hsi.h"

#include <math.h>


RGB hsi2rgb(float H, float S, float I)
{
    int R, G, B;
    float r, g, b;
    H = fmod(H, 360.0f); // cycle H around to 0-360 degrees
    H = 3.14159 * H / 180.0f; // Convert to radians.
    S = S > 0 ? (S < 1 ? S : 1) : 0; // clamp S and I to interval [0,1]
    I = I > 0 ? (I < 1 ? I : 1) : 0;

    if (H < 2.09439) {
        r = I * (1 + S * cos(H) / cos(1.047196667 - H));
        b = I * (1 - S);
        g = 3 * I - (r + b);
    }
    else if (H < 4.188787) {
        H = H - 2.09439;
        g = I * (1 + S * cos(H) / cos(1.047196667 - H));
        r = I * (1 - S);
        b = 3 * I - (r + g);
    }
    else {
        H = H - 4.188787;
        b = I * (1 + S * cos(H) / cos(1.047196667 - H));
        g = I * (1 - S);
        r = 3 * I - (g + b);
    }

    R = 255*r;
    G = 255*g;
    B = 255*b;

    if (R > 255)
    {
        R = 255;
    }
    if (G > 255)
    {
        G = 255;
    }
    if (B > 255)
    {
        B = 255;
    }

    if (R < 0)
    {
        R = 0;
    }
    if (G < 0)
    {
        G = 0;
    }
    if (B < 0)
    {
        B = 0;
    }

    struct RGB rgb = {R, G, B};
    return rgb;
}


HSI rgb2hsi(int R, int G, int B)
{
    float h, s, i;
    float r, g, b;
    float phi, den, num;

    r = float(R)/255;
    g = float(G)/255;
    b = float(B)/255;

    float min = r;
    if (g < min)
        min = g;
    if (b < min)
        min = b;

    // calculate intensity;
    i = (r+g+b)/3;

    // calculate saturation;
    s = 1 - min/i;

    // calculate hue:
    den = ((r-g)+(r-b))/2;
    num = sqrt(pow(r-g,2.0)+(r-b)*(g-b));
    if (num == 0)
    {
        num = 0.0000001f;
    }
    phi = acos(den/num);
    if (b<=g)
    {
        h = phi;
    }
    else
    {
        h = 2.0f * 3.14159f - phi;
    }

    h = h/2.0f/3.14159f*360;

    if (h > 360)
    {
        h = 360;
    }
    if (s > 1.0f)
    {
        s = 1.0;
    }
    if (i > 1.0f)
    {
        i = 1.0;
    }

    if (h < 0)
    {
        h = 0;
    }
    if (s < 0)
    {
        s = 0;
    }
    if (i < 0)
    {
        i = 0;
    }

    struct HSI hsi = {h, s, i};
    return hsi;
}
