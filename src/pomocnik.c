#include <stdio.h>
#include <allegro.h>


BITMAP *rysunek = NULL;
BITMAP *bufor_ekranu = NULL;
BITMAP *kursor = NULL;

FONT *czcionka = NULL;
DATAFILE *dat = NULL;
FONT *czcionka_m = NULL;
DATAFILE *dat2 = NULL;

int il_liter = 13;
int il_liter_temp = 100;
int edit = 0; //0 - nic 1- pole ilosci liter 2- haslo
int wcisniety =0; // 0- wcisniety 1- nie ;)
int pozycja = 0;
int strona = 0;
int anagram = 0;
int znal_w = 0;

int mx = 0,my = 0,mb = 0,k = 0;


int linia_wynik=0;

	char hasla_w[110000];

	char hasla02[110000];
	char hasla03[110000];
	char hasla04[110000];
	char hasla05[110000];
	char hasla06[110000];
	char hasla07[110000];
	char hasla08[110000];
	char hasla09[110000];
	char hasla10[110000];
	char hasla11[110000];
	char hasla12[110000];
	char hasla13[110000];
	char hasla14[110000];
	char hasla15[110000];
	char hasla16[110000];
	char hasla17[110000];
	char hasla18[110000];
	char hasla19[110000];
	char hasla20[110000];
	char hasla21[110000];
	char hasla22[110000];
	char hasla23[110000];



char haslo[23] = "";


int zwroc_char(int in) {
	int out=120;
	if(in==12) {  //�
		out=41; }
	if(in==11) {  //�
		out=40; }
	if(in==30) {  //a
		out=97; }
	if(in==7) {  //b
		out=98; }
	if(in==33) {  //c
		out=99; }
	if(in==37) {  //d
		out=100; }
	if(in==16) {  //e
		out=101; }
	if(in==18) {  //f
		out=102; }
	if(in==35) {  //g
		out=103; }
	if(in==28) {  //h
		out=104; }
	if(in==26) {  //i
		out=105; }
	if(in==29) {  //j
		out=106; }
	if(in==19) {  //k
		out=107; }
	if(in==24) {  //l
		out=108; }
	if(in==6) {  //m
		out=109; }
	if(in==5) {  //n
		out=110; }
	if(in==20) {  //o
		out=111; }
	if(in==25) {  //p
		out=112; }
	if(in==9) {  //q
		out=113; }
	if(in==17) {  //r
		out=114; }
	if(in==34) {  //s
		out=115; }
	if(in==21) {  //t
		out=116; }
	if(in==31) {  //u
		out=117; }
	if(in==8) {  //v
		out=118; }
	if(in==15) {  //w
		out=119; }
	if(in==22) {  //x
		out=120; }
	if(in==23) {  //y
		out=121; }
	if(in==32) {  //z
		out=122; }
	if(in==1) {  //�
		out=33; }
	if(in==36) {  //�
		out=34; }
	if(in==4) {  //�
		out=35; }
	if(in==3) {  //�
		out=36; }
	if(in==13) {  //�
		out=43; }
	if(in==14) {  //�
		out=38; }
	if(in==2) {  //�
		out=39; }
	return out;
}

int haslaxx(int ilosc, int poz) {
	int out=0;
	if(ilosc==2) {
		out=hasla02[poz]; }
	if(ilosc==3) {
		out=hasla03[poz]; }
	if(ilosc==4) {
		out=hasla04[poz]; }
	if(ilosc==5) {
		out=hasla05[poz]; }
	if(ilosc==6) {
		out=hasla06[poz]; }
	if(ilosc==7) {
		out=hasla07[poz]; }
	if(ilosc==8) {
		out=hasla08[poz]; }
	if(ilosc==9) {
		out=hasla09[poz]; }
	if(ilosc==10) {
		out=hasla10[poz]; }
	if(ilosc==11) {
		out=hasla11[poz]; }
	if(ilosc==12) {
		out=hasla12[poz]; }
	if(ilosc==13) {
		out=hasla13[poz]; }
	if(ilosc==14) {
		out=hasla14[poz]; }
	if(ilosc==15) {
		out=hasla15[poz]; }
	if(ilosc==16) {
		out=hasla16[poz]; }
	if(ilosc==17) {
		out=hasla17[poz]; }
	if(ilosc==18) {
		out=hasla18[poz]; }
	if(ilosc==19) {
		out=hasla19[poz]; }
	if(ilosc==20) {
		out=hasla20[poz]; }
	if(ilosc==21) {
		out=hasla21[poz]; }
	if(ilosc==22) {
		out=hasla22[poz]; }
	if(ilosc==23) {
		out=hasla23[poz]; }
	return out;
}

