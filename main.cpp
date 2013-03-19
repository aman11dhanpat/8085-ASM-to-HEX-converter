#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <climits>
#include <getopt.h>
using namespace std;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define REPS(p,s) for (char * p = s; *p ; p++)
#define FOR(var,start,end) for (int var=(start); var<(int)(end); ++var)
#define FORD(var,start,end) for (int var=(start); var>=(int)(end); --var)
#define PB push_back
#define PF push_front
#define BP pop_back
#define FP pop_front
#define BN begin()
#define RN rbegin()
#define RD rend()
#define ED end()
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define IT(X) __typeof((X).BN)
#define RIT(X) __typeof((X).RN)
#define REF(X) __typeof(__typeof(X)::reference)
#define FORIT(it, X) for(IT(X) it = (X).BN; it != (X).ED; ++it)
#define FORITR(it, X) for(RIT(X) it = (X).RN; it != (X).RD; ++it)
#define VV(X) vector < vector< X > >
#define PIB(X)  pair<IT(X),bool >

typedef long long LL;
typedef unsigned long long ULL;
typedef istringstream ISS;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector< PII > VPII;

char * program_name;

struct desc {
        string code;
        int num;
        int size;
        desc(){}
        desc ( string a , int n, int s ) {
                code = a;
                num = n;
                size = s ;
        }
};

map < string , desc > num;
map < string , string > hash;

