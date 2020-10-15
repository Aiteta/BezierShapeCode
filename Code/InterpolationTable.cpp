#include <iostream>
#include <stdlib.h>
// Edge Nodes
static double P2_1_1[4] = {0.5,0.5,0,0};
static double P3_2_1[4] = {0.7252957,0.2748043,0,0};
static double P4_3_1[4] = {0.8306024,0.1693976,0,0};
static double P4_2_2[4] = {0.5,0.5,0,0};
static double P5_4_1[4] = {0.8866427,0.1133573,0,0};
static double P5_3_2[4] = {0.6431761,0.3568239,0,0};
static double P6_5_1[4] = {0.9194021,0.0805979,0,0};
static double P6_4_2[4] = {0.7349105,0.2650895,0,0};
static double P6_3_3[4] = {0.5,0.5,0,0};
static double P7_6_1[4] = {0.9398927,0.0601073,0,0};
static double P7_5_2[4] = {0.7957614,0.2042386,0,0};
static double P7_4_3[4] = {0.6042138,0.3957862,0,0};
static double P8_7_1[4] = {0.9533797,0.0466203,0,0};
static double P8_6_2[4] = {0.8375919,0.1624081,0,0};
static double P8_5_3[4] = {0.6801403,0.3198597,0,0};
static double P8_4_4[4] = {0.5,0.5,0,0};
static double P9_8_1[4] = {0.9626819,0.0373181,0,0};
static double P9_7_2[4] = {0.8672666,0.1327334,0,0};
static double P9_6_3[4] = {0.7361751,0.2638249,0,0};
static double P9_5_4[4] = {0.5815151,0.4184849,0,0};

double* P2e[1] = {P2_1_1};
double* P3e[1] = {P3_2_1};
double* P4e[2] = {P4_3_1,P4_2_2};
double* P5e[2] = {P5_4_1,P5_3_2};
double* P6e[3] = {P6_5_1,P6_4_2,P6_3_3};
double* P7e[3] = {P7_6_1,P7_5_2,P7_4_3};
double* P8e[4] = {P8_7_1,P8_6_2,P8_5_3,P8_4_4};
double* P9e[4] = {P9_8_1,P9_7_2,P9_6_3,P9_5_4};

double** Pe[8] = {P2e,P3e,P4e,P5e,P6e,P7e,P8e,P9e};

// Triangle Nodes
static double P3_1_1_1[4] = {0.3333333,0.3333333,0.3333333,0};
static double P4_2_1_1[4] = {0.5582239,0.2208880,0.2208880,0};
static double P5_3_1_1[4] = {0.6949657,0.1525171,0.1525171,0};
static double P5_2_2_1[4] = {0.4168658,0.4168658,0.1662683,0};
static double P6_4_1_1[4] = {0.7805723,0.1097139,0.1097139,0};
static double P6_3_2_1[4] = {0.5586077,0.3157892,0.1256031,0};
static double P6_2_2_2[4] = {0.3333333,0.3333333,0.3333333,0};
static double P7_5_1_1[4] = {0.8365261,0.0817370,0.0817370,0};
static double P7_4_2_1[4] = {0.6584392,0.2447528,0.0968080,0};
static double P7_3_3_1[4] = {0.4494208,0.4494208,0.1011584,0};
static double P7_3_2_2[4] = {0.4673202,0.2663399,0.2663399,0};
static double P8_6_1_1[4] = {0.8745338,0.0627331,0.0627331,0};
static double P8_5_2_1[4] = {0.7294168,0.1942206,0.0763626,0};
static double P8_4_3_1[4] = {0.5524728,0.3657423,0.0817849,0};
static double P8_4_2_2[4] = {0.5692789,0.2153606,0.2153606,0};
static double P8_3_3_2[4] = {0.3891297,0.3891297,0.2217406,0};
static double P9_7_1_1[4] = {0.9012542,0.0493729,0.0493729,0};
static double P9_6_2_1[4] = {0.7808733,0.1575680,0.0615587,0};
static double P9_5_3_1[4] = {0.6309227,0.3020146,0.0670627,0};
static double P9_5_2_2[4] = {0.6461122,0.1769439,0.1769439,0};
static double P9_4_4_1[4] = {0.4658361,0.4658361,0.0683277,0};
static double P9_4_3_2[4] = {0.4887991,0.3261032,0.1850977,0};
static double P9_3_3_3[4] = {0.3333333,0.3333333,0.3333333,0};

