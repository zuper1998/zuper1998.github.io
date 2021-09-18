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

// A BTP sender program keretrendszere
int main(int argc, char* argv[]){

// Valtozok deklaralasa
	int err, i;
	int sd, ifindex;
	struct sockaddr_btp sbs;
	int len = sizeof(struct sockaddr_btp);
	unsigned char msg[2048] = {0};
	int index;
	int count;
	struct timeval current_time, base_time;
	int size, num;
	int shit = 0;
	int btp, pt, rep, scf, sec;
	unsigned char macAddr_c[6];
	unsigned int macAddr_i[6];

// Az elkeszitendo program argumentummaban kell megadni 8 darab parametert
	if(argc != 9){
  //Ha kevesebb, mint 8 parametert adunk meg akkor az alabbi manual irja ki a kepernyore:
		printf("btp_sender <btp_type> <pkt_type> <rep_interval> <pos_lat> <pos_long> <scf> <sec_profile> <peer_mac>\n");
		printf("-- Hasznalat --\n");
		printf("<btp_type> BTP tipusa 0:BTP_A/1:BTP_B\n");
		printf("<pkt_type> GeoNetworking csomagtipusa 0:GUC/1:SHB/2:TSB/3:GBC\n");
		printf("<rep_interval> Az ismetles idointervalluma:ms\n");
		printf("<pos_lat> GBC eseten az arena kozepenek lat koordinataja\n");
		printf("<pos_long> GBC eseten az arena kozepenek long koordinataja\n");
		printf("<scf> Store and forward 0:tiltas/1:engedelyezes\n");
		printf("<sec_profile> Csomagok titkositasanak engedelyezese 0:None/1:CAM/2:DENM/3:Normal\n");
		printf("<peer_mac> A kuldo MAC cime GUC eseten szukseges, formatuma: XX:XX:XX:XX:XX:XX\n");
		printf("pelda az argumentummok megadasara: \n");
		printf("  btp_sender 0 1 1000 0 0 0 4 FF:FF:FF:FF:FF:FF\n");
		return 1;
	}

/* FELADAT: Az argumentumban megadott ertekeket rendelje hozza egy valtozohoz az atoi fuggveny segitsegvel. Egy pelda az elso argumentum hozzarendelesere: 		btp = atoi(argv[1]);*/
	/*
	  btp =          // BTP tipusa
		pt =           // GeoNetworking csomagtipusa
		rep =          // Az ismetles idointervalluma
		scf =          // Store and forward
		sec =          // Csomagok titkositasanak engedelyezese
	*/

/* FELADAT: I. Socket letrehozasa */
	/* sd =			// Socket	(ha a visszeteresi erteke nullatol nagyobb, akkor sikeres, ha 0 vagy -1, akkor a socket letrehozasa sikertelen)

	// Socket sikeres letrehozasanak ellenorzese:
	if((sd <= 0){
			perror("Hiba a socket letrehozasa kozben!");
			return 1;
		}
*/

/* FELADAT: Az struct sockaddr_btp struktura kitoltese */
	/*
	sbs.btp_family = PF_BTP;
	sbs.btp_type = 			// BTP tipusa
	sbs.sport = 				// Source port BTP-A eseten
	sbs.dport = 				// Destination port BTP-A/BTP-B eseten
	sbs.dport_info = 		// Destination port info BTP-B eseten
	sbs.packet_type = 	// GeoNetworking csomagtipusa
	*/
	if(pt == 0){  /* GUC csomag */
		/* MAC cim feldolgozosa */
		if(sscanf(argv[7], "%2x:%2x:%2x:%2x:%2x:%2x\n", &macAddr_i[0], &macAddr_i[1], &macAddr_i[2], &macAddr_i[3], &macAddr_i[4], &macAddr_i[5]) != 6) {
			printf("Hibas MAC cim. Az elfogadott formatum: XX:XX:XX:XX:XX:XX\n");
			return 0;
		}
		for(i = 0; i < 6; i++) {
			macAddr_c[i] = (unsigned char) macAddr_i[i];
		}
		memcpy(sbs.dest.addr.mid, macAddr_c, 6);	// MAC cim sbs strukturaba helyezese memcpy segitsegvel
	}
	else if(pt == 3){  /* GBC csomag */

/* FELADAT: Struktura parameterek beallitase GBC eseten */
	  /*sbs.dest.area.area_type = ;					// GeoNetworking arena tipusa pl. kor, teglalap, ellipszis: AT_CIRCLE, AT_RECT, AT_ELIP
		sbs.dest.area.pos_latitude = ;				// GBC eseten az arena kozepenek lat koordinataja - WGS-84 latitude for the center position of the geometric shape.
		sbs.dest.area.pos_longitude = ;				// GBC eseten az arena kozepenek long koordinataja - WGS-84 longitude for the center position of the geometric shape.
		sbs.dest.area.distance_a = ;					// Distance a of the geometric shape in meters.
		sbs.dest.area.distance_b = ;					// Distance b of the geometric shape in meters.
		sbs.dest.area.angle = 0;							// Angle of the geometric shape in degrees form North.
		*/

	}
	//A struktura egyeb parameterei
	sbs.packet_lifetime.multiplier = 12; 		// Csomag elettartam szorzo
	sbs.packet_lifetime.base = 1;  					// Csomag elettartam alap		/* 12 * 1s = 12s */
	sbs.max_repeat_time = 10 * 1000;  			// Max ismetles ideje				/* 10s */
	sbs.repeat_interval = rep;							// argumentumban beallitott repeat_interval
	sbs.hop_limit = 10;											// Hop limit (csomag ugrasok maximalis szama)
	sbs.comm_profile = CP_G5A;							// Kommunikacios profill (ITS-G5A)
	sbs.sec_profile = 0;										// Biztonsagi profill (nem hasznaljuk 0)
	sbs.tc.tc_scf = scf;
	sbs.tc.tc_id= 0;
	sbs.tc.tc_co= 0;

/* FELADAT: II. Bind a socketre */
/*	err = 	// Bind az sd socketre. Ha sikeres a bind az err erteke 0, ha nem -1.
		if(	err != 0){
			perror("Hiba a bind soran!\n");
			close(sd);	//socket lezarasa
			return -1;  // hibaval visszateres
		}
*/

/* FELADAT: III. Csomag kuldese */
	// Kuldendo uzenet
	/*msg = "";		//Az atkuldendo uzenet pl. msg = "Demo uzenet";
		err =	//sendto fuggveny hivasa
		if(err < 0){
				perror("Hiba az uzenet kuldese soran!\n");
				return -1;	// hibaval visszateres
		}
*/

/* FELADAT: IV. Socket lezarasa */
	/* close(socket azonosito); */
	return 0; 	// Visszateresi ertek
} //main() vege