//haslaxx zwraca nr chara ktory jest pod dana komorka w danej tablicy hasel
void czysc_wynik( void )
{
	int tmp1=0;
	for(tmp1=0; tmp1<(110000-50); tmp1++) { //wyczcysc wyniki
		hasla_w[tmp1]=0;
	}
}

void wynik( void )
{
	int tmp1=0;
	int tmp2=0;
	int tmp3=0;
	int znaleziono=1;
	int znaleziono2=1;
	int poz_znal=0;
	char haslo2[23];
	char haslo_zn[23];
	znal_w=0;

	for(tmp1=0; tmp1<(110000-50); tmp1++) { //wyczcysc wyniki
		hasla_w[tmp1]=0;
	}
	if(anagram==0) {
		for(tmp1=0; tmp1<(110000-50); tmp1=tmp1+il_liter+1) {
			if(haslaxx(il_liter, tmp1)==43) {
				tmp1=110000;
			}
			else {
				znaleziono=1;
				for(tmp2=1; tmp2<=il_liter; tmp2++) {
					if( (haslo[tmp2-1]!=0) && (zwroc_char(haslaxx(il_liter, tmp1+tmp2))!=haslo[tmp2-1]) ) {
						znaleziono=0;
					}
				}
				if(znaleziono==1) { //wgraj do tablicy wynik�w
					znal_w++;
					hasla_w[poz_znal]=10; //0a poczatek slowa
					poz_znal++;
					for(tmp2=1; tmp2<=il_liter; tmp2++) {
						hasla_w[poz_znal]=97;
						hasla_w[poz_znal]=zwroc_char(haslaxx(il_liter, tmp1+tmp2));
						poz_znal++;
					}
				}
			}
		}
	}
	else {
		for(tmp1=0; tmp1<(110000-50); tmp1=tmp1+il_liter+1) {
			if(haslaxx(il_liter, tmp1)==43) {
				tmp1=110000;
			}
			else {
				for(tmp2=0; tmp2<23; tmp2++) {
					haslo_zn[tmp2]=0;
					haslo2[tmp2]=haslo[tmp2];
				}
				for(tmp2=1; tmp2<=il_liter; tmp2++) {
					haslo_zn[tmp2-1]=zwroc_char(haslaxx(il_liter, tmp1+tmp2));
				}
				znaleziono=1;
//				strcpy(haslo2, haslo);
				for(tmp2=1; tmp2<=il_liter; tmp2++) {
				    for(tmp3=1; tmp3<=il_liter; tmp3++) {
					if( (haslo2[tmp2-1]!=0) && (haslo_zn[tmp3-1]!=0) && (haslo_zn[tmp3-1]==haslo[tmp2-1]) ) {
						haslo2[tmp2-1]=0;
						haslo_zn[tmp3-1]=0;
					}
				    }
				}
				for(tmp2=0; tmp2<il_liter; tmp2++) {
					if(haslo2[tmp2]>0) {
						znaleziono=0;
					}
				}
				if(znaleziono==1) { //wgraj do tablicy wynik�w
					znal_w++;
					hasla_w[poz_znal]=10; //0a poczatek slowa
					poz_znal++;
					for(tmp2=1; tmp2<=il_liter; tmp2++) {
						hasla_w[poz_znal]=97;
						hasla_w[poz_znal]=zwroc_char(haslaxx(il_liter, tmp1+tmp2));
						poz_znal++;
					}
				}
			}
		}

	}
}

void kratka(int poz_x, int poz_y)
{
	int ciemny = makecol(96,120,255);
	int jasny = makecol(210,230,255);
	int posredni = makecol(128,160,255);

	int tx, ty, tymczasowa;
	//x 64-128  y 128-170

	line(bufor_ekranu,poz_x,poz_y+41,poz_x+31,poz_y+41,jasny);
	line(bufor_ekranu,poz_x,poz_y+40,poz_x+31,poz_y+40,jasny);

	line(bufor_ekranu,poz_x+30,poz_y,poz_x+30,poz_y+41,jasny);
	line(bufor_ekranu,poz_x+31,poz_y,poz_x+31,poz_y+41,jasny);

	line(bufor_ekranu,poz_x,poz_y,poz_x+31,poz_y,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+30,poz_y+1,ciemny);

	line(bufor_ekranu,poz_x,poz_y,poz_x,poz_y+41,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+1,poz_y+40,ciemny);

	for(tx=2; tx<30; tx++) {
		for(ty=2; ty<40; ty++) {
			tymczasowa=(tx+ty)/2;
			if((tymczasowa*2)==(tx+ty)) {
				putpixel(bufor_ekranu,poz_x+tx,poz_y+ty,posredni);
			}
		}
	}
}

