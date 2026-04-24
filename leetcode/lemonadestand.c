
bool lemonadeChange(int* bills, int billsSize) {
    int notas5 = 0; //vejo quantas notas de cinco eu tenho
    int notas10 = 0; //notas de dez
    
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            notas5++; // se a nota for de cinco, incremento o cinco
        } 
        else if (bills[i] == 10) {
            if (notas5 > 0) {
                notas5--; //dou cinco de troco e icnremento o dez
                notas10++;
            } else {
                return false; // se n tiver ja retorno falso
            }
        } 
        else if (bills[i] == 20) {
            if (notas10 > 0 && notas5 > 0) {
                notas10--; //vejo se tenho notas de 5 e de 10 p troco
                notas5--;
            } 
            else if (notas5 >= 3) {
                notas5 -= 3; // se tiver 3 de 5 tb da
            } 
            else {
                return false;
            }
        }
    }
    
    return true; 
}