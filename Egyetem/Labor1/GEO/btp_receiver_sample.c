/* szukseges header fajlok betoltese */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

/* FELADAT: itt kell a gn.h header fajlt betolteni */
#include "gn.h"
const unsigned char *pkt_type[5] = {"GUC", "SHB", "TSB", "GBC", "GAC"};

// A BTP receiver program keretrendszere
int main(int argc, char* argv[]){

	// Valtozok deklaralasa
	int err;
	int sd;
	struct sockaddr_btp sbs;
	int len = sizeof(struct sockaddr_btp);
	unsigned char msg[2048] = {0};
	int count;
	unsigned char *str;
	struct timeval current_time, base_time;
	unsigned char mac[6];


/* FELADAT: I. Socket letrehozasa */
	/* sd =			// Socket	(ha a visszeteresi erteke nullatol nagyobb, akkor sikeres, ha 0 vagy -1, akkor a socket letrehozasa sikertelen)
	// Socket sikeres letrehozasanak ellenorzese:
	if((sd <= 0){
			perror("Hiba a socket letrehozasa kozben!");
			return 1;
		}

	/* FELADAT: Az struct sockaddr_btp struktura kitoltese */
	sbs.btp_family = PF_BTP;
	/*	sbs.sport = ;		// A BTP senderben beallitott Source port BTP-A eseten */

/* FELADAT: II. Bind a socketre */
	/*	err = 	// Bind az sd socketre. Ha sikeres a bind az err erteke 0, ha nem -1.
			if(	err != 0){
				perror("Hiba a bind soran!\n");
				close(sd);	//socket lezarasa
				return -1;  // hibaval visszateres
			}
	*/

/* FELADAT: III. Csomag vetele */
	count = 0;
	while(1){

		/* err =	//recvfrom fuggveny hivasa */
		if(err < 0){
				perror("Hiba az uzenet kuldese soran!\n");
				return -1;	// hibaval visszateres
		}

/* FELADAT: IV. Vett csomag parametereinek kiirasa */
		/* FELADAT: Egiszitse ki a megfelelo struktura elemmel a printf fuggvenyeket */
		/*printf("Vett csomag sorszama: (%d)\n", count++);
		printf("Altalnos info\n");
		printf("  merete              = %d\n", err);
		printf("  btp_type          = %s\n", == BTP_A ? "BTP_A" : "BTP_B"); //printf("btp_type = %s\n", sbs.btp_type == BTP_A ? "BTP_A" : "BTP_B");
		printf("  sport             = %d\n", );
		printf("  dport             = %d\n", );
		printf("  packet_type       = %s\n", );
		printf("  packet_src\n");
		printf("    gn_addr\n");
		printf("      manual        = %u\n", );
		printf("      type          = %u\n", );
		printf("      country_code  = %u\n", );
		memcpy(mac, sbs.src_pv.addr.mid, 6);
		printf("      mid           = %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
		printf("    timestamp       = %u\n", );
		printf("    latitude        = %d\n", );
		printf("    longitude       = %d\n", );
		printf("    pai             = %d\n", );
		printf("    speed           = %d\n", );
		printf("    heading         = %d\n", );
		*/

		/* FELADAT: GeoNetworking fejlec informaciok kiiratasa*/

		switch(sbs.packet_type){
			case PT_SHB:
				// Single hop broadcast eseten
				break;
			case PT_TSB:
				// Topology scopped broadcast eseten
				break;
			case PT_GBC:
				// GeoBroadcast eseten:
				/* GeoBroadcast specifikus informacio kiiratasa. Egiszitse ki a megfelelo struktura elemmel a printf fuggvenyeket */
				/*printf("gbc info\n");
				printf("  dest_area\n");
				printf("    area_type       = %d\n", );
				printf("    latitude        = %d\n", );
				printf("    longitude       = %d\n", );
				printf("    distance_a      = %d\n", );
				printf("    distance_b      = %d\n", );
				printf("    angle           = %d\n", );
				*/


				break;
			case PT_GUC:
				// GeoUnicast eseten:
				/* FELADAT: GeoUnicast specifikus informacio kiiratasa. Egiszitse ki a megfelelo struktura elemmel a printf fuggvenyeket */

				/*printf("guc info\n");
				printf("  dest_addr\n");
				printf("    manual          = %u\n", );
				printf("    type            = %u\n", );
				printf("    country_code    = %u\n", e);
				memcpy(mac, sbs.dest.addr.mid, 6);
				printf("    mid             = %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
				*/
				break;
		}
	}

/* FELADAT: V. Socket lezarasa */
	/* close(socket azonosito); */
	return 0;
}