void kratka2(int poz_x, int poz_y)
{
	int ciemny = makecol(32,70,200);
	int jasny = makecol(150,170,200);
	int posredni = makecol(60,100,200);

	int tx, ty, tymczasowa;

	line(bufor_ekranu,poz_x,poz_y+41,poz_x+31,poz_y+41,jasny);
	line(bufor_ekranu,poz_x,poz_y+40,poz_x+31,poz_y+40,jasny);

	line(bufor_ekranu,poz_x+30,poz_y,poz_x+30,poz_y+41,jasny);
	line(bufor_ekranu,poz_x+31,poz_y,poz_x+31,poz_y+41,jasny);

	line(bufor_ekranu,poz_x,poz_y,poz_x+31,poz_y,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+30,poz_y+1,ciemny);

	line(bufor_ekranu,poz_x,poz_y,poz_x,poz_y+41,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+1,poz_y+40,ciemny);

	for(tx=2; tx<30; tx++) {
		for(ty=2; ty<40; ty++) {
			tymczasowa=(tx+ty)/2;
			if((tymczasowa*2)==(tx+ty)) {
				putpixel(bufor_ekranu,poz_x+tx,poz_y+ty,posredni);
			}
		}
	}
}

void przycisk(int poz_x, int poz_y)
{
	int ciemny = makecol(96,120,255);
	int jasny = makecol(210,230,255);
	int posredni = makecol(128,160,255);

	int tx, ty, tymczasowa;

	line(bufor_ekranu,poz_x,poz_y+41,poz_x+165,poz_y+41,jasny);
	line(bufor_ekranu,poz_x,poz_y+40,poz_x+165,poz_y+40,jasny);

	line(bufor_ekranu,poz_x+164,poz_y,poz_x+164,poz_y+41,jasny);
	line(bufor_ekranu,poz_x+165,poz_y,poz_x+165,poz_y+41,jasny);

	line(bufor_ekranu,poz_x,poz_y,poz_x+165,poz_y,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+164,poz_y+1,ciemny);

	line(bufor_ekranu,poz_x,poz_y,poz_x,poz_y+41,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+1,poz_y+40,ciemny);

	for(tx=2; tx<163; tx++) {
		for(ty=2; ty<40; ty++) {
			tymczasowa=(tx+ty)/2;
			if((tymczasowa*2)==(tx+ty)) {
				putpixel(bufor_ekranu,poz_x+tx,poz_y+ty,posredni);
			}
		}
	}
}

void przycisk2(int poz_x, int poz_y)
{
	int ciemny = makecol(150,170,200);
	int jasny = makecol(32,70,200);
	int posredni = makecol(60,100,200);

	int tx, ty, tymczasowa;

	line(bufor_ekranu,poz_x,poz_y+41,poz_x+165,poz_y+41,jasny);
	line(bufor_ekranu,poz_x,poz_y+40,poz_x+165,poz_y+40,jasny);

	line(bufor_ekranu,poz_x+164,poz_y,poz_x+164,poz_y+41,jasny);
	line(bufor_ekranu,poz_x+165,poz_y,poz_x+165,poz_y+41,jasny);

	line(bufor_ekranu,poz_x,poz_y,poz_x+165,poz_y,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+164,poz_y+1,ciemny);

	line(bufor_ekranu,poz_x,poz_y,poz_x,poz_y+41,ciemny);
	line(bufor_ekranu,poz_x+1,poz_y+1,poz_x+1,poz_y+40,ciemny);

	for(tx=2; tx<163; tx++) {
		for(ty=2; ty<40; ty++) {
			tymczasowa=(tx+ty)/2;
			if((tymczasowa*2)==(tx+ty)) {
				putpixel(bufor_ekranu,poz_x+tx,poz_y+ty,posredni);
			}
		}
	}
}


void pisztext(int pozycja_x, int pozycja_y, char tekst[], int kolor)
{
	textprintf(bufor_ekranu,czcionka,pozycja_x+3,pozycja_y+3,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka,pozycja_x-1,pozycja_y,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka,pozycja_x,pozycja_y-1,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka,pozycja_x+1,pozycja_y,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka,pozycja_x,pozycja_y+1,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka,pozycja_x,pozycja_y,kolor,tekst);
}

void pisztext2(int pozycja_x, int pozycja_y, char tekst[], int kolor)
{
	textprintf(bufor_ekranu,czcionka_m,pozycja_x+3,pozycja_y+3,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka_m,pozycja_x-1,pozycja_y,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka_m,pozycja_x,pozycja_y-1,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka_m,pozycja_x+1,pozycja_y,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka_m,pozycja_x,pozycja_y+1,makecol(0,0,0),tekst);

	textprintf(bufor_ekranu,czcionka_m,pozycja_x,pozycja_y,kolor,tekst);
}

