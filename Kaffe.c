#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

/*

Funktionen: 1. An dem 16 zeiligen Display werden Warnungen angezeigt, 
               wenn der Wassertank leer ist, wenn man den Kaffeesatz leeren muss usw. 
            2. Die Kaffeemaschine wird beim Einschalten und Ausschalten gespült.
            3. Nach 15 Tassen muss Wasser nachgefüllt werden.
            4. Kaffeebohnen müssen nach 50 Tassen nachgefüllt werden.
            5. Die Kaffeemaschine wird gereinigt, wenn die Servicetaste gedrückt wird.
            6. Nach 30 Kaffeetassen muss die Maschine gereinigt werden, 
               dies erfolgt, sobald die Servicetaste gedrückt wird
            7. Nach 100 Kaffeetasten muss die Maschine mittels Servicetasten druck, entkalkt werden.
            8. Die Maschine informiert bei jeder Funktion, was sie zu diesem Zeitpunkt macht. 

            es werdebn 100 tassen zubereitet, nach 30 tassen; wir benötigen bohnen um fortsetzten zu können! Danke fürs machen es fhelen nur noch 70 tassen....
            mit for schleife nach 30 i muss die eine methode kommen nacg 40 die andere...
*/  

////////SPÜLEN//////////////

void Spulen()
{
   Sleep(1000);
   printf("Wird gespült!\n");
   Sleep(5000);
}

////////Ausschaltvorgang//////////////

void Ausschaltvorgang()
{
   printf("Ausschaltvorgang\n");
   Spulen();
}

////////Wassernachfüllen//////////////

void Wassernachfullen()
{
   bool Servicetaste = false;
   if(Servicetaste == 0)
   {
      printf("\nWasser fehlt!\n");
      Sleep(4000);
      Servicetaste = true;
   }

   if(Servicetaste == 1)
   {
      printf("Wurde nachgefüllt\n");
      Sleep(4000);
   }
   else
   {
      printf("Taste drücken!\n");
   }
   
   Ausschaltvorgang();
}

////////Reinigen//////////////

void Reinigen()
{
   bool Servicetaste = false;
   if(Servicetaste == 0)
   {
      printf("\nBitte Reinigen!\n");
      Sleep(4000);
      Servicetaste = true;
   }

   if(Servicetaste == 1)
   {
      printf("Wurde gereinigt\n");
      Sleep(4000);
   }
   else
   {
      printf("Taste drücken!\n");
   }
   
   Ausschaltvorgang();
}

////////NAchfüllen//////////////

void KaffebohnenNachfullen()
{
   bool Servicetaste = false;
   if(Servicetaste == 0)
   {
      printf("\nBohnen fehlen!\n");
      Sleep(4000);
      Servicetaste = true;
   }

   if(Servicetaste == 1)
   {
      printf("Wurde nachgefüllt\n");
      Sleep(4000);
   }
   else
   {
      printf("Taste drücken!\n");
   }
   
   Ausschaltvorgang();
}

////////Entkalken//////////////

void Entkalken()
{
   bool Servicetaste = false;
   if(Servicetaste == 0)
   {
      printf("\nEntkalken!\n");
      Sleep(4000);
      Servicetaste = true;
   }
   
   if(Servicetaste == 1)
   {
      printf("Wurde entkalt!\n");
      Sleep(3000);
   }
   else
   {
      printf("Taste drücken!\n");
   }
   
   Ausschaltvorgang();
}

int main()
{
    int x = 1;
    int Tassen;
    int counterWassernachfuellen = 0;
    int counterReinigen = 0;
    int counterKaffebohnenNachfullen = 0; 
    int counterEntkalken = 0;
    while (x = 1)
    {
       
       char Kaffe[25] = "Kaffe";
       char input[25];
       
       printf("\nTaste drücken: ");
       scanf("%s", &input);

       int result = strcmpi(Kaffe, input);

       if(result == 0)
       {
          counterWassernachfuellen++;
          counterReinigen++;
          counterKaffebohnenNachfullen++;
          counterEntkalken++;
       }

       if(counterWassernachfuellen == 15)
       {
          Wassernachfullen();
          counterWassernachfuellen = 0;
       }

       if(counterReinigen == 30)
       {
          Reinigen();
          counterReinigen = 0;
       }

       if(counterKaffebohnenNachfullen == 50)
       {
          KaffebohnenNachfullen();
          counterKaffebohnenNachfullen = 0;
       }
        
       if(counterEntkalken == 100)
       {
          Entkalken();
          counterEntkalken = 0;
       }

      if (result != 0)
       {
           break;
       }
    }

/*  TEST

    printf("%d\n", counterEntkalken);
    printf("%d\n", counterKaffebohnenNachfullen);
    printf("%d\n", counterReinigen);
    printf("%d\n", counterWassernachfuellen);
    return 0;

*/
}