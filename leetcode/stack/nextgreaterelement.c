/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *resposta = (int *)malloc(sizeof(int) * nums1Size);
    
    for (int i = 0; i < nums1Size; i++) {
        resposta[i] = -1;
    }

    for (int i = 0; i < nums1Size; i++) {
        int j = 0;
        while (j < nums2Size && nums2[j] != nums1[i]) {
            j++;
        }
        
        for (int k = j + 1; k < nums2Size; k++) {
            if (nums2[k] > nums1[i]) {
                resposta[i] = nums2[k];
                break;
            }
        }
    }

    *returnSize = nums1Size;
    return resposta;
}