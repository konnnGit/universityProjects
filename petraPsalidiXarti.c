/*Ασκηση προετοιμασίας

Πέτρα-ψαλίδι-χαρτί Σας ζητούν να φτιάξετε το παιγνίδι πέτρα-ψαλίδι-χαρτί στον υπολογιστή. 
* Φτιάξτε ένα πρόγραμμα το οποίο θα εμφανίζει τις 3 επιλογές στο χρήστη (και 0 για έξοδο), 
* θα διαβάζει την επιλογή του χρήστη, θα επιλέγει τυχαία ένα αντικείμενο (δείτε τη συνάρτηση random) και 
* θα τυπώνει το αποτέλεσμα. Αν δεν θυμάστε: η πέτρα κερδίζει το ψαλίδι το ψαλίδι κερδίζει το χαρτί το χαρτί κερδίζει την πέτρα 
* Το πρόγραμμα θα συνεχίζει μέχρι ο χρήστης να επιλέξει "0. Έξοδο".*/


#include <stdio.h>
#include <stdlib.h>

int petra_psalidi_xarti (int );

int main (void){
	int choise=4;
	while (choise!=0){
	printf("Πέτρα=1\n");
	printf("Ψαλίδι=2\n");
	printf("Χαρτί=3\n");
	printf("Έξοδος=0\n\n");	
	printf("Δώστε επιλογή :");
	scanf("%d",&choise);
	petra_psalidi_xarti(choise);
}
    return 0;
}

int petra_psalidi_xarti(int c){
	int value;
	value=rand() % 3+1;
	if (value<c){
		printf("Αποτέλεσμα υπολογιστή %d :",value ); 
		printf("Νίκησες\n") ;
		}
	else if (value==c) {
		printf("Αποτέλεσμα υπολογιστή %d :",value ); 
		printf("Ισοπαλία\n") ;
		}
	else if (value==1&&c==2){
		printf("Αποτέλεσμα υπολογιστή %d :",value ); 
		printf("Νίκησες\n");
		} else {
			printf("Αποτέλεσμα υπολογιστή %d :",value ); 
			printf("Έχασες\n ");
			}
	return 0;
}