double* P3_1t[1] = {P3_1_1_1};
double* P4_1t[1] = {P4_2_1_1};
double* P5_1t[1] = {P5_3_1_1};
double* P5_2t[1] = {P5_2_2_1};
double* P6_1t[2] = {P6_4_1_1,P6_3_2_1,};
double* P6_2t[1] = {P6_2_2_2};
double* P7_1t[3] = {P7_5_1_1,P7_4_2_1,P7_3_3_1};
double* P7_2t[1] = {P7_3_2_2};
double* P8_1t[3] = {P8_6_1_1,P8_5_2_1,P8_4_3_1};
double* P8_2t[2] = {P8_4_2_2,P8_3_3_2};
double* P9_1t[4] = {P9_7_1_1,P9_6_2_1,P9_5_3_1,P9_4_4_1};
double* P9_2t[2] = {P9_5_2_2,P9_4_3_2};
double* P9_3t[1] = {P9_3_3_3};

double** P3t[1] = {P3_1t};
double** P4t[1] = {P4_1t};
double** P5t[2] = {P5_1t,P5_2t};
double** P6t[2] = {P6_1t,P6_2t};
double** P7t[2] = {P7_1t,P7_2t};
double** P8t[2] = {P8_1t,P8_2t};
double** P9t[3] = {P9_1t,P9_2t,P9_3t};

double*** Pt[7] = {P3t,P4t,P5t,P6t,P7t,P8t,P9t};

// Tetrahedron Nodes
double P4_1_1_1_1[4] = {0.25,0.25,0.25,0.25};
double P5_2_1_1_1[4] = {0.4530838,0.1823054,0.1823054,0.1823054};
double P6_3_1_1_1[4] = {0.5926485,0.1357838,0.1357838,0.1357838};
double P6_2_2_1_1[4] = {0.3559336,0.3559336,0.1440664,0.1440664};
double P7_4_1_1_1[4] = {0.6860001,0.1046666,0.1046666,0.1046666};
double P7_3_2_1_1[4] = {0.4885725,0.2830329,0.1141973,0.1141973};
double P7_2_2_2_1[4] = {0.2936310,0.2936310,0.2936310,0.1191069};
double P8_5_1_1_1[4] = {0.7496468,0.0834511,0.0834511,0.0834511};
double P8_4_2_1_1[4] = {0.5844475,0.2299889,0.0927818,0.0927818};
double P8_3_3_1_1[4] = {0.4060462,0.4060462,0.0939538,0.0939538};
double P8_3_2_2_1[4] = {0.4157364,0.2432058,0.2432058,0.0978521};
double P8_2_2_2_2[4] = {0.25,0.25,0.25,0.25};
double P9_6_1_1_1[4] = {0.7952422,0.0682526,0.0682526,0.0682526};
double P9_5_2_1_1[4] = {0.6543249,0.1908175,0.0774288,0.0774288};
double P9_4_3_1_1[4] = {0.5016150,0.3421360,0.0781245,0.0781245};
double P9_4_2_2_1[4] = {0.5083123,0.2049128,0.2049128,0.0818620};
double P9_3_3_2_1[4] = {0.3552639,0.3552639,0.2073089,0.0821632};
double P9_3_2_2_2[4] = {0.3630891,0.2123036,0.2123036,0.2123036};

