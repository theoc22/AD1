//theo chatkin m1 AED1

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int *resposta = (int*)malloc(sizeof(int) * numsSize);

    //coloco tudo em -1, default
    for (int i = 0; i < numsSize; i++) {
        resposta[i] = -1;
        for (int j = 1; j < numsSize; j++) {
            int x = (i + j) % numsSize; //simulo um movimento circular
            // 2+1 % 4 = 3, 2+2 % 4 = 0, 2+3 = 1 e dou uma volta
            if (nums[x] > nums[i]) {
                resposta[i] = nums[x]; //se eu acho, atribuo a resposta e saio
                break;
            }
        }
    }

    *returnSize = numsSize;
    return resposta;
}