void make_num ()
{
        num.insert ( pair<string, desc> ( "ACI" , desc ( "CE" , 0 , 2 ) ) );
        num.insert ( pair<string, desc> ( "ADC" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCA" , desc ( "8F" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCB" , desc ( "88" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCC" , desc ( "89" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCD" , desc ( "8A" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCE" , desc ( "8B" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCH" , desc ( "8C" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCL" , desc ( "8D" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADCM" , desc ( "8E" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADD" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDA" , desc ( "87" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDB" , desc ( "80" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDC" , desc ( "81" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDD" , desc ( "82" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDE" , desc ( "83" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDH" , desc ( "84" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDL" , desc ( "85" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADDM" , desc ( "86" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ADI" , desc ( "C6" , 0, 2 ) ) );
        num.insert ( pair<string, desc> ( "ANA" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAA" , desc ( "A7" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAB" , desc ( "A0" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAC" , desc ( "A1" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAD" , desc ( "A2" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAE" , desc ( "A3" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAH" , desc ( "A4" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAL" , desc ( "A5" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANAM" , desc ( "A6" , 0, 1 ) ) );
        num.insert ( pair<string, desc> ( "ANI" , desc ( "E6" , 0, 2 ) ) );
        num.insert ( pair<string, desc> ( "CALL" , desc ( "CD" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CC" , desc ( "DC" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CNC" , desc ( "D4" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CP" , desc ( "F4" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CM" , desc ( "FC" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CPE" , desc ( "EC" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CPO" , desc ( "E4" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CZ" , desc ( "CC" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CNZ" , desc ( "C4" , 0 , 3 ) ) );
        num.insert ( pair<string, desc> ( "CMA" , desc ( "2F" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMC" , desc ( "3F" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMP" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPA" , desc ( "BF" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPB" , desc ( "B8" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPC" , desc ( "B9" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPD" , desc ( "BA" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPE" , desc ( "BB" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPH" , desc ( "BC" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPL" , desc ( "BD" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CMPM" , desc ( "BE" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "CPI" , desc ( "FE" , 0 , 2 ) ) );
        num.insert ( pair<string, desc> ( "DAA" , desc ( "27" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DAD" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DADBC" , desc ( "09" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DADDE" , desc ( "19" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DADHL" , desc ( "29" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DADSP" , desc ( "39" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCR" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRA" , desc ( "3D" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRB" , desc ( "05" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRC" , desc ( "0D" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRD" , desc ( "15" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRE" , desc ( "1D" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRH" , desc ( "25" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRL" , desc ( "2D" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCRM" , desc ( "35" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCX" , desc ( "" , 1 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCXB" , desc ( "0B" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCXD" , desc ( "1B" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCXH" , desc ( "2B" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DCXSP" , desc ( "3B" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "DI" , desc ( "F3" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "EI" , desc ( "FB" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "HLT" , desc ( "76" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INR" , desc ( "" , 1 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRA" , desc ( "3C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRB" , desc ( "04" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRC" , desc ( "0C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRD" , desc ( "14" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRE" , desc ( "1C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRH" , desc ( "24" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRL" , desc ( "2C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INRM" , desc ( "34" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "IN" , desc ( "DB" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "INX" , desc ( "" , 1 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INXB" , desc ( "03" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INXD" , desc ( "13" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INXH" , desc ( "23" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "INXSP" , desc ( "33" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "JC" , desc ( "DA" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JNC" , desc ( "D2" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JP" , desc ( "F2" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JM" , desc ( "FA" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JPE" , desc ( "EA" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JPO" , desc ( "E2" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JZ" , desc ( "CA" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "JNZ" , desc ( "C2" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LDA" , desc ( "3A" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LDAX" , desc ( "" , 1 , 1 ) ) );
	num.insert ( pair<string, desc> ( "LDAXB" , desc ( "0A" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "LDAXD" , desc ( "1A" , 0 , 1 ) ) );
        num.insert ( pair<string, desc> ( "LXI" , desc ( "" , 1 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LXIH" , desc ( "21" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LXIB" , desc ( "01" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LXID" , desc ( "11" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LXISP" , desc ( "31" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "LHLD" , desc ( "2A" , 0 , 3 ) ) );
	num.insert ( pair<string, desc> ( "MOV" , desc ( "" , 2 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAA" , desc ( "7F" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAB" , desc ( "78" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAC" , desc ( "79" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAD" , desc ( "7A" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAE" , desc ( "7B" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAH" , desc ( "7C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAL" , desc ( "7D" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVAM" , desc ( "7E" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBA" , desc ( "47" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBB" , desc ( "40" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBC" , desc ( "41" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBD" , desc ( "42" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBE" , desc ( "43" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBH" , desc ( "44" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBL" , desc ( "45" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVBM" , desc ( "46" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCA" , desc ( "4F" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCB" , desc ( "48" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCC" , desc ( "49" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCD" , desc ( "4A" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCE" , desc ( "4B" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCH" , desc ( "4C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCL" , desc ( "4D" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVCM" , desc ( "4E" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDA" , desc ( "57" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDB" , desc ( "50" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDC" , desc ( "51" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDD" , desc ( "52" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDE" , desc ( "53" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDH" , desc ( "54" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDL" , desc ( "55" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVDM" , desc ( "56" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEA" , desc ( "5F" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEB" , desc ( "58" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEC" , desc ( "59" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVED" , desc ( "5A" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEE" , desc ( "5B" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEH" , desc ( "5C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEL" , desc ( "5D" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVEM" , desc ( "5E" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHA" , desc ( "67" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHB" , desc ( "60" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHC" , desc ( "61" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHD" , desc ( "62" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHE" , desc ( "63" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHH" , desc ( "64" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHL" , desc ( "65" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVHM" , desc ( "66" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLA" , desc ( "6F" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLB" , desc ( "68" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLC" , desc ( "69" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLD" , desc ( "6A" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLE" , desc ( "6B" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLH" , desc ( "6C" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLL" , desc ( "6D" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVLM" , desc ( "6E" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVMA" , desc ( "77" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVMB" , desc ( "70" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVMC" , desc ( "71" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVMD" , desc ( "72" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVME" , desc ( "73" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVMH" , desc ( "74" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVML" , desc ( "75" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MOVMM" , desc ( "76" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "MVI" , desc ( "" , 1 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIA" , desc ( "3E" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIB" , desc ( "06" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIC" , desc ( "0E" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVID" , desc ( "16" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIE" , desc ( "1E" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIH" , desc ( "26" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIL" , desc ( "2E" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "MVIM" , desc ( "36" , 0 , 2 ) ) );
	num.insert ( pair<string, desc> ( "NOP" , desc ( "00" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAA" , desc ( "B7" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAB" , desc ( "B0" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAC" , desc ( "B1" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAD" , desc ( "B2" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAE" , desc ( "B3" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAH" , desc ( "B4" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAL" , desc ( "B5" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORAM" , desc ( "B6" , 0 , 1 ) ) );
	num.insert ( pair<string, desc> ( "ORI" , desc ( "F6" , 0 , 2 ) ) );
//---------------------------------------------------------------------------------------------//
	num.insert ( pair<string, desc> ( "LABEL" , desc ( "" , 0 , 0 ) ) );
}

const struct option long_options[] = {
        { "help", 0 , NULL , 'h' },
        { "input-file", 1, NULL, 'i' },
        { "output-file", 1, NULL, 'o' },
        { "hex", 0, NULL, 'x' },
        { "binary", 0, NULL, 'b' },
        { "print_sample", 0, NULL, 'p' }
};

void print_usage ( FILE * stream , int exit_code )
{
        fprintf ( stream, "Usage: %s [options] --input-file=in.asm --output-file=out.hex\n", program_name );
        fprintf ( stream,
                  " -h --help\t\t\tDisplay this usage information.\n"
                  " -i --input-file\t\tInput assembly file. \n"
                  " -o --output-file\t\tFilename Write output to file.\n"
                  " -x --hex\t[Default]\tTo write the file in HEX ASCII format.\n"
                  " -b --binary\t\t\tTo write the file in Binary ASCII format\n"
                  " -p --print-sample\t\tPrints a sample code which this program accepts\n" );
        exit ( exit_code );
}

void print_sample ( FILE * stream )
{
        fprintf ( stream,
                  "Sample program\n\nSTART 0000H\n"
                  "MVI E,00H\nLHLD 4200H\nMOV C,L\nMOV B,H\nLHLD 4202H\nDAD B\nJNC LABEL1\nINR E\nLABEL1:\nSHLD 4204H\nMOV A,E\nSTA 4206H\nHLT\n"
                  "\nPlease ensure all the characters are UPPER CASE and numbers have H as suffix eg. MVI A, 10H.\nWrite the program with a statement START XXXXH for assembler to load address\n" );
}

string infread ( FILE * in )
{
        string temp = "" , code = "";
        char buff[100];
        while ( fscanf ( in , "%s" , buff ) != EOF ) {
                temp = string ( buff );
                code += " " + temp;
        }
        return code;
}

vector <string> tokenize ( string code , const char tok[] )
{
        vector <string> data;
        string temp;
        char * pch;
        pch = strtok ( ( char * ) code.c_str() , tok );
        while ( pch ) {
                temp = string ( pch );
                /*if ( (pch-1) == ':' )
                	hash [temp] = "";*/
                data.PB ( temp );
                pch = strtok ( NULL, tok );
        }
        return data;
}

void make_hash ( vector <string> & code_tok , int start )
{
	char buff[10] , str[10];
	printf ("Lookup table\n");
	printf ("+----------+---------------+\n");
	printf ("|%10s|%15s|\n" , "Label" , "Address");
	printf ("+----------+---------------+\n");
	FOR ( i , 2 , code_tok.size() )
	{
		if ( code_tok [i].c_str() [code_tok[i].length()-1] == ':' )
		{
			strcpy(buff , code_tok [i].c_str() );
			buff [code_tok[i].length()-1] = '\0';
			sprintf (str , "%04X" , start);
			hash.insert ( make_pair (string (buff) , string(str)) );
			//code_tok [i] = "LABEL";
			num.insert ( pair<string, desc> ( code_tok [i] , desc ( "" , 0 , 0 ) )     );
			printf ( "|%10s|" , buff);
			sprintf (buff , "0x%s" , str );
			printf ("%15s|\n" , buff );
		}
		else
		{
			start += num [code_tok [i]].size;
		}
	}
	printf ("+----------+---------------+\n");
}

int main ( int argc, char *argv[] )
{
        program_name = argv[0];
        FILE * in = stdin;
        FILE * out = stdout;
        int next_option;
        string code;
        int starting;
        vector <string> code_tok;
        if ( argc > 1 ) {
                do {
                        next_option = getopt_long ( argc , argv, "hpi:o:xb", long_options, NULL );

                        switch ( next_option ) {
                        case 'h' :
                                print_usage ( stderr, 0 );
                                break;
                        case 'i' :
                                in = fopen ( optarg , "r" );
                                break;
                        case 'o' :
                                printf ( "o\n" );
                                break;
                        case 'x' :
                                printf ( "x\n" );
                                break;
                        case 'b' :
                                printf ( "b\n" );
                                break;
                        case 'p' :
                                print_sample ( stderr );
                                exit ( 0 );
                                break;
                        default :
                                break;//abort();
                        }
                } while ( next_option != -1 );
        } else {
                fprintf ( stderr, "Enter the ASM code below\nPress Ctrl + D when done\n" );
        }
        code = infread ( in );
        code_tok  = tokenize ( code , " ," );
	char tempc [6];
        if ( code_tok [0] != "START" || ( sscanf ( code_tok[1].c_str(), "%sH" , tempc ) ) == 0 ) {
                fprintf ( stderr , "Please start your program with START XXXXH\nSee the sample program\n" );
                print_sample ( stderr );
                exit ( 1 );
        }
	starting = strtol ( tempc , NULL , 16 );
	string temp , opc , hex;
	int val;
	desc nu;
	make_num();
	make_hash( code_tok , starting );
	printf ("\nCode formatted\n");
	printf ("+----------+---------------+----------+\n");
	printf ("|%10s|%15s|%10s|\n" , "Address" , "Mnemonic" , "HEX");
	printf ("+----------+---------------+----------+\n");
	FOR ( i , 2 , code_tok.size() )
	{
		temp = code_tok [i];
		printf ("|0x%04X    |" , starting);
		if ( num.find(temp) == num.end() )
		{
			fprintf (stderr , "Cant find a mnemonic/symbol named %s at line number %d\n" , temp.c_str() , __LINE__);
			continue;
		}
		nu = num[temp];
		opc = temp;
		while(nu.num--)
		{
			temp += code_tok [++i];
			opc += " " + code_tok [i];
		}
		if ( num.find(temp) == num.end() )
		{
			fprintf (stderr , "Cant find a mnemonic/symbol named %s at line number %d\n" , temp.c_str() , __LINE__);
			continue;
		}
		nu = num[temp];
		hex = nu.code + " ";
		starting += nu.size;
		if (nu.size > 1)
		{	
			opc += " " + code_tok[++i];
			temp = code_tok[i];
			if ( hash.find(temp) == hash.end() )
			{
				if ( sscanf ( temp.c_str() , "%xH" , &val ) == 0 )
				{
					fprintf (stderr, "No %s symbol table at line number %d\n" , temp.c_str() , __LINE__);
					continue;
				}
				if ( nu.size == 3 )
				{
					sscanf ( temp.c_str() , "%sH" , tempc);
					//strcpy ( tempc , code_tok [++i].c_str() );
					//cout << " : " << tempc << " : ";
					tempc [0] = tempc [0] ^ tempc [2];
					tempc [2] = tempc [0] ^ tempc [2];
					tempc [0] = tempc [0] ^ tempc [2];
					tempc [1] = tempc [1] ^ tempc [3];
					tempc [3] = tempc [1] ^ tempc [3];
					tempc [1] = tempc [1] ^ tempc [3];
					tempc [5] = '\0';
					tempc [4] = tempc [3];
					tempc [3] = tempc [2];
					tempc [2] = ' ' ;
					hex += tempc;
					//cout << "hex : " << hex << " : ";	
				}
				else
				{
					temp.replace ( 2 , 1 , 1 , ' ' );
					hex += temp;
				}
			}
			else
			{
				 sscanf ( hash [temp].c_str() , "%sH" , tempc);
		                 //strcpy ( tempc , code_tok [++i].    c_str() );
		                 //cout << " : " << tempc << " : ";
		                 tempc [0] = tempc [0] ^ tempc [2];
		                 tempc [2] = tempc [0] ^ tempc [2];
		                 tempc [0] = tempc [0] ^ tempc [2];
		                 tempc [1] = tempc [1] ^ tempc [3];
		                 tempc [3] = tempc [1] ^ tempc [3];
		                 tempc [1] = tempc [1] ^ tempc [3];
		                 tempc [5] = '\0';
		                 tempc [4] = tempc [3];
		                 tempc [3] = tempc [2];
		                 tempc [2] = ' ' ;
		                 hex += tempc;
			}
		}
		printf ("%-15s|" , opc.c_str());
		printf ("%-10s|\n" , hex.c_str());
	}
	printf ("+----------+---------------+----------+\n");
        fclose ( in );
        fclose ( out );
        return 0;
}
