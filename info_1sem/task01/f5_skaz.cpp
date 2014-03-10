#include <stdio.h>
using namespace std;

int zones[9][9];
int num[10];
int nullarr();
bool ifnum();
int zone;

int main(){
	
	int a[9][9];
	bool mnb = true;
	nullarr();

	for (int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			scanf("%d", &a[i][j]);
			num[a[i][j]]++;	
		};
		if (ifnum())
			mnb = false;
		nullarr();
	};

	for (int j=0; j<9; j++) {
		for(int i=0; i<9; i++)
			num[a[i][j]]++;	
		if (ifnum())
			mnb = false;
		nullarr();
	};

	for (int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			scanf("%d", &zone);
			zones[zone][a[i][j]]++;	
		};
	};

	// for (int k=0; k<3; k++)
	// 	for(int m=0; m<3; m++) {
	// 		for (int i=0; i < 3; ++i)
	// 			for (int j = 0; j < 3; ++j)
	// 				num[a[i+3*k][j+3*m]]++;

	// 		if (ifnum())
	// 			mnb = false;
	// 		nullarr();
	// 		};

	if (mnb) printf("YES");
	else printf("NO");
	
	return 0;	
};

// int nullarr() {
// 	for (int i=1; i<10; i++)
// 		num[i] = 0;
// };

// bool ifnum() {
// 	bool b = false;
// 	for (int i = 1; i < 10; ++i)
// 		if (num[i] != 1) b = true;
// 	return b;
// }