double* P4_1_1T[1] = {P4_1_1_1_1};
double* P5_1_1T[1] = {P5_2_1_1_1};
double* P6_1_1T[2] = {P6_3_1_1_1,P6_2_2_1_1};
double* P7_1_1T[2] = {P7_4_1_1_1,P7_3_2_1_1};
double* P7_1_2T[1] = {P7_2_2_2_1};
double* P8_1_1T[3] = {P8_5_1_1_1,P8_4_2_1_1,P8_3_3_1_1};
double* P8_1_2T[1] = {P8_3_2_2_1};
double* P8_2_2T[1] = {P8_2_2_2_2};
double* P9_1_1T[3] = {P9_6_1_1_1,P9_5_2_1_1,P9_4_3_1_1};
double* P9_1_2T[2] = {P9_4_2_2_1,P9_3_3_2_1};
double* P9_2_2T[1] = {P9_3_2_2_2};

double** P4_1T[1] = {P4_1_1T};
double** P5_1T[1] = {P5_1_1T};
double** P6_1T[1] = {P6_1_1T};
double** P7_1T[2] = {P7_1_1T,P7_1_2T};
double** P8_1T[2] = {P8_1_1T,P8_1_2T};
double** P8_2T[1] = {P8_2_2T};
double** P9_1T[2] = {P9_1_1T,P9_1_2T};
double** P9_2T[1] = {P9_2_2T};

double*** P4T[1] = {P4_1T};
double*** P5T[1] = {P5_1T};
double*** P6T[1] = {P6_1T};
double*** P7T[1] = {P7_1T};
double*** P8T[2] = {P8_1T,P8_2T};
double*** P9T[2] = {P9_1T,P9_2T};

double**** PT[6] = {P4T,P5T,P6T,P7T,P8T,P9T};


double* getBezierZeta(int P, int i, int j, int k, int l) {
	double* out = (double*)calloc(4,sizeof(double));
	int placement[4] = {i,j,k,l};
	int zeroes = 0;
	for (int itr = 0; itr < 4; itr++) {
		// Vertex Node Check
		if (placement[itr] == P) {
			out[itr] = 1;
			return out;
		}
		else if (placement[itr] == 0)
			zeroes++;

	}
	if (zeroes == 4)
		return out;
	int order[4];
	for (int itr = 0; itr < 4; itr++) {
		order[itr] = 0;
	}
	for (int itr = 0; itr < 4; itr++) {
		int max = -1;
		int plac = -1;
		for (int itr1 = 0; itr1 < 4; itr1++) {
			if ((placement[itr1] > max) && (order[itr1]==0)) {
				max = placement[itr1];
				plac = itr1;
			}
		}
		order[plac] = 4-itr;
		switch (4-itr) {
		 	case 1:
		 		l = placement[plac];
		 		break;
		 	case 2:
		 		k = placement[plac];
		 		break;
		 	case 3:
		 		j = placement[plac];
		 		break;
		 	case 4:
		 		i = placement[plac];
		 	default:
		 		break;
		}
	}
	std::cout << i << ' ' << j << ' ' << k << ' ' << l << std::endl;
	double* zeta;
	switch (zeroes) {
		case 0:
			// Tetrahedron Nodes
			zeta = PT[P-4][l-1][k-l][j-k];
			break;
		case 1:
			// Triangle Nodes
			zeta = Pt[P-3][k-1][j-k];
			break;
		case 2:
			// Edge Nodes
			zeta = Pe[P-2][j-1];
			break;
		default:
			return out;
			// Error
	}
	for (int itr = 0; itr < 4; itr++) {
		if (order[itr] == 1) {
			out[itr] = zeta[3];
		}
		else if (order[itr] == 2) {
			out[itr] = zeta[2];
		}
		else if (order[itr] == 3) {
			out[itr] = zeta[1];
		}
		else if (order[itr] == 4) {
			out[itr] = zeta[0];
		}
	}
	return out;
}


int main() {
	double* zeta = getBezierZeta(6,2,2,2,0);
	for (int i = 0; i < 4; i++) {
		std::cout << i << ": " << zeta[i] << std::endl;
	}

	return 0;
}