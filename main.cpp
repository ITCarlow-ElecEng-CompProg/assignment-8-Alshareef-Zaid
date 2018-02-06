/** Zaid H Alshareef
*  Lab 8
*  Operational Amplifier Circuits
*  28/1/2018

/** Preprocessor directives */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h>
#include <math.h>


using namespace std;


char displayMenu(void);
void invert (void);
void noninvert (void);

//* pointer functions */
void inverting(double *AvPtr, double Rf, double Rin, double *VoutPtr, double Vin);
void noninverting(double *AvPtr, double R2, double R1, double *VoutPtr, double Vin);


/** Main function */
int main(void)
{
/** declare variables */
char choice;
/** do while loop to get the user to select which operation they want to use */
do
{
choice = displayMenu();

/** switch case  */
    switch (choice)
{
            case 'a':       invert ();
                            break;

            case 'b':       noninvert ();
                            break;

            case 'q':       system("cls");
                            cout <<"Goodbye...\n";
                            break;

            default:	    cout <<"\nInvalid input, press any key to continue..." ;
                            fflush(stdin);
                            getchar();
                            break;
}
}
while (choice != 'q' );

return 0;
}


/** function header */
char displayMenu(void)
{
    /** declaring variable type char */
    char choice;
    /** turns previous screen off */
    system("cls");
    /** user enters which command they want to use */
    cout <<"Operational Amplifier Circuits" ;
    cout <<"\n\nPress 'a' for an inverting amplifier ...";
    cout <<"\nPress 'b' for a non-inverting amplifier ...";
    cout <<"\nPress 'q' to quit ...\n\nChoice: ";
    /** gets rid of bugs */

    fflush(stdin);
    choice = getchar();

return choice;
}


void invert()
{
/** turns previous screen off */
system("cls");

double Vcc = -1, Vee = 1, Vin, Rin = 0, Rf = 0, Av, Vout;
double *AvPtr = &Av, *VoutPtr = &Vout;

/** heading */
cout << "Inverting Amplifier Circuit\n\n" ;

/** Ensuring positive values for rin in a while loop */
while (Rin <= 0)
{
cout << "\nRin :\t";
cin >> Rin;
}
/** Ensuring positive values for rf in a while loop */
while (Rf <= 0)
{
cout << "\nRf :\t";
cin >> Rf;
}
/** Ensuring positive values for vcc in a while loop */
while (Vcc <= 0)
{
cout << "\nVcc :\t";
cin >> Vcc;
}
/** Ensuring negative values for vee in a while loop */
while (Vee >= 0)
{
cout << "\nVee :\t";
cin >> Vee;
}
/** Reading in values for vin */
cout << "\nVin :\t";
cin >> Vin;

/** calling sub function inverting */
inverting (AvPtr, Rf, Rin, VoutPtr, Vin);
/** displaying values for gain and vout */
cout << "\nAv =\t" << Av << "\n\nVout =\t" << Vout;

/** if vout is outside of vcc or vcc, display correct vcc or vee value */
if( Vout >= Vee || Vout <= Vcc )
{
if( Vin <= 0 )
{
cout << "\n\nAmplifier is in saturation \n\nVout =\t " << Vcc ;
}
else
{
cout << "\n\nAmplifier is in saturation \n\nVout =\t " << Vee ;
}
}
/** displayed on main console instructions for user to get back to main screen */
cout << "\n\nPress enter to return to the main menu..." ;
fflush(stdin);
getchar();
/** returns something back to main function */
return ;
}


/** Sub function to calculate gain and vout */
void inverting(double *AvPtr, double Rf, double Rin, double *VoutPtr, double Vin)
{
*AvPtr = -(Rf/Rin);

*VoutPtr = *AvPtr * Vin;
/** returning no value but have assigned a value in each pointers address */
return ;
}


/** sub function for non inverting amplifier */
void noninvert ()
{
/** turns previous screen off */
system("cls");
/** declare variables */
double Vcc = -1, Vee = 1, Vin, R1 = 0, R2 = 0, Av, Vout;
double *AvPtr = &Av, *VoutPtr = &Vout;

/** display heading */
cout << "Non - Inverting Amplifier Circuit\n\n" ;

/** Ensuring positive values for r1 in a while loop */
while (R1 <= 0)
{
cout << "\nR1 :\t";
cin >> R1;
}
/** Ensuring positive values for r2 in a while loop */
while (R2 <= 0)
{
cout << "\nR2 :\t";
cin >> R2;
}
/** Ensuring positive values for Vcc in a while loop */
while (Vcc <= 0)
{
cout << "\nVcc :\t";
cin >> Vcc;
}
/** Ensuring neg values for Vee in a while loop */
while (Vee >= 0)
{
cout << "\nVee :\t";
cin >> Vee;
}
/** read oin values for vin */
cout << "\nVin :\t";
cin >> Vin;

/** calling subfunction */
noninverting (AvPtr, R2, R1, VoutPtr, Vin);

/** displaying values for gain and vout */
cout << "\nAv =\t" << Av << "\n\nVout =\t" << Vout ;

/** if vout is outside of vcc or vcc, display correct vcc or vee value */
if(Vout <= Vee || Vout >= Vcc)
{
if(Vin >= 0)
{
cout << "\n\nAmplifier is in saturation \n\nVout =\t " << Vcc ;
}
else
{
cout << "\n\nAmplifier is in saturation \n\nVout =\t " << Vee ;
}
}

/** displayed on main console instructions for user to get back to main screen */
cout << "\n\nPress enter to return to the main menu..." ;
fflush(stdin);
getchar();
/** returns something back to main function */
return ;
}


/** sub function to calculate gain and vout for non inverting amplifier */
void noninverting(double *AvPtr, double R2, double R1, double *VoutPtr, double Vin)
{
*AvPtr = 1 + (R2 / R1);

*VoutPtr = *AvPtr * Vin;
/** returning no value but have assigned a value in each pointers address */
return ;
}