void ilosc (int poz_x, int poz_y) {
	char il[50];
	char il2[50];
	strcpy(il, "znaleziono slow:");
	il[12]=40;
	il[13]=35;
	//il[17]=48;
	pisztext2(poz_x, poz_y, il, makecol(180,210,250));
	il2[0]=48+(znal_w)/10000;
	il2[1]=48+((znal_w-(10000*(il2[0]-48)))/1000);
	il2[2]=48+((znal_w-(10000*(il2[0]-48))-(1000*(il2[1]-48)))/100);
	il2[3]=48+((znal_w-(10000*(il2[0]-48))-(1000*(il2[1]-48))-(100*(il2[2]-48)))/10);
	il2[4]=48+(znal_w-(10000*(il2[0]-48))-(1000*(il2[1]-48))-(100*(il2[2]-48))-(10*(il2[3]-48)));
//
	pisztext(poz_x+20, poz_y+26, il2, makecol(180,255,180));

}

void wyswietl( void ) {
	char il[23];
	int miesci=0;
	int temp1 = 0;
	int temp2 = 1;
	int temp3 = 0;
	int nr_l = 0;
	miesci=(740/(il_liter*18));
	if(hasla_w[(temp1+(temp3*miesci))*(il_liter+1)+(il_liter+1)*miesci*(strona+1)+temp2]==0) {
		strona--;
	}
	if(strona<0)
		strona=0;

	for(temp3=0; temp3<14; temp3++) {
		for(temp2=1; temp2<=23;temp2++) {
			il[temp2-1]=0;
		}
		if(hasla_w[((temp3*miesci))*(il_liter+1)+(il_liter+1)*miesci*(strona)+1]!=0)
		{
//			nr_l=temp3+strona+1+(miesci-1+strona)*temp3;
			nr_l=((temp3+strona)*miesci)+1;
			il[0]=48+(nr_l)/1000;
			il[1]=48+(nr_l-(1000*(il[0]-48)))/100;
			il[2]=48+((nr_l-(1000*(il[0]-48))-(100*(il[1]-48)))/10);
			il[3]=48+(nr_l-(1000*(il[0]-48))-(100*(il[1]-48))-(10*(il[2]-48)));
			pisztext2(8, 140+temp3*28, il, makecol(100,200,255));
		}
		for(temp1=0; temp1<miesci; temp1++)
		{
			for(temp2=1; temp2<=23;temp2++) {
				il[temp2-1]=0;
			}
			for(temp2=1; temp2<=il_liter;temp2++) {
				il[temp2-1]=hasla_w[(temp1+(temp3*miesci))*(il_liter+1)+(il_liter+1)*miesci*(strona)+temp2];
			}
			pisztext2(54+(18*temp1*il_liter)+8, 140+temp3*28, il, makecol(240,240,240));
			if( (il[0]!=0) && (temp3==13) && (temp1==(miesci-1)) ) {
				strcpy(il, "wiecej");
				il[2]=34;
				pisztext2(696, 549, il, makecol(240,50,20));
			}
		}
	}
	if( (strona>0) ) {
		strcpy(il, "wzwyz");
		il[4]=43;
		pisztext2(596, 549, il, makecol(50,240,20));
	}


}


void wyswietl_haslo(int poz_x, int poz_y)
{
	char il[5];
	int nr_kratki;
	for(nr_kratki=0; nr_kratki<23; nr_kratki++) {
		if(nr_kratki<il_liter) {
			il[0]=haslo[nr_kratki];
			if(haslo[nr_kratki]==0) {
				pisztext(poz_x+nr_kratki*34, poz_y, " ", makecol(240,240,240));
			}
			else {
				pisztext(poz_x+nr_kratki*34, poz_y, il, makecol(240,240,240));
			}
		}
		if( (edit==2) && (pozycja==nr_kratki) ) {
			pisztext(poz_x+nr_kratki*34, poz_y, "_", makecol(240,120,60));
		}
	}
}

