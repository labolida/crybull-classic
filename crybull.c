#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc , char ** argv ) {
	if (argc==1) {
		printf("Crybull classic - cryptography - Linux 64-bits by leonardo.labolida.com	(2024) \n" ) ;
		printf("This program is released under GNU GPL v3 license - https://www.gnu.org/licenses \n" ) ;
		printf("Missing parameters. Expected: PASSWORD INPUT-FILENAME OUTPUT-FILENAME \n" ) ;
		printf("  Example:   \n" ) ;
		printf("	crybull MySecretPassword  secretMessage.txt  encryptedMessage.txt	\n" ) ;
		printf("	crybull MySecretPassword  encryptedMessage.txt  secretMessage.txt	\n\n" ) ;
	}else{
		char * pwd	= argv[1];		// STDIN.PARAM: PASSWORD
		char * fn_in	= argv[2];		// STDIN.PARAM: INPUT-FILENAME
		char * fn_out   = argv[3];		// STDIN.PARAM: OUTPUT-FILENAME
		FILE * fp1 ;				// FILE POINTER IN
		FILE * fp2 ;				// FILE POINTER OUT
		int s=0;				// step (position in while)
		int c;					// char readed from file
		fp1 = fopen( fn_in  , "r");
		fp2 = fopen( fn_out , "w");
		while( (c = fgetc(fp1))!=EOF ) {
			int p = pwd[ ( s % strlen(pwd) ) ];
			fputc( c^p  , fp2 );                    // CLASSIC XOR VIGENERE
			s++;
		}
		fclose(fp1);
		fclose(fp2);
	}
}

