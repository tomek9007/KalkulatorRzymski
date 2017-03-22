// zadTestoweSTOSKalkulatorRzymski.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"

char T[1000];
char* t = T;

void zerujTablice()
{
	do
	{
		*t = 0;
		t--;

	} while (t != &T[0]);
}

void przewinTablice()
{
	while (t != &T[0])
	{
		t--;
	}
}

void wypiszTablice()
{
	while (*t!='\0')
	{

		printf("%c", *t);
		t++;

	}
}

void wypisywanie(int &arabska, int liczba, char literka)
{
	while (arabska>=liczba)
	{
		*t = literka;
		t++;
		arabska = arabska - liczba;
	}

}

void wypisywanie2(int &arabska, int liczba, char literka, char literka2)
{
	while (arabska >= liczba)
	{
		*t = literka;
		t++;
		*t = literka2;
		t++;
		arabska = arabska - liczba;
	}
}

char *wypisywanieArabskiej1(int &arabska, int liczba, char literka, char *t)
{
	while (*t == literka)
	{
		arabska += liczba;
		t++;
	}
	
	return t;
}

char *wypisywanieArabskiej2(int &arabska, int liczba, char literka1, char literka2, char *t)
{
	while (*t == literka1)
	{
		t++;
		if (*t == literka2)
		{
			arabska += liczba;
			t++;
		}
		else
		{
			t--;
			break;
		}
		
	}
	return t;
}

void arabskaNaRzymska(int arabska, bool zeruj)
{

	wypisywanie(arabska, 1000, 'M');
	wypisywanie2(arabska, 900, 'C', 'M');
	wypisywanie(arabska, 500, 'D');
	wypisywanie2(arabska, 400, 'C', 'D');
	wypisywanie(arabska, 100, 'C');
	wypisywanie2(arabska, 90, 'X', 'C');
	wypisywanie(arabska, 50, 'L');
	wypisywanie2(arabska, 40, 'X', 'L');
	wypisywanie(arabska, 10, 'X');
	wypisywanie2(arabska, 9, 'I', 'X');
	wypisywanie(arabska, 5, 'V');
	wypisywanie2(arabska, 4, 'I', 'V');
	wypisywanie(arabska, 1, 'I');


////////////////////////////////////////////

	przewinTablice();

	wypiszTablice();
	if (zeruj)
	zerujTablice();

}

int rzymskaNaArabska(char* t)
{
	int arabska=0;


	t=wypisywanieArabskiej1(arabska, 1000, 'M', t);
	
	t = wypisywanieArabskiej2(arabska, 900, 'C', 'M', t);

	t = wypisywanieArabskiej1(arabska, 500, 'D', t);

	t = wypisywanieArabskiej2(arabska, 400, 'C', 'D', t);

	t = wypisywanieArabskiej1(arabska, 100, 'C', t);

	t = wypisywanieArabskiej2(arabska, 90, 'X', 'C', t);

	t = wypisywanieArabskiej1(arabska, 50, 'L', t);

	t = wypisywanieArabskiej2(arabska, 40, 'X', 'L', t);
	
	t = wypisywanieArabskiej1(arabska, 10, 'X', t);
	
	t = wypisywanieArabskiej2(arabska, 9, 'I', 'X', t);
	
	t = wypisywanieArabskiej1(arabska, 5, 'V', t);

	t = wypisywanieArabskiej2(arabska, 4, 'I', 'V', t);

	t = wypisywanieArabskiej1(arabska, 1, 'I', t);

	//printf("%d", arabska);
	return arabska;
}

int mnozenieArabskich(int arabska1, int arabska2)
{
	return arabska1*arabska2;
}

int dodawanieArabskich(int arabska1, int arabska2)
{
	return arabska1+arabska2;
}

int dzielenieArabskich(int arabska1, int arabska2)
{
	if ((arabska1 % arabska2) == 0)
	{
		return arabska1 / arabska2;
	}
	else{
		int calkowita = arabska1 / arabska2;
		arabskaNaRzymska(calkowita, true);
		char spacja = ' ';
		printf("%c", spacja);

		return  arabska1%arabska2;


	}
}

int odejmowanieArabskich(int arabska1, int arabska2)
{
	return arabska1-arabska2;
}

int dzialanie(char znak, int arabska1, int arabska2)
{
	int wynik;
	switch (znak)
	{
	case '+':
	{
			wynik=dodawanieArabskich(arabska1, arabska2);
				break;
	}
	case '-':
	{
				wynik = odejmowanieArabskich(arabska1, arabska2);
				break;
	}
	case '*':
	{
				wynik = mnozenieArabskich(arabska1, arabska2);
				break;
	}
	case '/':
	{
				wynik = dzielenieArabskich(arabska1, arabska2);
				break;
	}
	default:
		break;
	}

	return wynik;
}

int _tmain(int argc, _TCHAR* argv[])
{

	char T1[10000];
	char *t1 = T1;
	char T2[10000];
	char *t2 = T2;
	char T3[10000];
	char *t3 = T3;

	
	for (;;)
	{


		fgets(T1, sizeof T1, stdin);
		
		if (*t1=='\n')
			return 0;
		
		char x = *t1;

		t1 += 2;

		while (*t1 != ' ')
		{
			*t2 = *t1;
			t1++;
			t2++;
		}

		t1++;

		while (*t1 != '\n')
		{
			*t3 = *t1;
			t1++;
			t3++;
		}

		int wynikArabska = dzialanie(x, rzymskaNaArabska(T2), rzymskaNaArabska(T3));
		//printf("%d", wynikArabska);
		//char spacja = '\n';
		arabskaNaRzymska(wynikArabska, false);
		printf("%c", '\n');
		//printf("%c", spacja);
		//printf("%d", rzymskaNaArabska(T3));

		//arabskaNaRzymska(2003);
		//rzymskaNaArabska();


		do
		{
			*t1 = 0;
			t1--;

		} while (t1 != &T1[0]);

		do
		{
			*t2 = 0;
			t2--;

		} while (t2 != &T2[0]);

/*		do
		{
			*t3 = 0;
			t3--;

		}*/ while (t3 != &T3[0])
		{
			*t3 = 0;
			t3--;

		}


		zerujTablice();
	}
	return 0;
}



