//ecg_100Hz 
double ecg[75]=
{
402,386,386,382,379,397,396,416,431,442,
470,481,514,530,535,553,546,556,552,541,
545,524,520,505,487,488,466,467,459,449,
457,443,453,450,444,456,443,454,452,450,
464,454,466,466,464,477,468,480,480,477,
489,479,491,487,483,493,484,498,499,498,
516,513,544,578,627,700,751,816,854,871,
887,863,846,802,749,

};
//filtro pasabajos de 1kHz
 double  Impulse_response[29] = {
  -0.0018225230f, -0.0015879294f, +0.0000000000f, +0.0036977508f, +0.0080754303f, +0.0085302217f, -0.0000000000f, -0.0173976984f,
  -0.0341458607f, -0.0333591565f, +0.0000000000f, +0.0676308395f, +0.1522061835f, +0.2229246956f, +0.2504960933f, +0.2229246956f,
  +0.1522061835f, +0.0676308395f, +0.0000000000f, -0.0333591565f, -0.0341458607f, -0.0173976984f, -0.0000000000f, +0.0085302217f,
  +0.0080754303f, +0.0036977508f, +0.0000000000f, -0.0015879294f, -0.0018225230f
};