void wyswietl_ilosc(int poz_x, int poz_y)
{
	char il[5];
	if(edit==1) {
		if(il_liter_temp!=100) {
			if(il_liter_temp<10) {
				itoa(il_liter_temp, il, 15);
				pisztext(poz_x, poz_y, il, makecol(240,240,240));
				pisztext(poz_x+34, poz_y, "_", makecol(240,120,60));
			}
			else {
				if(il_liter_temp<20) {
					itoa(il_liter_temp/10, il, 15);
					pisztext(poz_x, poz_y, il, makecol(240,240,240));
					itoa(il_liter_temp-10, il, 15);
					pisztext(poz_x+34, poz_y, il, makecol(240,240,240));
					pisztext(poz_x+34*2, poz_y, "_", makecol(240,120,60));
				}
				else {
					itoa(il_liter_temp/10, il, 15);
					pisztext(poz_x, poz_y, il, makecol(240,240,240));
					itoa(il_liter_temp-20, il, 15);
					pisztext(poz_x+34, poz_y, il, makecol(240,240,240));
					pisztext(poz_x+34*2, poz_y, "_", makecol(240,120,60));
				}
			}
		}
		else {
			pisztext(poz_x, poz_y, "_", makecol(240,240,240));
		}
	}
	else {
		if(il_liter<10) {
			itoa(il_liter, il, 15);
			pisztext(poz_x, poz_y, "0", makecol(240,240,240));
			pisztext(poz_x+34, poz_y, il, makecol(240,240,240));
		}
		else {
			if(il_liter<20) {
				itoa(il_liter/10, il, 15);
				pisztext(poz_x, poz_y, il, makecol(240,240,240));
				itoa(il_liter-10, il, 15);
				pisztext(poz_x+34, poz_y, il, makecol(240,240,240));
			}
			else {
				itoa(il_liter/10, il, 15);
				pisztext(poz_x, poz_y, il, makecol(240,240,240));
				itoa(il_liter-20, il, 15);
				pisztext(poz_x+34, poz_y, il, makecol(240,240,240));
			}
		}
	}
}


void odswiez()
{
//	char tekst[255];
	int ciemny = makecol(96,120,255);
	int jasny = makecol(210,230,255);
	int posredni = makecol(128,160,255);
	int nr_kratki;

	scare_mouse();
	//rectfill(screen,0,0,400,30,15);
	text_mode(-1);
	clear_bitmap(bufor_ekranu); //wyczysc bufor ekranu
	blit(rysunek,bufor_ekranu,0,0,0,0,rysunek->w,rysunek->h);

	if(anagram==0) {
		przycisk(9+34*5,31); //179-343   y 127-168
		przycisk2(9+34*10,31); //349-513   y 127-168
	}
	else {
		przycisk2(9+34*5,31); //179-343   y 127-168
		przycisk(9+34*10,31); //349-513   y 127-168
	}
	pisztext2(24+34*5, 31+8, "uzupe(nianie", makecol(240,240,240));
	pisztext2(13+34*10, 31+8, "anagramowanie", makecol(240,240,240));



	kratka(9+34*2,31); //77-142   y 127-168
	kratka(9+34*3,31);


	for(nr_kratki=0; nr_kratki<23; nr_kratki++) {
		if(nr_kratki<il_liter) {
			kratka(9+(nr_kratki*34),95);  //x 9 - 9+(23*34)    y 200 - 241
		}
		else {
			kratka2(9+(nr_kratki*34),95);
		}
	}

	wyswietl_ilosc(9+34*2, 31);

	wyswietl_haslo(9,95);

	wyswietl();
	ilosc(570, 14);

	pisztext2(477, 550, "g.korycki", makecol(255,200,255));
	pisztext2(477, 574, "t.korycki", makecol(255,200,200));

	masked_blit(kursor,bufor_ekranu,0,0,mx,my,kursor->w,kursor->h);
	blit(bufor_ekranu,screen,0,0,0,0,800,600);
	unscare_mouse();
}


