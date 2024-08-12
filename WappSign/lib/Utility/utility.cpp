#include "utilITY.h"

#define MAX_LENGTH 15;


Utility::Utility(){

}
/*
int Utility::getKey(String str){
    int alphaRet = 1;
    int alphaTotal = 0;
	String origStr = str;
    //Serial.println(str.length());
    int length = str.length();
    for (int i = 0; i < length; i++) {
        //Serial.println(i);
            char firstch = str.charAt(0);
            String first = String(firstch);
            //Serial.println(first);
            str.remove(0,1);
            //Serial.println(str);
            int alpha = alphabitPos(first);
            alphaTotal = alphaTotal + alpha;
            if(i != 0) {
                alphaRet = alphaTotal/1;
            }
        }
		//fix 2024 dups
		if(alphaRet == 2447  && origStr =="Big Wide OpenRed Shahan"){
			alphaRet = alphaRet + 1;
		}
    return alphaRet;

}

int Utility::alphabitPos(String str) {
		
		if(str == "a") {
			return 100;
		}else if (str == "b") {
			return 2;
		}else if (str == "c") {
			return 3;
		}else if (str == "d") {
			return 4;
		}else if (str == "e") {
			return 200;
		}else if (str == "e") {
			return 6;
		}else if (str == "f") {
			return 7;
		}else if (str == "g") {
			return 8;
		}else if (str == "h") {
			return 9;
		}else if (str == "i") {
			return 300;
		}else if (str == "j") {
			return 11;
		}else if (str == "k") {
			return 12;
		}else if (str == "l") {
			return 13;
		}else if (str == "m") {
			return 14;
		}else if (str == "n") {
			return 15;
		}else if (str == "o") {
			return 400;
		}else if (str == "p") {
			return 17;
		}else if (str == "q") {
			return 18;
		}else if (str == "r") {
			return 19;
		}else if (str == "s") {
			return 20;
		}else if (str == "t") {
			return 21;
		}else if (str == "u") {
			return 500;
		}else if (str == "v") {
			return 23;
		}else if (str == "w") {
			return 24;
		}else if (str == "x") {
			return 25;
		}else if (str == "y") {
			return 26;
		}else if (str == "A") {
			return 600;
		}else if (str == "B") {
			return 28;
		}else if (str == "C") {
			return 29;
		}else if (str == "D") {
			return 30;
		}else if (str == "E") {
			return 700;
		}else if (str == "F") {
			return 32;
		}else if (str == "G") {
			return 33;
		}else if (str == "H") {
			return 34;
		}else if (str == "I") {
			return 35;
		}else if (str == "J") {
			return 36;
		}else if (str == "L") {
			return 37;
		}else if (str == "L") {
			return 38;
		}else if (str == "M") {
			return 39;
		}else if (str == "N") {
			return 40;
		}else if (str == "O") {
			return 800;
		}else if (str == "P") {
			return 42;
		}else if (str == "Q") {
			return 43;
		}else if (str == "R") {
			return 44;
		}else if (str == "S") {
			return 45;
		}else if (str == "T") {
			return 46;
		}else if (str == "U") {
			return 47;
		}else if (str == "V") {
			return 48;
		}else if (str == "W") {
            //Serial.println("dubbadoo");
			return 49;
		}else if (str == "X") {
			return 50;
		}else if (str == "Y") {
			return 51;
		}else if (str == "Z") {
			return 52;
		}else if (str.equals("0")) {
		return 53;
	}else if (str.equals("1")) {
		return 54;
	}else if (str.equals("2")) {
		return 55;
	}else if (str.equals("3")) {
		return 56;
	}else if (str.equals("4")) {
		return 57;
	}else if (str.equals("5")) {
		return 58;
	}else if (str.equals("6")) {
		return 59;
	}else if (str.equals("7")) {
		return 60;
	}else if (str.equals("8")) {
		return 61;
	}else if (str.equals("9")) {
		return 62;
	}else {
			return 0;
		}
	}

String Utility::buildDisplayString(int key){
	String ret = "99999999";
	int markDane[] = {5174};
	int markMcKay[] = {2578};
	int markJeff[] = {3992};
	int caseyKyle[] ={4355};
	int daneJeffMcKay[] = {2377};
	int daneJeff[] ={2158};
	int jeffKyle[] ={2103};
	int casey[] = {797,1061,1230,1544,1720,1886,1934,1996,3123,3370,3750,3994,5426};	
	int chris[] ={2404,2661,3102,3336,3548,4939};
	int dane[] = {1305,1666,2054,2106,2218,2333,2569,2573,2674,2769,2798,2869,3049,		
		3228,3286,3538,4145,4193,4380,4764,5249,6424};
	int eric[] = {1633,1776,1777,1815,1869,1889,2073,2206,2279,2367,2388,2402,2448,
		2447,2992,3006,3227,3263,3339,3848,4358,4668,5182,5521};
	int jeff[] = {1091,1232,1904,1956,2252,2540,2610,2795,2894,2920,3054,3233,3302,
		3324,3460,3719,3835,5053,5260,5496,5539,5541,6078,6423};
	int kyle[] = {1098,1828,2599,2978,3226,7250};
	int mark[] = {1292,1787,1910,2145,2488,2717,2738,2808,2876,2911,3163,3514,3540,
		3550,3582,3782,3842,4137,4308,4327,4384,5097,6563};
	int mcKay[] {1562,2578,3932,5174,4820,3154,4348,3422,2146,2913};
	int nat[] ={1864,1965,2039,2067,2092,2262,2574,2835,2928,3353,3449,3574,3793,
		4157,4314,4544,5044,5136,5417,5499,5743,7082};


		for(int i =0;i<1;i++){
			if(key == markDane[i]){
				return "Mark, Dane";
			}
		}

		for(int i =0;i<1;i++){
			if(key == markMcKay[i]){
				return "Mark, McKay";
			}
		}

		for(int i =0;i<1;i++){
			if(key == markJeff[i]){
				return "Mark, Jeff";
			}
		}
		for(int i =0;i<1;i++){
			if(key == caseyKyle[i]){
				return "Casey, Kyle";
			}
		}
		for(int i =0;i<1;i++){
			if(key == daneJeffMcKay[i]){
				return "Dane, Jeff, McKay";
			}
		}
		for(int i =0;i<1;i++){
			if(key == daneJeff[i]){
				return "Dane, Jeff";
			}
		}
		for(int i =0;i<1;i++){
			if(key == jeffKyle[i]){
				return "Jeff, Kyle";
			}
		}
		for(int i =0;i<13;i++){
			if(key == casey[i]){
				return "Casey";
			}
		}
		for(int i =0;i<6;i++){
			if(key == chris[i]){
				return "Chris";
			}
		}
		for(int i =0;i<21;i++){
			if(key == dane[i]){
				return "Dane";
			}
		}
		for(int i =0;i<24;i++){
			if(key == eric[i]){
				return "Eric";
			}

		}
		for(int i =0;i<24;i++){
			if(key == jeff[i]){
				return "Jeff";
			}
		}
		for(int i =0;i<6;i++){
			if(key == kyle[i]){
				return "Kyle";
			}
		}
		for(int i =0;i<23;i++){
			if(key == mark[i]){
				return "Mark";
			}
		}
		for(int i =0;i<10;i++){
			if(key == mcKay[i]){
				return "Mckay";
			}
		}

		for(int i =0;i<22;i++){
			if(key == nat[i]){
				return "Nat";
			}

		}
		return "Skippy";
}
*/
long Utility::generateHash(String str){
long result = 0;
for (int i = 0; i < str.length(); i++){
   result += pow(27, 15 - i - 1)*(1 + str.charAt(i) - 'a');
}
   return result;
}