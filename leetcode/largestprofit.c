int maxProfit(int* prices, int pricesSize) {
    int menorp = prices[0]; //maior valor
    int maiorl = 0;
    //percorre todo o array
    for ( int i = 0; i < pricesSize; i++ ){
      //atualiza o menor preco se achar um menor
        if ( prices[i] < menorp ){
            menorp = prices[i];
        }
        //se o preco for maior q o menor preco, e o lucro calculado dele for maior q o atual
        //calcula o lucro atual
        if ( prices[i] > menorp && maiorl < prices[i] - menorp){
            maiorl = prices[i] - menorp;
        }
    }
    return maiorl;
}