int main()
{
	allegro_init();
	install_keyboard();
	install_mouse();
	set_color_depth(16);
	int zmienna1; //tymczasowa
	int tmp9;



	FILE *plik;
	plik = fopen ("dane/Hasla-2.Lit", "r");
	fread(&hasla02,sizeof(hasla02),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-3.Lit", "r");
	fread(&hasla03,sizeof(hasla03),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-4.Lit", "r");
	fread(&hasla04,sizeof(hasla04),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-5.Lit", "r");
	fread(&hasla05,sizeof(hasla05),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-6.Lit", "r");
	fread(&hasla06,sizeof(hasla06),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-7.Lit", "r");
	fread(&hasla07,sizeof(hasla07),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-8.Lit", "r");
	fread(&hasla08,sizeof(hasla08),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-9.Lit", "r");
	fread(&hasla09,sizeof(hasla09),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-10.Lit", "r");
	fread(&hasla10,sizeof(hasla10),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-11.Lit", "r");
	fread(&hasla11,sizeof(hasla11),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-12.Lit", "r");
	fread(&hasla12,sizeof(hasla12),1,plik);
	fclose(plik);


	plik = fopen ("dane/Hasla-13.Lit", "r");
	fread(&hasla13,sizeof(hasla13),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-14.Lit", "r");
	fread(&hasla14,sizeof(hasla14),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-15.Lit", "r");
	fread(&hasla15,sizeof(hasla15),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-16.Lit", "r");
	fread(&hasla16,sizeof(hasla16),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-17.Lit", "r");
	fread(&hasla17,sizeof(hasla17),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-18.Lit", "r");
	fread(&hasla18,sizeof(hasla18),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-19.Lit", "r");
	fread(&hasla19,sizeof(hasla19),1,plik);
	fclose(plik);


	plik = fopen ("dane/Hasla-20.Lit", "r");
	fread(&hasla20,sizeof(hasla20),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-21.Lit", "r");
	fread(&hasla21,sizeof(hasla21),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-22.Lit", "r");
	fread(&hasla22,sizeof(hasla22),1,plik);
	fclose(plik);

	plik = fopen ("dane/Hasla-23.Lit", "r");
	fread(&hasla23,sizeof(hasla23),1,plik);
	fclose(plik);


	set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);
	clear_to_color(screen,makecol(0,0,0));

	bufor_ekranu = create_bitmap(800,600);
	dat = load_datafile("pom2.dat");
	dat2 = load_datafile("pom_m.dat");
	czcionka = (FONT *)dat[0].dat;
	czcionka_m = (FONT *)dat2[0].dat;

	clear_to_color(bufor_ekranu,makecol(0,0,0));

	rysunek = load_bitmap("tlo.pcx",default_palette);
	if(!rysunek)
	{
		set_gfx_mode(GFX_TEXT,0,0,0,0);
		allegro_message("Nie moge zaladowac pliku z obrazkiem !\n");
		allegro_exit();
		return 0;
	}

	kursor = load_bitmap("kursor2.bmp",default_palette);
	if(!kursor)
	{
		set_gfx_mode(GFX_TEXT,0,0,0,0);
		allegro_message("Nie moge zaladowac pliku z obrazkiem !\n");
		allegro_exit();
		return 0;
	}

	while(!key[KEY_ESC]) {
		mx = mouse_x;
		my = mouse_y;
		mb = mouse_b;
			wcisniety = 1;
		if(keypressed())
		{
			wcisniety = 0;
			k = readkey();
		}
		else {
		}


		if(edit==0) {
			if( (k==21760) && (wcisniety==0) ) { //dol
				strona++;
				wcisniety = 1;
			}
			if( (k==21504) && (wcisniety==0) ) { //gora
				strona--;
				wcisniety = 1;
			}
			if( (k==20736) && (wcisniety==0) ) { //dol pd
				strona=strona+14;
				wcisniety = 1;
			}
			if( (k==20480) && (wcisniety==0) ) { //gora pu
				strona=strona-14;
				wcisniety = 1;
			}

			if( (mx>=179) && (mx<=343) && (my>=31) && (my<=72) && (mb==1) ) { //179-343
				anagram=0;
				for(zmienna1=0; zmienna1<23;zmienna1++ ) {
					haslo[zmienna1]=0;
				}
				czysc_wynik();
			}
			if( (mx>=349) && (mx<=513) && (my>=31) && (my<=72) && (mb==1) ) { //349-513
				anagram=1;
				for(zmienna1=0; zmienna1<23;zmienna1++ ) {
					haslo[zmienna1]=0;
				}
				czysc_wynik();
			}
			//696, 549,
			if( (mx>=696) && (mx<=765) && (my>=549) && (my<=569) && (mb==1) ) { //349-513
				strona++;
			}
			if( (mx>=596) && (mx<=653) && (my>=549) && (my<=569) && (mb==1) ) { //349-513
				strona--;
			}
			if(strona<0)
				strona=0;
		}

		if(edit!=1) {
			if( (mx>=77) && (mx<=142) && (my>=31) && (my<=72) && (mb==1) ) { //77-142
				edit=1;
				il_liter_temp=100;
			}
			if( (mx>=9) && (mx<=(9+(il_liter*34))) && (my>=95) && (my<=136) && (mb==1) ) { //x 9 - 9+(23*34)    y 200 - 241
				if( (((mx-9)/34)>=0) && (((mx-9)/34)<il_liter) ) {
					edit=2;
					if(anagram==0) {
						pozycja=(mx-9)/34;
					}
					else {
						pozycja=0;
						for(zmienna1=0; zmienna1<23;zmienna1++ ) {
							haslo[zmienna1]=0;
						}
					}
				}
			}

		}
		else {
			if(edit==1) { // edytowanie pola ilosci liter
				if( ((k==23309) || (k==17165)) && (wcisniety==0) && (il_liter_temp!=100) ) { //enter
					if(il_liter_temp<2) {
						il_liter_temp=2;
					}
					il_liter = il_liter_temp;
					il_liter_temp = 100;
					wcisniety = 1;
					edit=0;
					for(zmienna1=0; zmienna1<23;zmienna1++ ) {
						haslo[zmienna1]=0;
					}
					for(tmp9=0; tmp9<(110000-50); tmp9++) { //wyczcysc wyniki
						hasla_w[tmp9]=0;
					}

				}
				if( (k==16136) && (wcisniety==0) ) { //backspace
					il_liter_temp = 100;
					wcisniety = 1;
				}
				if(il_liter_temp == 100) { //jesli nic nie ma
					if( ((k==9777) || (k==7217)) && (wcisniety==0) ) { //1
						il_liter_temp = 1;
						wcisniety = 1;
					}
					if( ((k==10034) ||(k==7474)) && (wcisniety==0) ) { //2
						il_liter_temp = 2;
						wcisniety = 1;
					}
					if( ((k==10291) ||(k==7731)) && (wcisniety==0) ) { //3
						il_liter_temp = 3;
						wcisniety = 1;
					}
					if( ((k==10548) ||(k==7988)) && (wcisniety==0) ) { //4
						il_liter_temp = 4;
						wcisniety = 1;
					}
					if( ((k==10805) ||(k==8245)) && (wcisniety==0) ) { //5
						il_liter_temp = 5;
						wcisniety = 1;
					}
					if( ((k==11062) ||(k==8502)) && (wcisniety==0) ) { //6
						il_liter_temp = 6;
						wcisniety = 1;
					}
					if( ((k==11319) ||(k==8759)) && (wcisniety==0) ) { //7
						il_liter_temp = 7;
						wcisniety = 1;
					}
					if( ((k==11576) ||(k==9016)) && (wcisniety==0) ) { //8
						il_liter_temp = 8;
						wcisniety = 1;
					}
					if( ((k==11833) ||(k==9273)) && (wcisniety==0) ) { //9
						il_liter_temp = 9;
						wcisniety = 1;
					}
					if( ((k==9520) ||(k==6960)) && (wcisniety==0) ) { //0
						il_liter_temp = 0;
						wcisniety = 1;
					}
				}
				if(il_liter_temp<3) { //jesli pierwsza liczba jest mniejsza niz 3
					if( ((k==9777) ||(k==7217)) && (wcisniety==0) ) { //1
						il_liter_temp = (il_liter_temp*10)+1;
						wcisniety = 1;
					}
					if( ((k==10034) ||(k==7474)) && (wcisniety==0) ) { //2
						il_liter_temp = (il_liter_temp*10)+2;
						wcisniety = 1;
					}
					if( ((k==10291) ||(k==7731)) && (wcisniety==0) ) { //3
						il_liter_temp = (il_liter_temp*10)+3;
						wcisniety = 1;
					}
					if(il_liter_temp<2) {
						if( ((k==10548) ||(k==7988)) && (wcisniety==0) ) { //4
							il_liter_temp = (il_liter_temp*10)+4;
							wcisniety = 1;
						}
						if( ((k==10805) ||(k==8245)) && (wcisniety==0) ) { //5
							il_liter_temp = (il_liter_temp*10)+5;
							wcisniety = 1;
						}
						if( ((k==11062) ||(k==8502)) && (wcisniety==0) ) { //6
							il_liter_temp = (il_liter_temp*10)+6;
							wcisniety = 1;
						}
						if( ((k==11319) ||(k==8759)) && (wcisniety==0) ) { //7
							il_liter_temp = (il_liter_temp*10)+7;
							wcisniety = 1;
						}
						if( ((k==11576) ||(k==9016)) && (wcisniety==0) ) { //8
							il_liter_temp = (il_liter_temp*10)+8;
							wcisniety = 1;
						}
						if( ((k==11833) ||(k==9273)) && (wcisniety==0) ) { //9
							il_liter_temp = (il_liter_temp*10)+9;
							wcisniety = 1;
						}
					}
					if( ((k==9520) ||(k==6960)) && (wcisniety==0) ) { //0
						il_liter_temp = (il_liter_temp*10);
						wcisniety = 1;
					}
				}
				if(mb==2) {
					edit=0;
					il_liter_temp=0;
				}
			}
		}
		if(edit==2) {
			if( (k==353) && (wcisniety==0) ) { //a
				haslo[pozycja]=97;
				wcisniety = 1;
				pozycja++;
			}

			if( (k==610) && (wcisniety==0) ) { //b
				haslo[pozycja]=98;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==867) && (wcisniety==0) ) { //c
				haslo[pozycja]=99;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==1124) && (wcisniety==0) ) { //d
				haslo[pozycja]=100;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==1381) && (wcisniety==0) ) { //e
				haslo[pozycja]=101;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==1638) && (wcisniety==0) ) { //f
				haslo[pozycja]=102;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==1895) && (wcisniety==0) ) { //g
				haslo[pozycja]=103;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==2152) && (wcisniety==0) ) { //h
				haslo[pozycja]=104;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==2409) && (wcisniety==0) ) { //i
				haslo[pozycja]=105;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==2666) && (wcisniety==0) ) { //j
				haslo[pozycja]=106;
				pozycja++;
				wcisniety = 1;
			}
			if( (k==2923) && (wcisniety==0) ) { //k
				haslo[pozycja]=107;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==3180) && (wcisniety==0) ) { //l
				haslo[pozycja]=108;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==3437) && (wcisniety==0) ) { //m
				haslo[pozycja]=109;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==3694) && (wcisniety==0) ) { //n
				haslo[pozycja]=110;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==3951) && (wcisniety==0) ) { //o
				haslo[pozycja]=111;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==4208) && (wcisniety==0) ) { //p
				haslo[pozycja]=112;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==4465) && (wcisniety==0) ) { //q
				haslo[pozycja]=113;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==4722) && (wcisniety==0) ) { //r
				haslo[pozycja]=114;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==4979) && (wcisniety==0) ) { //s
				haslo[pozycja]=115;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==5236) && (wcisniety==0) ) { //t
				haslo[pozycja]=116;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==5493) && (wcisniety==0) ) { //u
				haslo[pozycja]=117;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==5750) && (wcisniety==0) ) { //v
				haslo[pozycja]=118;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==6007) && (wcisniety==0) ) { //w
				haslo[pozycja]=119;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==6264) && (wcisniety==0) ) { //x
				haslo[pozycja]=120;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==6521) && (wcisniety==0) ) { //y
				haslo[pozycja]=121;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==6778) && (wcisniety==0) ) { //z
				haslo[pozycja]=122;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==350) && (wcisniety==0) ) { //�
				haslo[pozycja]=33;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==1374) && (wcisniety==0) ) { //�
				haslo[pozycja]=34;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==4083) && (wcisniety==0) ) { //�
				haslo[pozycja]=35;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==4958) && (wcisniety==0) ) { //�
				haslo[pozycja]=36;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==6750) && (wcisniety==0) ) { //�
				haslo[pozycja]=43;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==6238) && (wcisniety==0) ) { //�
				haslo[pozycja]=38;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==862) && (wcisniety==0) ) { //�
				haslo[pozycja]=39;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==3166) && (wcisniety==0) ) { //�
				haslo[pozycja]=40;
				wcisniety = 1;
				pozycja++;
			}
			if( (k==3678) && (wcisniety==0) ) { //�
				haslo[pozycja]=41;
				wcisniety = 1;
				pozycja++;
			}





			if(anagram==0) {
				if( (k==19232) && (wcisniety==0) ) { //spacja
					haslo[pozycja]=0;
					wcisniety = 1;
					pozycja++;
				}
				if( (k==20992) && (wcisniety==0) ) { //<-
					pozycja--;
					wcisniety = 1;
				}
				if( (k==21248) && (wcisniety==0) ) { //->
					pozycja++;
					wcisniety = 1;
				}
				if( (k==19712) && (wcisniety==0) ) { //del
					haslo[pozycja]=0;
					wcisniety = 1;
				}
			}
			else {
				if( (k==20992) && (wcisniety==0) ) { //<-
					pozycja--;
					wcisniety = 1;
				}
				if( (k==21248) && (wcisniety==0) ) { //->
					if(haslo[pozycja]!=0) {
						pozycja++;
					}
					wcisniety = 1;
				}
			}

			if( (k==16136) && (wcisniety==0) ) { //bckspc
				if(pozycja!=0) {
					haslo[pozycja-1]=0;
					pozycja--;
					wcisniety = 1;
				}
			} 

			if( ((k==23309) || (k==17165)) && (wcisniety==0) ) { //enter
				pozycja=0;
				wcisniety = 1;
				edit=0;
				wynik();
			}

			if(pozycja>=il_liter) {
				pozycja=il_liter-1;
			}
			if(mb==2) {
				edit=0;
				wynik();
			}
			if(pozycja>=il_liter) {
				pozycja=0;
				edit=0;
				wynik();
			}

		}
		odswiez();
	}
	destroy_bitmap(kursor);
	destroy_bitmap(rysunek);
	destroy_bitmap(bufor_ekranu);
	unload_datafile(dat);
	scare_mouse();
	allegro_exit();
	return 0;
}
END_OF_MAIN()
