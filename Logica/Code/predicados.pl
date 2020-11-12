cao(fido). 
cao(rover). 
cao(jane).
cao(tom).
cao(fred). 
cao(henry).

grande(tom).
grande(fido).
grande(mary).
grande(fred).
grande(jim).
grande(mike).

gato(mary). 
gato(harry).
gato(bill).
gato(steve).

pequeno(henry). /*Henry é pequeno mas não é gato*/
pequeno(bill).
pequeno(steve).

animal_grande(X):- cao(X),grande(X).
animal_pequeno(Z):- gato(Z),pequeno(Z). /*para ser animal_pequeno precisa ser gato*/